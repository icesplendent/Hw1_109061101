#include <string.h>

#include <iostream>

#include "mbed.h"

using namespace std;

// define the button to press: pressed is 0, unpressed is 1
DigitalIn button(BUTTON1);

// define the light to shown
DigitalOut myled(LED1);

// seven segment display
BusOut display(D6, D7, D9, D10, D11, D5, D4, D8);
char model[36] = {0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71, 0x3D, 0x76, 0x30,
                  0x1E, 0x76, 0x38, 0x4F, 0x54, 0x5C, 0x73, 0x67, 0x50,
                  0x6D, 0x78, 0x3E, 0x1C, 0x4F, 0x76, 0x6E, 0x5B, 0x06,
                  0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x3F};

// main() runs in its own thread in the OS
int main() {
    char shor = '.';
    char lon = '-';

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
        string ans = "";

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

            for (int i = 0; i < 19 && data[i] != -1; i++) {
                if (data[i] * data[i + 1] * data[i + 2] == 1) {
                    ans.push_back(lon);
                    i += 2;
                    printf("3\n");
                } else if (data[i] == 1) {
                    ans.push_back(shor);
                    printf("%d\n", data[i]);
                } else if (data[i] == 0) {
                    printf("%d\n", data[i]);
                }
            }

            printf("the result is shown!\n\n\n");

            // print the ans in morse code
            for (int i = 0; i < ans.length(); i++) {
                if (ans[i] == '.') {
                    printf(".");
                } else if (ans[i] == '-') {
                    printf("-");
                }
            }
            cout << "\n";

            if (ans == ".-") {
                printf("A");
                display = model[0];
            } else if (ans == "-...") {
                printf("B");
                display = model[1];
            } else if (ans == "-.-.") {
                printf("C");
                display = model[2];
            } else if (ans == "-..") {
                printf("D");
                display = model[3];
            } else if (ans == ".") {
                printf("E");
                display = model[4];
            } else if (ans == "..-.") {
                printf("F");
                display = model[5];
            } else if (ans == "--.") {
                printf("G");
                display = model[6];
            } else if (ans == "....") {
                printf("H");
                display = model[7];
            } else if (ans == "..") {
                printf("I");
                display = model[8];
            } else if (ans == ".---") {
                printf("J");
                display = model[9];
            } else if (ans == "-.-") {
                printf("K");
                display = model[10];
            } else if (ans == ".-..") {
                printf("L");
                display = model[11];
            } else if (ans == "--") {
                printf("M");
                display = model[12];
            } else if (ans == "-.") {
                printf("N");
                display = model[13];
            } else if (ans == "---") {
                printf("O");
                display = model[14];
            } else if (ans == ".--.") {
                printf("P");
                display = model[15];
            } else if (ans == "--.-") {
                printf("Q");
                display = model[16];
            } else if (ans == ".-.") {
                printf("R");
                display = model[17];
            } else if (ans == "...") {
                printf("S");
                display = model[18];
            } else if (ans == "-") {
                printf("T");
                display = model[19];
            } else if (ans == "..-") {
                printf("U");
                display = model[20];
            } else if (ans == "...-") {
                printf("V");
                display = model[21];
            } else if (ans == ".--") {
                printf("W");
                display = model[22];
            } else if (ans == "-..-") {
                printf("X");
                display = model[23];
            } else if (ans == "-.--") {
                printf("Y");
                display = model[24];
            } else if (ans == "--..") {
                printf("Z");
                display = model[25];
            } else if (ans == ".----") {
                printf("1");
                display = model[26];
            } else if (ans == "..---") {
                printf("2");
                display = model[27];
            } else if (ans == "...--") {
                printf("3");
                display = model[28];
            } else if (ans == "....-") {
                printf("4");
                display = model[29];
            } else if (ans == ".....") {
                printf("5");
                display = model[30];
            } else if (ans == "-....") {
                printf("6");
                display = model[31];
            } else if (ans == "--...") {
                printf("7");
                display = model[32];
            } else if (ans == "---..") {
                printf("8");
                display = model[33];
            } else if (ans == "----.") {
                printf("9");
                display = model[34];
            } else if (ans == "-----") {
                printf("0");
                display = model[35];
            }

            for (int i = 0; i < 19; i++) {
                printf("%d ", data[i]);
            }
            printf("\n");
        }
    }
}
