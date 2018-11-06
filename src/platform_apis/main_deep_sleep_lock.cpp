#include "select_app.h"

#if APP == APP_DEEP_SLEEP_LOCK

#include "mbed.h"

InterruptIn button(BUTTON1);
DigitalOut led(LED1);

void toggle()
{
    led = !led;
}

int main()
{
    button.rise(&toggle);
    button.fall(&toggle);

    // Lock deep sleep to decrease interrupt latency
    // at the expense of high power consumption
    DeepSleepLock lock;

    while(1) {
        // Wait and let interrupts take care of the rest
        wait(1.0);
    }
}

#endif

