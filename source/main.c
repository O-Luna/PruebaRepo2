#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_uart.h"
#include "Drivers/GPIO_Display/display_driver.h"
#include "Drivers/PIT/pit_driver.h"

void *callback_1;


int main(void) {

	Display_GPIOs_init();
	PIT_init_d();

	while(1){
		Show_Seconds();
		PIT_Delay(1000000);
	}
}
