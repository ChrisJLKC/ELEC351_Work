#include "mbed.h"

#include "mbed.h"
// Hardware Definitions
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

#define TRAF_GRN2_PIN PC_9
#define TRAF_YEL2_PIN PC_8
#define TRAF_RED2_PIN PC_7

#define TRAF_WHITE_PIN PF_10

#define BTN1_PIN PG_0 
#define BTN2_PIN PG_1
#define BTN3_PIN PG_2 // No pull down
#define BTN4_PIN PG_3 // No pull down

// Inputs
// Understanding of the pull down resistor: https://circuitdigest.com/tutorial/pull-up-and-pull-down-resistor
BusInOut SW(BTN1_PIN, BTN2_PIN);
BusInOut SW_Down(BTN3_PIN, BTN4_PIN); // Need to state pin mode

// Outputs
BusOut leds(TRAF_GRN1_PIN, TRAF_YEL1_PIN, TRAF_RED1_PIN);

int main()
{
    SW.input();
    SW_Down.input();
    SW_Down.mode(PinMode::PullDown);

    while (true) {
        if (SW == 1) {
            leds = 4;
        } else {
            leds = 0;
        }

        if (SW == 2) {
            leds = 2;
        } else {
            leds = 0;
        }

        if (SW_Down == 3) {
            leds = 7;
        } else {
            leds = 0;
        }
    }
}



