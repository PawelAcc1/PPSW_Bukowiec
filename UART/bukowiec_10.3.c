#include "UartRecieverOnInterrupts.h"
#include "servo.h"

extern char cOdebranyZnak;

int main(){
	ServoInit(50);
	UART_InitWithInt(9600);
	
	while(1){
		switch(cOdebranyZnak){
			case '1':
				ServoGoTo(12);
				break;
			case '2':
				ServoGoTo(24);
				break;
			case '3':
				ServoGoTo(36);
				break;
			case 'c':
				ServoCallib();
				break;
			default:
				break;
		}
	}
}
