/* gpio header file */
#ifndef __GPIO_H_
#define __GPIO_H_

#include "my_board_info.h"

#include <stdint.h>
#include <stdbool.h>

#define ON  true
#define OFF false

void gpio_leds_init();
void gpio_all_leds(bool on);
void gpio_one_led(GPIO_TypeDef *GPIOx, uint32_t pin, bool on);
void gpio_toggle_all_leds();
void gpio_toggle_one_led(GPIO_TypeDef *GPIOx, uint32_t pin);

// I/O mode values (GPIOx_MODER)
enum {
  INPUT = 0x0, // 0b 00
  OUTPUT,      // 0b 01
  ALTERNATE,   // 0b 10
  ANALOG       // 0b 11
};

struct LedDef {
  GPIO_TypeDef *GPIOx;
  uint32_t pin;
};

extern struct LedDef myLeds[NUM_LEDS];

#endif// __GPIO_H_
