#include "source.h"

int main() {
    stdio_init_all();

    /*
    This simple program will make the Raspberry Pi Pico's LED blink slowly.
    
    You can then test your EMFI tool on the RP2040, 
    e.g. in the "pin 1" corner that's marked with a dot.

    If fault injection is successful, the LED will blink faster.
    If fault injection causes the RP20240 to hang, the LED will 
    permanently stay on or off.

    After the test, just power cycle the Pi Pico.
    */

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    const uint long_cycle = 10000000;
    const uint short_cycle = long_cycle / 4;

    int num_cycles = long_cycle;
    int led_state = 0;

    while (true) {
        // toggle LED:
        led_state ^= 1;
        gpio_put(LED_PIN, led_state);

        // do a long loop, just incrementing counters:
        int x1 = 0, x2 = 0, x3 = 0;
        for (int i = 0; i < num_cycles; i++) {
            ++x1; ++x2; ++x3;
        }

        // check whether the counters have the correct value now:
        if (x1 != num_cycles || x2 != num_cycles || x3 != num_cycles) {
            // no, some fault happened: now blink faster:
            num_cycles = short_cycle;
        }
    }

    return 0;
}