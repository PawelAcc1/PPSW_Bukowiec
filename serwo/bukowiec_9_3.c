#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"

#define TIMER0_INTERRUPT_ENABLE (1<<4)
#define TIMER0_INTERRUPT_DISABLE (1<<4)

#define DETECTOR_INPUT_SET_bm (1<<10)
#define DETECTOR_bm (1<<10)

void DetectorInit(void){
	IO0DIR &= (~DETECTOR_INPUT_SET_bm);
}

enum DetectorState {ACTIVE , INACTIVE};
enum DetectorState eReadDetector(void){
	if((IO0PIN & DETECTOR_bm) == 0){
		return ACTIVE;
	}
	else{
		return INACTIVE;
	}
}

enum ServoState {CALLIB, IDLE, IN_PROGRESS};
struct Servo{
	enum ServoState eServoState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
};
volatile struct Servo sServo;

void SetServoToPosition(void){
	
	switch(sServo.eServoState){
		case CALLIB:
			if(eReadDetector() == ACTIVE){
				sServo.uiCurrentPosition = 0;
				sServo.uiDesiredPosition = 0;
				sServo.eServoState = IDLE;
			}
			else{
				LedStepLeft();
				sServo.eServoState = CALLIB;
			}
			break;
		case IDLE:
			if(sServo.uiCurrentPosition != sServo.uiDesiredPosition){
				sServo.eServoState = IN_PROGRESS;
			}
			else{
				sServo.eServoState = IDLE;
			}
			break;
		case IN_PROGRESS:
			if(sServo.uiCurrentPosition == sServo.uiDesiredPosition){
				sServo.eServoState = IDLE;
			}
			else{
				if(sServo.uiCurrentPosition < sServo.uiDesiredPosition){
					LedStepRight();
					sServo.uiCurrentPosition++;
				}
				else if(sServo.uiCurrentPosition > sServo.uiDesiredPosition){
					LedStepLeft();
					sServo.uiCurrentPosition--;
				}
				sServo.eServoState = IN_PROGRESS;
			}
	}
}

void ServoCallib(void){
	VICIntEnClr = TIMER0_INTERRUPT_DISABLE;
	sServo.eServoState = CALLIB;
	VICIntEnable = TIMER0_INTERRUPT_ENABLE;
}

void ServoInit(unsigned int uiServoFrequency){
	LedInit();
	DetectorInit();
	ServoCallib();
	Timer0Interrupts_Init((1000000/uiServoFrequency), &SetServoToPosition);
}

void ServoGoTo(unsigned int uiPosition){
	VICIntEnClr = TIMER0_INTERRUPT_DISABLE;
	sServo.uiDesiredPosition = uiPosition;
	VICIntEnable = TIMER0_INTERRUPT_ENABLE; 
}
