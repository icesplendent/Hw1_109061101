#include "mbed.h"

// Initialize a pins to perform analog and digital output functions
// Adjust analog output pin name to your board spec.
AnalogOut aout(PA_4);
DigitalOut dout(LED1);

int main(void) {
    while (1) {
        // change the voltage on the digital output pin by 0.1 * VCC
        //  and print what the measured voltage should be (assuming VCC = 3.3v)
        float i = 0.0f;

        while (1) {
            if (i >= 1.0f) {
                i = 0.0f;
            }

            aout.write_u16(65536 * i);
            // printf("aout = %f volts\n", aout.read() * 3.3f);
            i += 0.1f;
            wait_us(1);
        }
    }
}