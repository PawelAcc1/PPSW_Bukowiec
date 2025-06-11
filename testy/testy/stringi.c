#include "stringi.h"

#define NULL 0

void CopyString(char pcSource[], char pcDestination[])
{

	unsigned char ucCharCounter;

  for (ucCharCounter = 0 ; pcSource[ucCharCounter] != NULL ; ucCharCounter = ucCharCounter + 1)
	{
		
		pcDestination[ucCharCounter] = pcSource[ucCharCounter];
  }
	
	pcDestination[ucCharCounter] = '\0';
}

//enum CompResult { DIFFERENT , EQUAL };

enum CompResult eCompareString(char pcStr1[], char pcStr2[]){
	
	unsigned char ucCharCounter;

	for (ucCharCounter = 0 ; pcStr1[ucCharCounter] != NULL || pcStr2[ucCharCounter] != NULL ; ucCharCounter = ucCharCounter + 1){

		if (pcStr1[ucCharCounter] != pcStr2[ucCharCounter]){
            
			return DIFFERENT;
    }
  }

    return EQUAL;
}

void AppendString (char cSourceStr[],char cDestinationStr[])
{
    
	unsigned char ucCharCounter;

  for (ucCharCounter = 0 ; cDestinationStr[ucCharCounter] != NULL ; ucCharCounter = ucCharCounter + 1)
	{

  }

	CopyString(cSourceStr, cDestinationStr + ucCharCounter);

}

void ReplaceCharactersInString(char pcString[],char cOldChar,char cNewChar){

	unsigned char ucCharCounter;

	for (ucCharCounter = 0 ; pcString[ucCharCounter] != NULL ; ucCharCounter = ucCharCounter + 1)
	{

		if ( pcString[ucCharCounter] == cOldChar )
		{

			pcString[ucCharCounter] = cNewChar;
    }
  }

}
