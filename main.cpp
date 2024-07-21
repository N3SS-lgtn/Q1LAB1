// Final program with suitable software solution
// Changes: Using a volatile flag to indicate the button press and managing it properly in the main loop.
// Ensuring the printf statement is outside the interrupt context for proper operation.

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
        // Short delay to avoid busy-waiting
        wait_ms(10);
    }
}