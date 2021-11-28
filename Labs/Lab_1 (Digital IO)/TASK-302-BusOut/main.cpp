#include "mbed.h"

// Hardware Definitions 
// (EXTERNAL PUSH/PULL LEDs)
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

// (ON BOARD LEDs)

#define PCB_LED1 PB_0
#define PCB_LED2 PB_7
#define PCB_LED3 PB_14

//Objects 
BusOut leds_def(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN); // Just push / pull leds
BusOut leds_new(TRAF_RED1_PIN, TRAF_YEL1_PIN, TRAF_GRN1_PIN, PCB_LED1, PCB_LED2, PCB_LED3); // push / pull and on board leds

int main()
{
    while (true) {
        for (int i = 0; i < 8; i++) { // Binary values are added up to 7 which for us is full led's
            leds_def = i; 
            wait_us(500000);
        } 

        leds_def = 0; // Stops difference in buses and different outputs.

        leds_new = 0;   //Binary 000000
        wait_us(500000);
        leds_new = 63;   //Binary 111111
        wait_us(500000);   

        leds_new = 0;   //Binary 000000
        wait_us(500000);
        leds_new = 63;   //Binary 111111
        wait_us(500000);

        leds_new = 0; // Stops difference in buses and different outputs.
    }
}


