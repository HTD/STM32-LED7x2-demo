/*
 * led7.c
 * Controls LDD040AUE-101A LED 2x7 segments display.
 * Part specs: https://www.tme.eu/Document/3895106c66fc8a45b0fb841e8babf96c/LDD040AUE-101A.pdf
 */

#include "led7.h"

static const uint16_t segment_pin[] = {
	LED_A, LED_B, LED_C, LED_D, LED_E, LED_F, LED_G
};

static const uint16_t digit_segments[] = {
	LED_HEX_0, LED_HEX_1, LED_HEX_2, LED_HEX_3,
	LED_HEX_4, LED_HEX_5, LED_HEX_6, LED_HEX_7,
	LED_HEX_8, LED_HEX_9, LED_HEX_A, LED_HEX_B,
	LED_HEX_C, LED_HEX_D, LED_HEX_E, LED_HEX_F
};

void led_reset() {
	HAL_GPIO_WritePin(LED_PORT_GROUPS, LED_1, 1);
	HAL_GPIO_WritePin(LED_PORT_GROUPS, LED_2, 1);
	for (int i = 0; i < 7; i++)
		HAL_GPIO_WritePin(LED_PORT_SEGMENTS, segment_pin[i], 0);
};

void led_set_digit(uint16_t group, uint16_t digit) {
	uint16_t segments = digit_segments[digit];
	HAL_GPIO_WritePin(LED_PORT_GROUPS, LED_1, (group & 1) > 0 ? 0 : 1);
	HAL_GPIO_WritePin(LED_PORT_GROUPS, LED_2, (group & 2) > 0 ? 0 : 1);
	for (int i = 0; i < 7; i++)
		HAL_GPIO_WritePin(LED_PORT_SEGMENTS, segment_pin[i], (segment_pin[i] & segments) > 0 ? 1 : 0);
};

void led_set_digits(uint8_t msd, uint8_t lsd, uint32_t time) {
	for (uint32_t i = 0; i < time / (2 * LED_SWITCHING_TIME); i++) {
		if (msd > 0) led_set_digit(1, msd);
		HAL_Delay(LED_SWITCHING_TIME);
		led_set_digit(2, lsd);
		HAL_Delay(LED_SWITCHING_TIME);
	}
}

void led_set_dec(uint8_t number, uint32_t time) {
	led_set_digits(number / 10u, number % 10u, time);
};

void led_set_hex(uint8_t number, uint32_t time) {
	led_set_digits((number & 0xf0) >> 4, number & 0xf, time);
};
