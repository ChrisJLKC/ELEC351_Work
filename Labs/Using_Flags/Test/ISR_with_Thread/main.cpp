#include "mbed.h"

Ticker tick;
Thread t1;

AnalogIn ldr(PC_0);

void ISR_Sample(void) {
    t1.flags_set(1);
}

void Sampling(void) {
    while(true) {
        ThisThread::flags_wait_any(1);
        ThisThread::flags_clear(1);
        float ldr_reading = ldr;
        printf("%4.2f", ldr_reading);
    }
}

int main()
{
    tick.attach(&ISR_Sample, 100ms);
    t1.start(Sampling);
}

