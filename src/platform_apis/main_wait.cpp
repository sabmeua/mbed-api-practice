#include "select_app.h"

#if APP == APP_WAIT

#include "mbed.h"

DigitalOut heartbeat(LED1);

int main() {
    while (1) {
        heartbeat = 1;
        wait(0.5);
        heartbeat = 0;
        wait(0.5);
        heartbeat = 1;
        wait_ms(500);
        heartbeat = 0;
        wait_us(500 * 1000);
    }
}

#endif

