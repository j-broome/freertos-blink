// core subset of Raspberry Pi Pico SDK libraries used by most executables along with some additional utility methods
#include "pico/stdlib.h"

// core subset of FreeRTOS libraries used by the kernel
#include "FreeRTOS.h"

// type by which tasks are referenced, i.e., a call to xTaskCreate returns (via a pointer parameter) an TaskHandle_t variable that can then be used as a parameter to vTaskDelete to delete the task
#include "task.h"

// onboard LED task
void vBlinkTask() {
   // do this forever
   for (;;) {
      // GPIO High
      gpio_put(PICO_DEFAULT_LED_PIN, 1);
      // puts the task in a blocked state for the specificed tick count
      vTaskDelay(1000);
      // GPIO Low
      gpio_put(PICO_DEFAULT_LED_PIN, 0);
      // puts the task in a blocked state for the specificed tick count
      vTaskDelay(1000);
   }
}

void main() {
// initialize onboard LED GPIO - PICO_DEFAULT_LED_PIN is pin 25
   gpio_init(PICO_DEFAULT_LED_PIN);
// set the GPIO to be an output
   gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);

// tasks are created using the FreeRTOS xTaskCreate() API function; the most fundamental component of a multitasking system
   xTaskCreate(vBlinkTask,       // pVTaskCode - pointer to the function that implements the task (in effect, just the name of the function)
               "Blink Task",     // pcName - descriptive name that is used purely as a debugging aid
               128,              // usStackDepth - number of words (not bytes) the stack can hold
               NULL,             // pvParameters - task functions accept a parameter of type pointer to void (void*)
               1,                // uxPriority - 0: lowest priority to (configMax_PRIORITIES - 1)
               NULL);            // pxCreatedTask - can be used to pass out a handle which can be used to delete or change the priority level

// start the task scheduler which manages the task execution order and processing time
   vTaskStartScheduler();        // once the scheduler is started it will run continuously until it is stopped or a system reset occurs
}