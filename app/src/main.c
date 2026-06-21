#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED_PIN 29

int main(void)
{
    const struct device *gpio0 = DEVICE_DT_GET(DT_NODELABEL(gpio0));

    if (!device_is_ready(gpio0)) {
        return 0;
    }

    gpio_pin_configure(gpio0, LED_PIN, GPIO_OUTPUT);

    while (1) {
        gpio_pin_set(gpio0, LED_PIN, 1);
        k_msleep(500);

        gpio_pin_set(gpio0, LED_PIN, 0);
        k_msleep(500);
    }
}
