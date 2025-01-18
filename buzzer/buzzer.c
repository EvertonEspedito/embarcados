#include "pico/stdlib.h"

void play_tone(int buzzer_pin, int frequency, int duration_ms) {
    int delay_us = 1000000 / (2 * frequency); // Tempo entre alternâncias (em microsegundos)
    int cycles = (frequency * duration_ms) / 1000; // Número de ciclos para a duração especificada

    for (int i = 0; i < cycles; i++) {
        gpio_put(buzzer_pin, 1); // Liga o buzzer
        sleep_us(delay_us);     // Aguarda metade do período
        gpio_put(buzzer_pin, 0); // Desliga o buzzer
        sleep_us(delay_us);     // Aguarda outra metade do período
    }
}

int main() {
    const int BUZZER_PIN_A = 21; // Pino do buzzer
    const int BUZZER_PIN_B = 10; // Pino do buzzer
    const int BUTTON_PIN_A = 5; // Pino do botão
    const int BUTTON_PIN_B = 6; // Pino do botão

    gpio_init(BUZZER_PIN_A);
    gpio_set_dir(BUZZER_PIN_A, GPIO_OUT);
    gpio_put(BUZZER_PIN_A, 0); // Garante que o buzzer comece desligado

    gpio_init(BUZZER_PIN_B);
    gpio_set_dir(BUZZER_PIN_B, GPIO_OUT);
    gpio_put(BUZZER_PIN_B, 0); // Garante que o buzzer comece desligado

    gpio_init(BUTTON_PIN_A);
    gpio_set_dir(BUTTON_PIN_A, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_A); // Habilita resistor pull-up interno no botão

    gpio_init(BUTTON_PIN_B);
    gpio_set_dir(BUTTON_PIN_B, GPIO_IN);
    gpio_pull_up(BUTTON_PIN_B); // Habilita resistor pull-up interno no botão

    while (true) {
        if (!gpio_get(BUTTON_PIN_A)) { // Botão pressionado
            play_tone(BUZZER_PIN_B, 1000, 200); // Frequência de 1000 Hz por 500 ms
        } else {
            gpio_put(BUZZER_PIN_B, 0); // Desliga o buzzer
        }

        if (!gpio_get(BUTTON_PIN_B)) { // Botão pressionado
            play_tone(BUZZER_PIN_A, 1000, 200); // Frequência de 1000 Hz por 500 ms
        } else {
            gpio_put(BUZZER_PIN_B, 0); // Desliga o buzzer
        }
    }
}