#include "mbed.h"

#include "select_app.h"

#if APP == APP_WAIT

DigitalOut heartbeat(LED1);

int main() {
    while (1) {
        heartbeat = 1;
        wait(0.5);
        heartbeat = 0;
        wait(0.5);
    }
}

#endif

