# pico-picoemp-test-target

With this simple program, a Raspberry Pi Pico (RP2040) can be used as a test target for an EMFI (Electromagnetic Fault Injection) tool like the PicoEMP.

Initially the Raspberry Pi Pico's LED will blink slowly.
    
You can then test your EMFI tool on the RP2040, e.g. in the "pin 1" corner that's marked with a dot.

* If fault injection is successful, the LED will blink faster.
* If fault injection causes the RP20240 to hang, the LED will permanently stay on or off.

After the test, just power cycle the Pi Pico.
