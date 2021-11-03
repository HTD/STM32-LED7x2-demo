/*
 * led7.h
 * Controls LDD040AUE-101A LED 2x7 segments display.
 * Part specs: https://www.tme.eu/Document/3895106c66fc8a45b0fb841e8babf96c/LDD040AUE-101A.pdf
 */

#ifndef INC_LED7_H_
#define INC_LED7_H_

#include <gpio.h>

// ports:
#define LED_PORT_SEGMENTS GPIOB
#define LED_PORT_GROUPS GPIOB
// pins:
#define LED_A GPIO_PIN_5
#define LED_B GPIO_PIN_6
#define LED_C GPIO_PIN_7
#define LED_D GPIO_PIN_8
#define LED_E GPIO_PIN_9
#define LED_F GPIO_PIN_10
#define LED_G GPIO_PIN_11
#define LED_1 GPIO_PIN_12
#define LED_2 GPIO_PIN_13
// multiplexing:
#define LED_SWITCHING_TIME 10
// digits:
#define LED_HEX_0 LED_A | LED_B | LED_C | LED_D | LED_E | LED_F
#define LED_HEX_1 LED_B | LED_C
#define LED_HEX_2 LED_A | LED_B | LED_G | LED_E | LED_D
#define LED_HEX_3 LED_A | LED_B | LED_G | LED_C | LED_D
#define LED_HEX_4 LED_F | LED_G | LED_B | LED_C
#define LED_HEX_5 LED_A | LED_F | LED_G | LED_C | LED_D
#define LED_HEX_6 LED_A | LED_F | LED_G | LED_C | LED_D | LED_E
#define LED_HEX_7 LED_A | LED_B | LED_C
#define LED_HEX_8 LED_A | LED_B | LED_C | LED_D | LED_E | LED_F | LED_G
#define LED_HEX_9 LED_A | LED_B | LED_C | LED_D | LED_F | LED_G
#define LED_HEX_A LED_A | LED_B | LED_C | LED_E | LED_F | LED_G
#define LED_HEX_B LED_C | LED_D | LED_E | LED_F | LED_G
#define LED_HEX_C LED_A | LED_F | LED_E | LED_D
#define LED_HEX_D LED_B | LED_G | LED_E | LED_D | LED_C
#define LED_HEX_E LED_A | LED_F | LED_G | LED_E | LED_D
#define LED_HEX_F LED_A | LED_F | LED_G | LED_E
// API:
void led_reset();
void led_set_digit(uint16_t group, uint16_t digit);
void led_set_digits(uint8_t msd, uint8_t lsd, uint32_t time);
void led_set_dec(uint8_t number, uint32_t time);
void led_set_hex(uint8_t number, uint32_t time);
#endif /* INC_LED7_H_ */
