#include "select_app.h"

#if APP == APP_IDLELOOP

#include "mbed.h"

int main()
{
    // Deep sleep for 1 second
    printf("Deep sleep allowed: %i\r\n", sleep_manager_can_deep_sleep());
    wait(1.0);
    
    // Lock deep sleep
    printf("Locking deep sleep\r\n");
    sleep_manager_lock_deep_sleep();
    
    // Sleep for 1 second
    printf("Deep sleep allowed: %i\r\n", sleep_manager_can_deep_sleep());
    wait(1.0);
}

#endif

