#include "select_app.h"

#if APP == APP_CALLBACK

#include "mbed.h"

RawSerial  pc(USBTX, USBRX);
RawSerial  dev(D1, D0);
DigitalOut led1(LED1);
DigitalOut led4(LED4);

void dev_recv()
{
    led1 = !led1;
    while(dev.readable()) {
        pc.putc(dev.getc());
    }
}

void pc_recv()
{
    led4 = !led4;
    while(pc.readable()) {
        dev.putc(pc.getc());
    }
}

int main()
{
    pc.baud(9600);
    dev.baud(9600);

    pc.attach(&pc_recv, Serial::RxIrq);
    dev.attach(&dev_recv, Serial::RxIrq);

    while(1) {
        sleep();
    }
}

#endif

