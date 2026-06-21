#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED_NODE DT_ALIAS(led0)
#define LED_LABEL DT_LABEL(LED_NODE)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED_NODE, gpios);

int main(void)
{
    int ret;

    if (!gpio_is_ready_dt(&led)) {
        printk("Error: LED device is not ready\n");
        return 0;
    }

    ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
    if (ret < 0) {
        printk("Error: Could not configure LED pin\n");
        return 0;
    }

    printk("LED blinking on %s (P0.29)\n", LED_LABEL);

    while (1) {
        gpio_pin_toggle_dt(&led);
        k_msleep(500);
    }
}
