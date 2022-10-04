#include "mbed.h"

// define the button to press: pressed is 0, unpressed is 1
DigitalIn button(BUTTON1);

// define the light to shown
DigitalOut myled(LED1);

// main() runs in its own thread in the OS
int main() {
    // check that myled object is initialized and connected to a pin
    if (myled.is_connected()) {
        printf("myled is initialized and connected!\n\r");
    }

    // store the value read from the button
    int temp[10];

    // store the Morse Code
    int data[19];

    // Blink LED
    while (1) {
        // count if pass the seven units
        int count = 0;
        int start = 0;

        if (button == 0) {
            start = 1;
        }

        // printf("i am outside\n");

        if (start) {
            for (int index = 0; index < 19; index++) {
                // read the data from the button
                for (int i = 0; i < 10; i++) {
                    temp[i] = button;
                    ThisThread::sleep_for(100ms);
                }

                // initial data value
                data[index] = 0;

                for (int i = 0; i < 6; i++) {
                    if (temp[i] == 0 && temp[i + 1] == 0 && temp[i + 2] == 0 &&
                        temp[i + 3] == 0 && temp[i + 4] == 0) {
                        data[index] = 1;
                        count = 0;
                        printf("reading 1\n");
                        break;
                    }

                    if (i == 5) {
                        printf("reading 0\n");
                        count++;
                    }
                }

                if (count == 7) {
                    printf(
                        "finish reading the data, time to print out the "
                        "data!\n");
                    data[index] = -1;
                    break;
                }
            }

            // show the result
            for (int i = 0; i < 19 && data[i] != -1; i++) {
                if (data[i] == 1 && data[i + 1] == 1 && data[i + 2] == 1) {
                    myled = 1;
                    ThisThread::sleep_for(1500ms);
                    myled = 0;
                    i += 2;
                    printf("3\n");
                } else {
                    myled = data[i];
                    ThisThread::sleep_for(500ms);
                    myled = 0;
                    printf("%d\n", data[i]);
                }
            }

            printf("the result is shown!\n\n\n");
            for (int i = 0; i < 19; i++) {
                printf("%d ", data[i]);
            }
            printf("\n");
        }
    }
}
