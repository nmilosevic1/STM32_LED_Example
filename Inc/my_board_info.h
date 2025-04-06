/* my_board_info header
 *
 * Define all your board specific stuff here
 *
 * Check your board's user guide to determine your LED pin(s)/port(s) and alter below definitions accordingly
 * Download the nucleo user guide for your board from st.com
 * e.g.  My board is this one: https://www.st.com/en/evaluation-tools/nucleo-f767zi.html  (stm32f767)
 *   Search on st.com for your board,
 *         Click on the Documentation tab, then scroll down to "User Manuals" and download  (e.g. UM1974 STM32 Nucleo-144 boards (MB1137))
 *         Once downloaded, open the document and verify your board is listed in the introduction section
 *   This document defines the user LEDs for the board, you need to change the defines below to match your board definitions.
 * e.g. section 6.5 LEDs
 *              User LD1: a green user LED is connected to the STM32 I/O PB0 (SB120 ON and SB119 OFF)
 *                                                                    or PA5 (SB119 ON and SB120 OFF) corresponding to the ST Zio D13.
 *              User LD2: a blue user LED is connected to PB7.
 *              User LD3: a red user LED is connected to PB14.
 * Check the bottom of your board to find if SB120 and SB119 are ON and OFF (if ON, you see a black square with a white ZERO)
 * My board has the zero on SB120 and not on SB119, hence my green LED is PB0 (port B, pin 0)
 * So all 3 of the LEDs on my board are connected to port B (PB0, PB7, and PB14).
 *
 * Check your board's datasheet to determine which bus the GPIO ports are connected to
 * e.g  search online for "datasheet stm32f767"
 * My search results include:
 * https://www.st.com/resource/en/datasheet/stm32f765bi.pdf
 * when I download and open I see my board is listed at the very top of the document.
 * Scroll down to the "block diagram" and find the GPIO ports for your board and check which bus they are connected to
 * My GPIO port B is connected to AHB1 bus so we need to use the AHB1 enable register to enable the clock for GPIOB
 *
 * Check your board's reference manual to determine which bit to set for the bus your GPIO ports are connected to
 * e.g. search online for "reference manual stm32f767"
 * My search results include:
 * https://www.st.com/resource/en/reference_manual/dm00224583-stm32f76xxx-and-stm32f77xxx-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf
 * download and open and ensure your board is listed at the top of the document.
 * Then search for AHB1ENR (or whichever bus your GPIO ports are connected to)
 *     check the register definition for the bits you will need to set to enable clock for your port(s)
 * My LEDs are all on 1 port (GPIOB) which is bit 1.
 *   if your GPIOxEN bits do not start at 0 in the bus enable register, edit GPIOAEN_BIT below to account for that.
 */

#ifndef MY_BOARD_INFO_H_
#define MY_BOARD_INFO_H_

#include "stm32f7xx.h"       // board specific headers - replace with headers for your board
#include "stm32f767xx.h"

// stm32f767 has 3 user LEDs, all are connected to port B
#define NUM_LEDS          3   // update to the number of user LEDs on your board

#define LED1              (1U << 0)  // pin0  GREEN   // update to the pins for your user LEDs
#define LED2              (1U << 7)  // pin7  BLUE
#define LED3              (1U << 14) // pin14 RED

#define LED1_PORT         GPIOB            // update to the ports for your LEDs
#define LED2_PORT         GPIOB
#define LED3_PORT         GPIOB

// If your GPIO ports are connected to a different bus, you only
// need to change the "AHB1ENR" below to the name of your bus's enable register
#define GPIO_BUS          (*(volatile uint32_t *)(&(RCC->AHB1ENR)))
#define GPIOAEN_BIT       0 // GPIOAEN bit in my RCC->AHB1ENR

#endif /* MY_BOARD_INFO_H_ */
