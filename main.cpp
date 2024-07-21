// Program with flag for button press and debugging statements
// Debugging shows that the flag set in the interrupt context is not consistently managed in the main loop.

#include "mbed.h"

// Initialize button pin as InterruptIn
InterruptIn button(BUTTON1);
volatile bool button_flag = false;

// Function to handle button press interrupt
void button_pressed() {
    button_flag = true;
}

int main() {
    // Attach the button press handler
    button.fall(&button_pressed);

    // Keep the program running
    while (1) {
        if (button_flag) {
            printf("Button pressed\n");
            button_flag = false;
        }
    }
}