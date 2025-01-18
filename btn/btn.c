#include "pico/stdlib.h"
#include <stdio.h>

int main()
{
    const int LED_PIN_GREEN = 11; // Pino do LED
    const int LED_PIN_RED = 13; // Pino do LED
    const int LED_BTN_A = 5;  // Pino do botão
    const int LED_BTN_B = 6;  // Pino do botão

    // Inicialização dos pinos
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);
    gpio_put(LED_PIN_GREEN, 0); // Garante que o LED comece apagado
    
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_put(LED_PIN_RED, 0); // Garante que o LED comece apagado

    gpio_init(LED_BTN_A);
    gpio_set_dir(LED_BTN_A, GPIO_IN);
    gpio_pull_up(LED_BTN_A); // Habilita o resistor pull-up interno

    gpio_init(LED_BTN_B);
    gpio_set_dir(LED_BTN_B, GPIO_IN);
    gpio_pull_up(LED_BTN_B); // Habilita o resistor pull-up interno

    while (true) {
        // Verifica o estado do botão (0 = pressionado, 1 = solto)
        if (!gpio_get(LED_BTN_A)) { // Botão pressionado
            gpio_put(LED_PIN_GREEN, 1); // Liga o LED
        } else { // Botão solto
            gpio_put(LED_PIN_GREEN, 0); // Desliga o LED
        }

        // Verifica o estado do botão (0 = pressionado, 1 = solto)
        if (!gpio_get(LED_BTN_B)) { // Botão pressionado
            gpio_put(LED_PIN_RED, 1); // Liga o LED
        } else { // Botão solto
            gpio_put(LED_PIN_RED, 0); // Desliga o LED
        }
       
    }
}
