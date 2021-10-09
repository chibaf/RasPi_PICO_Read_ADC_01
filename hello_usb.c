/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

// modification of hello_usb.c

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

int main() {
    stdio_init_all();
    adc_init();

    adc_gpio_init(26);
    // Select ADC input 0 (GPIO26)
    adc_gpio_init(27);
    // Select ADC input 1 (GPIO27)

    while (true) {
      adc_select_input(0);
      uint16_t result0 = adc_read();
      adc_select_input(1);
      uint16_t result1 = adc_read();
      printf("%d, %d \n",result0,result1);
      sleep_ms(1000);
    }
    return 0;
}
