// Initial program with error message
// Error: 'printf' will not work directly inside an interrupt context due to its re-entrant nature. 
// Error handling needs to be outside the interrupt context.

#include "mbed.h"

// Initialize button pin as InterruptIn
InterruptIn button(BUTTON1);

// Function to handle button press interrupt
void button_pressed() {
    printf("Button pressed\n");
}

int main() {
    // Attach the button press handler
    button.fall(&button_pressed);

    // Keep the program running
    while (1) {
        // Do nothing, wait for interrupt
    }
}