#include "UartRecieverOnInterrupts.h"
#include "servo.h"

extern char cOdebranyZnak;

int main(){
	unsigned int uiDesiredPosition = 0;
	
	ServoInit(30);
	UART_InitWithInt(9600);
	
	while(1){
		switch(cOdebranyZnak){
			case '1':
				uiDesiredPosition += 12;
				ServoGoTo(uiDesiredPosition);
				cOdebranyZnak = 0;
				break;
			case 'c':
				ServoCallib();
				uiDesiredPosition = 0;
				cOdebranyZnak = 0;
				break;
			default:
				break;
		}
	}
}
