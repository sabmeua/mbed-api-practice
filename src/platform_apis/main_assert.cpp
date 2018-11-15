#include "select_app.h"

#if APP == APP_ASSERT

#include "mbed.h"
#include "platform/mbed_assert.h"

#define MAX_THREAD_INFO 10

int main() {
  DigitalOut *led1, *led2;

  /**
   * Assert macro would be active only if debug build profile.
   *
   * It shows below output:
   *
   *  Assertion led1 -> OK
   *  mbed assertation failed: led2, file: ./src/platform_apis/main_assert.cpp, line 17
   */

  led1 = new DigitalOut(LED1);
  MBED_ASSERT(led1);
  printf("Assertion led1 -> OK\n");

  MBED_ASSERT(led2);
  printf("Assertion led2 -> OK\n");


  /**
   * MBED_ASSERT macro is evaluated at run-time but MBED_STATIC_ASSERT macro is evaluated at compile-time.
   */
#if 0 // When this switch is enabled and the assertion will fail and the compilation will finish with error.
  uint8_t a;
  uint16_t b;
#else
  uint8_t a, b;
#endif
  MBED_STATIC_ASSERT(sizeof(a) == sizeof(b), "Size of a and b must be equal");
}

#endif

