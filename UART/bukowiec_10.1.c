#include "UartRecieverOnInterrupts.h"

unsigned int uiLoopCounter;

int main(){
	UART_InitWithInt(9600);
	
	while(1){
		uiLoopCounter++;
	}
} //zmiana
