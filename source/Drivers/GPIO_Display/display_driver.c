#include "fsl_debug_console.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "board.h"
#include "fsl_uart.h"
#include "Drivers/GPIO_Display/display_driver.h"
#include "Drivers/PIT/pit_driver.h"

#define SEG_A (1 << 0)
#define SEG_B (1 << 1)
#define SEG_C (1 << 2)
#define SEG_D (1 << 3)
#define SEG_E (1 << 4)
#define SEG_F (1 << 5)
#define SEG_G (1 << 6)

const uint8_t nums[10] = {
	//gfedcba
    0b0111111, //0
    0b0000110, //1
    0b1011011, //2
    0b1001111, //3
    0b1100110, //4
    0b1101101, //5
    0b1111101, //6
    0b0000111, //7
    0b1111111, //8
    0b1101111  //9

};

bool alt_sec= false;
uint8_t segments=0;

void clean(){
	GPIOD->PSOR = (1 << 0);
	GPIOD->PSOR = (1 << 1);
	GPIOD->PSOR = (1 << 2);
	GPIOD->PSOR = (1 << 3);
	GPIOD->PSOR = (1 << 4);
	GPIOD->PSOR = (1 << 5);
	GPIOD->PSOR = (1 << 6);
}


void mostrar(uint8_t number) {
    if (number > 9) return;
    clean();

    uint8_t segments = nums[number];
    if (segments & SEG_A) GPIOD->PCOR = (1 << 0);
    if (segments & SEG_B) GPIOD->PCOR = (1 << 1);
    if (segments & SEG_C) GPIOD->PCOR = (1 << 2);
    if (segments & SEG_D) GPIOD->PCOR = (1 << 3);
    if (segments & SEG_E) GPIOD->PCOR = (1 << 4);
    if (segments & SEG_F) GPIOD->PCOR = (1 << 5);
    if (segments & SEG_G) GPIOD->PCOR = (1 << 6);
}

void Show_Seconds(){
	if (u_sec > 9|| d_sec >9) return;
	clean();

	if(alt_sec==false){
		GPIOC->PSOR |= (1 << 5);
		GPIOC->PCOR |= (1 << 4); //apagar
		segments = nums[u_sec];

	} else{
		GPIOC->PSOR |= (1 << 4);
		GPIOC->PCOR |= (1 << 5); //apagar
		segments = nums[d_sec];
	}

	if (segments & SEG_A) GPIOD->PCOR = (1 << 0);
	if (segments & SEG_B) GPIOD->PCOR = (1 << 1);
	if (segments & SEG_C) GPIOD->PCOR = (1 << 2);
	if (segments & SEG_D) GPIOD->PCOR = (1 << 3);
	if (segments & SEG_E) GPIOD->PCOR = (1 << 4);
	if (segments & SEG_F) GPIOD->PCOR = (1 << 5);
	if (segments & SEG_G) GPIOD->PCOR = (1 << 6);

	alt_sec= !alt_sec;
}

void prender(){
	GPIOC->PSOR |= (1 << 0); //prender
}

void apagar(){
	GPIOC->PCOR |= (1 << 0); //apagar
}

void Display_GPIOs_init(){
	SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK | SIM_SCGC5_PORTD_MASK;


	    PORTD->PCR[0] = PORT_PCR_MUX(1); // a PTD0
	    GPIOD->PDDR |= (1 << 0);

	    PORTD->PCR[1] = PORT_PCR_MUX(1); // b PTD1
	    GPIOD->PDDR |= (1 << 1);

	    PORTD->PCR[2] = PORT_PCR_MUX(1); // c PTD2
	    GPIOD->PDDR |= (1 << 2);

	    PORTD->PCR[3] = PORT_PCR_MUX(1); // d PTD3
	    GPIOD->PDDR |= (1 << 3);

	    PORTD->PCR[4] = PORT_PCR_MUX(1); // e PTC4
	    GPIOD->PDDR |= (1 << 4);

	    PORTD->PCR[5] = PORT_PCR_MUX(1); // f PTC2
	    GPIOD->PDDR |= (1 << 5);

	    PORTD->PCR[6] = PORT_PCR_MUX(1); // g PTC3
	    GPIOD->PDDR |= (1 << 6);

	    PORTC->PCR[5] = PORT_PCR_MUX(1); // anodo PTC5
	    GPIOC->PDDR |= (1 << 5);
	    //GPIOC->PSOR |= (1 << 5); //prender
	    //GPIOC->PCOR |= (1 << 0); //apagar

	    PORTC->PCR[4] = PORT_PCR_MUX(1); // anodo PTC4 //cambiar
	    GPIOC->PDDR |= (1 << 4);
	    //GPIOC->PSOR |= (1 << 0); //prender
}


