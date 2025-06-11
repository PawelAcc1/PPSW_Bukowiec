#include <LPC21xx.H>
#include "konwersje.h"

#define NULL 0
#define NIBBLE_bm 0x000F

void UIntToHexStr(unsigned int uiValue, char pcStr[]){
	
	unsigned char ucNibbleCounter;
	unsigned int uiHexNibble = 0;

	pcStr[0] = '0';
	pcStr[1] = 'x';

	for(ucNibbleCounter = 0 ; ucNibbleCounter < 4 ; ucNibbleCounter++){
		
		uiHexNibble = ((uiValue >> (4*ucNibbleCounter)) & NIBBLE_bm);
		
		if(uiHexNibble < 10){
			
			pcStr[5 - ucNibbleCounter] = '0' + uiHexNibble;
		}
		else{
			
			pcStr[5 - ucNibbleCounter] = 'A' + (uiHexNibble - 10);
		}
	}
	
	pcStr[6] = NULL;
}

enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue){
	
	unsigned char ucNibbleCounter;
	unsigned int uiCurrentNibble;
	*puiValue = 0;
	
	if((pcStr[0] != '0') || (pcStr[1] != 'x') || (pcStr[2] == NULL)){
		return ERROR;
	}
	
	for(ucNibbleCounter = 2 ; (pcStr[ucNibbleCounter] != NULL) ; ucNibbleCounter++){
		if(ucNibbleCounter == 6){
			return ERROR;
		}
		uiCurrentNibble = pcStr[ucNibbleCounter];

		if(uiCurrentNibble >= '0' && uiCurrentNibble <= '9'){
			uiCurrentNibble = uiCurrentNibble - '0';
		}
		else if(uiCurrentNibble >= 'A' && uiCurrentNibble <= 'F'){
			uiCurrentNibble = uiCurrentNibble - 'A' + 10;
		}
		else{
			return ERROR;
		}
		
		*puiValue = ((*puiValue << 4) | uiCurrentNibble); 
		
	}
	return OK;

}

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]){
	
	unsigned char ucCharCounter;
	
	for(ucCharCounter = 0 ; ucCharCounter != NULL ; ucCharCounter++){
		
	}
	
	UIntToHexStr(uiValue, pcDestination + ucCharCounter);
}
