#include "mbed.h"

// Hardware Definitions
#define LEDMASK_C 0x4C // instead of writing out many 1 and 0's
#define LEDMASK_B 0x4081
// Objects
PortOut leds_C(PortC, LEDMASK_C);
PortOut leds_B(PortB, LEDMASK_B);

int main()
{
    while (true) {
        leds_C = leds_C ^ LEDMASK_C;   // Logic XOR switches on and off LED's
        leds_B = leds_B ^ LEDMASK_B;
        wait_us(500000);
    }
}




