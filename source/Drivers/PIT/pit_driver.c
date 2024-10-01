#include <stdint.h>
#include "Drivers/PIT/pit_driver.h"

#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_pit.h"

#define DEMO_PIT_BASEADDR PIT
#define DEMO_PIT_CHANNEL  kPIT_Chnl_0
#define PIT_IRQ_ID        PIT0_IRQn
#define PIT_SOURCE_CLOCK CLOCK_GetFreq(kCLOCK_BusClk)

volatile bool pitIsrFlag = false;

volatile uint8_t u_sec= 0;
volatile uint8_t d_sec= 0;

void counter(){
	if(u_sec<9)
	{
		u_sec++;
	} else
	{
		if(d_sec<5)
		{
			d_sec++;
		} else
		{
			d_sec=0;
		}
	u_sec=0;
	}
}

void PIT0_IRQHandler(void)
{
	counter();
    PIT_ClearStatusFlags(DEMO_PIT_BASEADDR, DEMO_PIT_CHANNEL, kPIT_TimerFlag);
    pitIsrFlag = true;
    __DSB();
}

void PIT1_IRQHandler(void){
	PIT_ClearStatusFlags(DEMO_PIT_BASEADDR, kPIT_Chnl_1, kPIT_TimerFlag);
	 pitIsrFlag = true;
	 __DSB();
}

void PIT0_init_d(){

	PIT_SetTimerPeriod(DEMO_PIT_BASEADDR, DEMO_PIT_CHANNEL, USEC_TO_COUNT(1000000U, PIT_SOURCE_CLOCK));
	PIT_EnableInterrupts(DEMO_PIT_BASEADDR, DEMO_PIT_CHANNEL, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT_IRQ_ID);
	PIT_StartTimer(DEMO_PIT_BASEADDR, DEMO_PIT_CHANNEL);
}

void PIT1_init_d(){
	PIT_SetTimerPeriod(DEMO_PIT_BASEADDR, kPIT_Chnl_1, USEC_TO_COUNT(10000U, PIT_SOURCE_CLOCK));
	PIT_EnableInterrupts(DEMO_PIT_BASEADDR, kPIT_Chnl_1, kPIT_TimerInterruptEnable);
	EnableIRQ(PIT1_IRQn);
	PIT_StartTimer(DEMO_PIT_BASEADDR, kPIT_Chnl_1);
}


void PIT_init_d(){
	pit_config_t pitConfig;
	PIT_GetDefaultConfig(&pitConfig);
	PIT_Init(DEMO_PIT_BASEADDR, &pitConfig);
	PIT0_init_d();
	PIT1_init_d();
}

void PIT_Delay(int time){

	int x=0;
	while(x==0){
	if (true == pitIsrFlag)
	        {
	            pitIsrFlag = false;
	            x=1;
	        }
	}
}
