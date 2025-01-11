#include "pico/stdlib.h"

int main() {
    // Leds
    int led_pinG = 11;
    int led_pinB = 12;
    int led_pinR = 13;

    gpio_init(led_pinR);
    gpio_set_dir(led_pinR, GPIO_OUT);

    gpio_init(led_pinG);
    gpio_set_dir(led_pinG, GPIO_OUT);

    gpio_init(led_pinB);
    gpio_set_dir(led_pinB, GPIO_OUT);

    // Funções
    void letterS(int led_pin) {
        gpio_put(led_pin, true);
        sleep_ms(200);
        gpio_put(led_pin, false);
        /*Gap*/
        sleep_ms(125);
        gpio_put(led_pin, true);
        sleep_ms(200);
        gpio_put(led_pin, false);
        /*Gap*/
        sleep_ms(125);
        gpio_put(led_pin, true);
        sleep_ms(200);
        gpio_put(led_pin, false);
        /*Gap*/
        sleep_ms(125);
    }

    void letterO(int led_pin) {
        gpio_put(led_pin, true);
        sleep_ms(800);
        gpio_put(led_pin, false);
        /*Gap*/
        sleep_ms(125);
        gpio_put(led_pin, true);
        sleep_ms(800);
        gpio_put(led_pin, false);
        /*Gap*/
        sleep_ms(125);
        gpio_put(led_pin, true);
        sleep_ms(800);
        gpio_put(led_pin, false);
        /*Gap*/
        sleep_ms(125);
    }

    void lettersInterval() {
        sleep_ms(250);
    }

    while (true) {
        // SOS => ... --- ...
        letterS(led_pinR);
        lettersInterval();

        letterO(led_pinG);
        lettersInterval();

        letterS(led_pinB);
        lettersInterval();

        /* Espera de Fim */
        sleep_ms(3000);
    }
}
