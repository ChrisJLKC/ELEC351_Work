#include "mbed.h"
#include "uop_msb.h"
#include "PushSwitch.hpp"
#include "FlashingLED.hpp"
#include <cstdio>

using namespace uop_msb;

void task1();
void task2();
void task3();

typedef enum {NONE=0, THREAD1=0b001, THREAD2=0b010, THREAD3=0b011, ALL=0b100} THREADHEALTH; 
uint8_t threadHealth = 0b000;
Mutex threadHealthLock;
void isAlive(THREADHEALTH th)
{
    threadHealthLock.lock();
    threadHealth |= th;
    if (threadHealth & THREAD1) {
        printf("Thread 1 checked in\n");
    }
    if (threadHealth & THREAD2) {
        printf("Thread 2 checked in\n");
    }
    if (threadHealth & THREAD3) {
        printf("Thread 3 checked in\n");
    }
    if (threadHealth == ALL) {
        // Resets the watchdog timer
        Watchdog::get_instance().kick();
        threadHealth = NONE;
        printf("All checked in: Reset Watchdog\n");
    }
    threadHealthLock.unlock();
}

//Threads
Thread t1, t2, t3;

#define TIMEOUT_MS 10000
int main() {

    printf("***** RESTART *****\n");
    Watchdog &watchdog = Watchdog::get_instance();
    watchdog.start(TIMEOUT_MS);    

    t1.start(task1);
    t2.start(task2);
    t3.start(task3);

    //Wait for t1, t2 and t3 to end (which they never do)
    t1.join();
    t2.join();
    t3.join();
}

// Version 1 - Partially uses a spinning technique
void task1() {
    DigitalOut red_led(TRAF_RED1_PIN);  
    DigitalIn sw1(BTN1_PIN);
    red_led = sw1;
    
    while(true) {
        while (sw1 == 0) {};            //BLOCKS via SPINNING
        
        isAlive(THREAD1);
        ThisThread::sleep_for(50ms);    //Blocks in the WAITING state

        while (sw1 == 1) {};            //BLOCKS via SPINNING

        isAlive(THREAD1);
        red_led = !red_led;             
        ThisThread::sleep_for(50ms);    //Blocks in the WAITING state  
    }    
}

// Version 2 - uses a much more power-friendly ISR driven method
void task2() 
{
    DigitalOut green_led(TRAF_GRN1_PIN);
    PushSwitch sw2(BTN2_PIN);

    while(true) {

        sw2.waitForPress();         //Blocks in the WAITING state 

        isAlive(THREAD2);
        ThisThread::sleep_for(50ms);    //Blocks in the WAITING state

        sw2.waitForRelease();       //Blocks in the WAITING state

        isAlive(THREAD2);
        green_led = !green_led;         
        ThisThread::sleep_for(50ms);    //Blocks in the WAITING state

    }    
}

// Version 3 - ISR Method (Not quite works)
void task3() {
    DigitalOut yellow_led(TRAF_YEL1_PIN);
    PushSwitch sw3(BTN3_PIN);

    while(true) {

        sw3.waitForPress();         //Blocks in the WAITING state 

        isAlive(THREAD3);
        ThisThread::sleep_for(50ms);    //Blocks in the WAITING state

        sw3.waitForRelease();       //Blocks in the WAITING state

        isAlive(THREAD3);
        yellow_led = !yellow_led;         
        ThisThread::sleep_for(50ms);    //Blocks in the WAITING state

    }   
}

