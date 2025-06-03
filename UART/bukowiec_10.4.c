#include "UartRecieverOnInterrupts.h"
#include "servo.h"

extern char cOdebranyZnak;

int main(){
	unsigned int uiDesiredPosition = 0;
	
	ServoInit(50);
	UART_InitWithInt(9600);
	
	while(1){
		switch(cOdebranyZnak){
			case '1':
				uiDesiredPosition += 12;
				ServoGoTo(uiDesiredPosition);
				break;
			case 'c':
				ServoCallib();
				break;
			default:
				break;
		}
	}
}
