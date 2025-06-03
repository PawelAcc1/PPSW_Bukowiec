#include "UartRecieverOnInterrupts.h"
#include "led.h"

extern char cOdebranyZnak;

int main(){
	LedInit();
	UART_InitWithInt(9600);
	
	while(1){
		switch(cOdebranyZnak){
			case '1':
				LedOn(0);
				break;
			case '2':
				LedOn(1);
				break;
			case '3':
				LedOn(2);
				break;
			case '4':
				LedOn(3);
				break;
			case 'c':
				LedOn(4);
				break;
			default:
				break;
		}
	}
}
