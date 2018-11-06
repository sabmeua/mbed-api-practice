/*
 * Copyright (c) 2018, sabmeua <sabme.ua@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0       
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "select_app.h"

#if APP == APP_CRITICAL_SECTION_LOCK

#include "rtos/Thread.h"
#include "mbed.h"
#include "rtos/rtos_idle.h"
#include "platform/mbed_critical.h"
 
#define  USE_CRITICAL_SECTION_LOCK      0   // Set 0 to see race condition
// Note: Might require few runs to see race condition
 
#define THREAD_CNT  8
 
int32_t value = 100000;
volatile int32_t count = 0;
 
void increment(void) {
    for (int i = 0; i < value; i++) {
#if (USE_CRITICAL_SECTION_LOCK == 1)
        CriticalSectionLock  lock;
#endif
        ::count += 1;
    }
}
 
int get_count(void) {
    if (::count == (value * THREAD_CNT)) {
        printf("No Race condition\n");
    } else {
        printf("Race condition\n");
    }
    return ::count;
}
 
int main()
{
    Thread counter_thread[THREAD_CNT];    
 
    for (int i = 0; i < THREAD_CNT; i++) {
        counter_thread[i].start(callback(increment));
    }
    
    // Wait for the threads to finish
    for (int i = 0; i < THREAD_CNT; i++) {
        counter_thread[i].join();
    }    
    printf ("Counter = %d\n", get_count());
}

#endif

