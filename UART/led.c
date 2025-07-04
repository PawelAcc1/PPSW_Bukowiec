#include <LPC21xx.H>
#include "led.h"

#define LED0_bm (1<<16)
#define LED1_bm (1<<17)
#define LED2_bm (1<<18)
#define LED3_bm (1<<19)

void LedInit(){
	
	IO1DIR |= (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	
	IO1SET = LED0_bm;
}

void LedOn(unsigned char ucLedIndeks){
	
	IO1CLR = (LED0_bm | LED1_bm | LED2_bm | LED3_bm);

	switch (ucLedIndeks){

		case 0:
			IO1SET = LED0_bm;
			break;
		
		case 1:
			IO1SET = LED1_bm;
			break;

		case 2:
			IO1SET = LED2_bm;
			break;

		case 3:
			IO1SET = LED3_bm;
			break;
		
		case 4:
			break;
	}
}

void LedStep(enum TwoDirections eStepDirection){
	static unsigned int uiLedIndex = 0;
	
	switch(eStepDirection){
		case LEFT:
			uiLedIndex = (uiLedIndex + 1);
			break;
		
		case RIGHT:
			uiLedIndex = (uiLedIndex - 1);
			break;
		
		default:
			break;
	}
	
	uiLedIndex %= 4;
	LedOn(uiLedIndex);
}

void LedStepLeft(void){
	enum TwoDirections eShiftLeft = LEFT;
	LedStep(eShiftLeft);
}

void LedStepRight(void){
	enum TwoDirections eShiftRight = RIGHT;
	LedStep(eShiftRight);
}
