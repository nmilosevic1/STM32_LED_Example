/* main.c
 * Simple LED example for STM32
 *
 * See README for initial setup
 * Update my_board_info.h to meet the specification for your board (if not stm32f767)
 * Alter the definition of myLeds (only if your board has fewer than 3 user LEDs)
 */

#include <stdint.h>
#include "my_board_info.h"
#include "gpio.h"

struct LedDef myLeds[NUM_LEDS] = {
    {LED1_PORT, LED1}, // update for your board's LED(s) if you don't have 3
    {LED2_PORT, LED2},
    {LED3_PORT, LED3}
};

#define FAKE_CLOCK 0x100fff // facilitate wasting a little time so we can actually see the lights changing

int main(void) {
  gpio_leds_init();     // initialize the LEDs
  gpio_all_leds(ON);    // start with all LEDs lit

  uint32_t slow=0;
  while (1) {  // loop forever
    for (slow=0; slow<FAKE_CLOCK; ++slow);
    gpio_all_leds(OFF); // turn off all LEDs

    // turn on each light one by one until all are on
    for (uint32_t led_idx=0; led_idx<NUM_LEDS; ++led_idx) {
      for (slow=0; slow<FAKE_CLOCK; ++slow);
      gpio_toggle_one_led(myLeds[led_idx].GPIOx, myLeds[led_idx].pin);
    }
  }
}
