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

#if APP == APP_TIME

#include "mbed.h"

int main() {
    set_time(1256729737);  // Set RTC time to Wed, 28 Oct 2009 11:35:37

    while (true) {
        time_t seconds = time(NULL);
        
        printf("Time as seconds since January 1, 1970 = %d\n", seconds);
        
        printf("Time as a basic string = %s", ctime(&seconds));

        char buffer[32];
        strftime(buffer, 32, "%I:%M %p\n", localtime(&seconds));
        printf("Time as a custom formatted string = %s", buffer);
        
        wait(1);
    }
}

#endif


