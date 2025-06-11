#include <LPC21xx.H>
#include "led.h"
#include "timer_interrupts.h"
//zmiana
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

enum ServoState {CALLIB , STOP};
enum ServoState eServoState = CALLIB;
void ServoCallibration(void){
	switch(eServoState){
			case STOP:
				if(eReadDetector() == ACTIVE){
					eServoState = STOP;
				}
				else{
					eServoState = CALLIB;
				}
				break;
			case CALLIB:
				if(eReadDetector() == ACTIVE){
					eServoState = STOP;
				}
				else{
					LedStepLeft();
					eServoState = CALLIB;
				}
				break;
		}
}


int main(){
	unsigned int iMainLoopCtr;
	
	DetectorInit();
	Timer0Interrupts_Init(200000, &ServoCallibration);

	while(1){
	 	iMainLoopCtr++;
	}
}
