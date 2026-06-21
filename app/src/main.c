#include <zephyr/kernel.h>
#include <hal/nrf_gpio.h>

#define LED_PIN 29

int main(void)
{
    nrf_gpio_cfg_output(LED_PIN);

    while (1) {
        nrf_gpio_pin_toggle(LED_PIN);
        k_msleep(500);
    }
}
