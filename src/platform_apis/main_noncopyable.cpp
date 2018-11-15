#include "select_app.h"

#if APP == APP_NONCOPYABLE

#include "mbed.h"

class Led : public DigitalOut {
};

class LedOwner : NonCopyable<Led> {

};

int main() {

}

#endif

