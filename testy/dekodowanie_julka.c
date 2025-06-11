#include "dekodowanie.h"
#include "konwersje.h"
#include "lancuchy.h"

#define NULL '\0'
#define MAX_KEYWORD_NR 3

struct Keyword asKeywordList[MAX_KEYWORD_NR] = {
    {RST, "reset"}, 
	{LD, "load"}, 
	{ST, "store"}
};

struct Token asToken[MAX_TOKEN_NR];

unsigned char ucTokenNr = 0;

enum State {TOKEN, DELIMITER};

unsigned char ucFindTokensInString(char *pcString) {

	enum State eCurrentState = DELIMITER;
	unsigned char ucCharacterCounter;
	unsigned char ucCurrentCharacter;
	ucTokenNr = 0;

	for(ucCharacterCounter = 0; ; ucCharacterCounter++) {
		ucCurrentCharacter = pcString[ucCharacterCounter];
		switch(eCurrentState) {
			case DELIMITER:
				if(NULL == ucCurrentCharacter) {
					return ucTokenNr;
				}
				else if(DELIMITER_CHARACTER == ucCurrentCharacter) {
					eCurrentState = DELIMITER;
				}
				else {
					eCurrentState = TOKEN;
					asToken[ucTokenNr].uValue.pcString = (pcString + ucCharacterCounter);
					ucTokenNr++;
				}
				break;
			case TOKEN:
				if(MAX_TOKEN_NR <= ucTokenNr) {
					return ucTokenNr;
				}
				else if(NULL == ucCurrentCharacter) {
					return ucTokenNr;
				}
				else if(DELIMITER_CHARACTER == ucCurrentCharacter) {
					eCurrentState = DELIMITER;
				}
				else {
					eCurrentState = TOKEN;
				}
				break;
		}
	}
}

enum Result eStringToKeyword(char pcStr[], enum KeywordCode *peKeywordCode) {

  unsigned char ucKeywordCounter;

  for (ucKeywordCounter = 0; ucKeywordCounter < MAX_KEYWORD_NR;
       ucKeywordCounter++) {

    if (EQUAL == eCompareString(pcStr, asKeywordList[ucKeywordCounter].cString)) {
      *peKeywordCode = asKeywordList[ucKeywordCounter].eCode;
      return OK;
    }
  }
  return ERROR;
}

void DecodeTokens(void) {
	
	unsigned char ucTokenCounter;
	struct Token * psCurrentToken;
	
	for(ucTokenCounter = 0; ucTokenNr > ucTokenCounter; ucTokenCounter++) {
		psCurrentToken = &asToken[ucTokenCounter];
		if(OK == eStringToKeyword(psCurrentToken->uValue.pcString, &psCurrentToken->uValue.eKeyword)) {
			psCurrentToken->eType = KEYWORD;
		}
		else if(OK == eHexStringToUInt(psCurrentToken->uValue.pcString, &psCurrentToken->uValue.uiValue)) {
			psCurrentToken->eType = NUMBER;
		}
		else {
			psCurrentToken->eType = STRING;
		}
	}
}

void DecodeMsg(char *pcString) {  
  ucTokenNr = ucFindTokensInString(pcString);
  ReplaceCharactersInString(pcString, DELIMITER_CHARACTER, NULL);
  DecodeTokens();
}
