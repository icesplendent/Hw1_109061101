#include "mbed.h"

// table to show Morse Code in LED
int A[3] = {2, 1, 3};
int B[5] = {4, 3, 1, 1, 1};
int C[5] = {4, 3, 1, 3, 1};
int D[4] = {3, 3, 1, 1};
int E[2] = {1, 1};
int F[5] = {4, 1, 1, 3, 1};
int G[4] = {3, 3, 3, 1};
int H[5] = {4, 1, 1, 1, 1};
int I[3] = {2, 1, 1};
int J[5] = {4, 1, 3, 3, 3};
int K[4] = {3, 3, 1, 3};
int L[5] = {4, 1, 3, 1, 1};
int M[3] = {2, 3, 3};
int N[3] = {2, 3, 1};
int O[4] = {3, 3, 3, 3};
int P[5] = {4, 1, 3, 3, 1};
int Q[5] = {4, 3, 3, 1, 3};
int R[4] = {3, 1, 3, 1};
int S[4] = {3, 1, 1, 1};
int T[2] = {1, 1};
int U[4] = {3, 1, 1, 3};
int V[5] = {4, 1, 1, 1, 3};
int W[4] = {3, 1, 3, 3};
int X[5] = {4, 3, 1, 1, 3};
int Y[5] = {4, 3, 1, 3, 3};
int Z[5] = {4, 3, 3, 1, 1};
int one[6] = {5, 1, 3, 3, 3, 3};
int two[6] = {5, 1, 1, 3, 3, 3};
int three[6] = {5, 1, 1, 1, 3, 3};
int four[6] = {5, 1, 1, 1, 1, 3};
int five[6] = {5, 1, 1, 1, 1, 1};
int six[6] = {5, 3, 1, 1, 1, 1};
int seven[6] = {5, 3, 3, 1, 1, 1};
int eight[6] = {5, 3, 3, 3, 1, 1};
int nine[6] = {5, 3, 3, 3, 3, 1};
int zero[6] = {5, 3, 3, 3, 3, 3};

int* table[36] = {A,   B,     C,    D,    E,   F,     G,     H,    I,
                  J,   K,     L,    M,    N,   O,     P,     Q,    R,
                  S,   T,     U,    V,    W,   X,     Y,     Z,    one,
                  two, three, four, five, six, seven, eight, nine, zero};

// define the button to press

// define the light to shown
DigitalOut myled(LED1);

// main() runs in its own thread in the OS
int main() {
    // check that myled object is initialized and connected to a pin
    if (myled.is_connected()) {
        printf("myled is initialized and connected!\n\r");
    }

    // Blink LED
    while (1) {
        // show AB
        for (int i = 0; i <= 1; i++) {
            for (int j = 1; j <= table[i][0]; j++) {
                for (int k = 0; k < table[i][j]; k++) {
                    myled = 1;  // set LEB1 pin to high
                    ThisThread::sleep_for(500ms);
                }
                myled = 0;
                ThisThread::sleep_for(500ms);
            }
            ThisThread::sleep_for(1000ms);
        }

        // show Blank
        ThisThread::sleep_for(2000ms);

        // show C
        for (int j = 1; j <= table[2][0]; j++) {
            for (int k = 0; k < table[2][j]; k++) {
                myled = 1;
                ThisThread::sleep_for(500ms);
            }
            myled = 0;
            ThisThread::sleep_for(500ms);
        }

        for (int i = 0; i < 5; i++) {
            myled = 1;
            ThisThread::sleep_for(100ms);
            myled = 0;
            ThisThread::sleep_for(100ms);
        }
    }
}
