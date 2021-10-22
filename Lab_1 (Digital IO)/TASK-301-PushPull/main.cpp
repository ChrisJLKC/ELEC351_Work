#include "mbed.h"

// Hardware Definitions (THESE ARE ALLOWED FOR PUSH_PULL OPERATION)
#define TRAF_GRN1_PIN PC_6
#define TRAF_YEL1_PIN PC_3
#define TRAF_RED1_PIN PC_2

// Objects All LED's are now on (301 - 4) 
DigitalOut grn(TRAF_GRN1_PIN,1);
DigitalOut yel(TRAF_YEL1_PIN,1);
DigitalOut red(TRAF_RED1_PIN,1); // RED is on (301 - 3)

int main()
{
    while (true) {
        red = 0;
        yel = 1;
        grn = 1;
        wait_us(500000);
        red = 1;
        yel = 0;
        grn = 0;  
        wait_us(500000);    
    }
}

