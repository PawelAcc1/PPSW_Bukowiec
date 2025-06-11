#define NULL '\0'

#include "konwersje.h"

void UIntToHexStr(unsigned int uiValue, char pcStr[]) {
	int iNibbleCounter;
	
	pcStr[0] = '0';
	pcStr[1] = 'x';
	
	for (iNibbleCounter = 0; iNibbleCounter < 4; iNibbleCounter++) {
    	unsigned char ucDigit = (uiValue >> (iNibbleCounter * 4)) & 0xF;
    	if (ucDigit < 10) { //błąd którego nie wykryją, graniczne wartości do ucDigit <9
        	pcStr[5 - iNibbleCounter] = '0' + ucDigit;
    	} else {
        	pcStr[5 - iNibbleCounter] = 'A' + (ucDigit - 10);
    	}
	}
 
	pcStr[6] = NULL;
}


enum Result eHexStringToUInt(char pcStr[], unsigned int *puiValue) {
    unsigned char ucCharCounter;
    int uiCurrentCharacter;

    if ((pcStr[0] != '0') || (pcStr[1] != 'x') || (pcStr[2] == '\0')) {
        return ERROR;
    }

    *puiValue = 0;

    for (ucCharCounter = 2; pcStr[ucCharCounter] != NULL; ucCharCounter++) {
        uiCurrentCharacter = pcStr[ucCharCounter];

        if (uiCurrentCharacter == NULL) {
            return OK;
        }
        
        if (ucCharCounter > 5) {
            return ERROR;
        }
        
        *puiValue = *puiValue << 4;
        
        if ((uiCurrentCharacter >= '0') && (uiCurrentCharacter <= '9')) {
            *puiValue = *puiValue + (uiCurrentCharacter - '0');
        } else if (uiCurrentCharacter >= 'A' && uiCurrentCharacter <= 'F') {
            *puiValue = *puiValue + (uiCurrentCharacter - 'A' + 10);
        } else {
            return ERROR;
        }
    }

    return OK;
}


void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]) {
    while (*pcDestinationStr != NULL) {
        pcDestinationStr++;
    }

    UIntToHexStr(uiValue, pcDestinationStr);
}
