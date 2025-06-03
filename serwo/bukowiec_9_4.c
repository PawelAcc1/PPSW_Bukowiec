#include "led.h"
#include "keyboard.h"
#include "timer_interrupts.h"
#include "servo.h"

int main(){
	enum ButtonState eButtonState;
	KeyInit();
	ServoInit(100);
	
	while(1){
		eButtonState = eKeyboardRead();
		switch(eButtonState){
			case BUTTON_0:
				ServoCallib();
				break;
			case BUTTON_1:
				ServoGoTo(12);
				break;
			case BUTTON_2:
				ServoGoTo(24);
				break;
			case BUTTON_3:
				ServoGoTo(36);
				break;
			case RELEASED:
				break;
		}
	}
}
