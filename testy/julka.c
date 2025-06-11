#include <stdio.h>
#include <string.h>
#include "konwersje.h"
#include "dekodowanie.h"
#include "lancuchy.h"
#include <stddef.h> 

void TestOf_CopyString(void) {
    char cString1[] = "test of function";
    char cString2[25] = "";

    printf("CopyString test:\n");
    printf("Test - "); // Weryfikacja, czy łańcuch został poprawnie skopiowany do docelowej zmiennej
    CopyString(cString1, cString2);
    if(strcmp(cString2, cString1) == 0) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_eCompareString(void) {
    char cString1[] = "Zaliczenie testy 0x02";
    char cStringShorter[] = "Zaliczenie testy";
    char cStringLonger[] = "Zaliczenie testy obw 0x01";
    char cDifferentString[] = "Program obowiązkowy";


    printf("eCompareString test:\n");
    printf("Test 1 - "); // Sprawdzenie porównania identycznych łańcuchów
    if (eCompareString(cString1, cString1) == EQUAL) printf("OK\n"); else printf("Error\n");

    printf("Test 2 - "); // Weryfikacja działania dla dłuższego łańcucha
    if (eCompareString(cString1, cStringLonger) == DIFFERENT) printf("OK\n"); else printf("Error\n");

    printf("Test 3 - "); // Weryfikacja działania dla krótszego łańcucha
    if (eCompareString(cString1, cStringShorter) == DIFFERENT) printf("OK\n"); else printf("Error\n");

    printf("Test 4 - "); // Sprawdzenie porównania różnych łańcuchów
    if (strcmp(cString1, cDifferentString) != 0 && eCompareString(cString1, cDifferentString) == DIFFERENT) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_AppendString(void) {
    char cTestDest1[20] = "Pierwszy";
    char cTestSrc1[] = "Drugi";

    char cTestDest2[15] = "";
    char cTestSrc2[] = "NiePusty";

    char cTestDest3[20] = "Tekst";
    char cTestSrc3[] = "";

    char cTestDest4[30] = "Dodanie";
    char cTestSrc4[] = "Łańcucha";


    printf("Testy funkcji AppendString:\n");
    printf("Test 1 - "); // Sprawdzenie czy funkcja poprawnie dodaje niepusty lancuch do niepustego lancucha
    AppendString(cTestSrc1, cTestDest1);
    if (strcmp(cTestDest1, "PierwszyDrugi") == 0) printf("OK\n"); else printf("Error\n");
  
    printf("Test 2 - "); // Sprawdzenie czy funkcja poprawnie dodaje pusty lancuch do niepustego lancucha
    AppendString(cTestSrc2, cTestDest2);

    if (strcmp(cTestDest2, "NiePusty") == 0) printf("OK\n"); else printf("Error\n");

    printf("Test 3 - "); // Sprawdzenie czy funkcja poprawnie dodaje niepusty lancuch do pustego lancucha
    AppendString(cTestSrc3, cTestDest3);

    if (strcmp(cTestDest3, "Tekst") == 0) printf("OK\n"); else printf("Error\n");

    printf("Test 4 - "); // Ogólny test dołączania różnych łańcuchów
    AppendString(cTestSrc4, cTestDest4);

    if (strcmp(cTestDest4, "DodanieŁańcucha") == 0) printf("OK\n"); else printf("Error\n");
}

void TestOf_ReplaceCharactersInString(void) {
    char cOldChar = 'f';
    char cNewChar = 'g';
    char cNewString[] = "test of function";

    printf("ReplaceCharactersInString test:\n");
    printf("Test - "); // Weryfikacja, czy funkcja poprawnie zamienia wszystkie wystąpienia znaku
    ReplaceCharactersInString(cNewString, cOldChar, cNewChar);
    if (strcmp(cNewString, "test og gunction") == 0) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_UIntToHexStr(void) {
    char cString[7];

    printf("UIntToHexStr test:\n");
    printf("Test 1 - "); // Sprawdzenie konwersji wartości dziesiętnej na format szesnastkowy
    UIntToHexStr(0x90AF, cString);
    if (strcmp(cString, "0x90AF") == 0) printf("OK\n"); else printf("Error\n");
}

void TestOf_eHexStringToUInt(void) {
    
    unsigned int uiResult;

    printf("eHexStringToUInt test:\n");
    printf("Test 1 - "); // Testowanie błędnego formatu wejściowego (brak "0x")
    if (eHexStringToUInt("sth",&uiResult) == ERROR) printf("OK\n"); else printf("Error\n");

    printf("Test 2 - "); // Testowanie zbyt krótkiego łańcucha wejściowego ("0x" bez cyfr)
    if (eHexStringToUInt("0x",&uiResult) == ERROR) printf("OK\n"); else printf("Error\n");

    printf("Test 3 - "); // Testowanie zbyt długiego łańcucha wejściowego (przekroczenie limitu 4 cyfr HEX)
    if (eHexStringToUInt("0x12345",&uiResult) == ERROR) printf("OK\n"); else printf("Error\n");

    printf("Test 4 - "); // Weryfikacja poprawnej konwersji z formatu szesnastkowego na liczbę całkowitą
    if ((eHexStringToUInt("0xFDE8",&uiResult) == OK) && uiResult == 0xFDE8) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_AppendUIntToString(void) {
    char cDestinationStr1[15] = "Test";
    char cDestinationStr2[10] = "";
    unsigned int uiValue = 1;

    printf("AppendUIntToString test:\n");
    printf("Test 1 - "); // Sprawdzenie dołączania liczby do niepustego łańcucha
    AppendUIntToString(uiValue, cDestinationStr1);
    if (strcmp(cDestinationStr1, "Test0x0001") == 0) printf("OK\n"); else printf("Error\n");

    printf("Test 2 - "); // Sprawdzenie dołączania liczby do pustego łańcucha
    AppendUIntToString(uiValue, cDestinationStr2);
    if (strcmp(cDestinationStr2, "0x0001") == 0) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_ucFindTokensInString(void) {
    char cString1[] = "obowiązkowy 0x11 test";
    char cString2[] = "    ";
    char cString3[] = " obowiązkowy 0x11 test";
    char cString4[] = "obowiązkowy   0x11 test";


    printf("ucFindTokensInString test:\n");
    printf("Test 1 - "); // Weryfikacja poprawnego znajdowania i zliczania tokenów w standardowym łańcuchu
    ucTokenNr = ucFindTokensInString(cString1);
    if (ucTokenNr == 3 && (strcmp(asToken[0].uValue.pcString,"obowiązkowy 0x11 test") == 0) && (strcmp(asToken[1].uValue.pcString,"0x11 test") == 0) && (strcmp(asToken[2].uValue.pcString,"test") == 0)) printf("OK\n"); else printf("Error\n");
    printf("Test 2 - "); // Sprawdzenie działania funkcji dla łańcucha zawierającego tylko delimitery
    ucTokenNr = ucFindTokensInString(cString2);
    if (ucTokenNr == 0) printf("OK\n"); else printf("Error\n");

    printf("Test 3 - "); // Weryfikacja, czy funkcja radzi sobie z delimiterem na początku
    ucTokenNr = ucFindTokensInString(cString3);
    if (ucTokenNr == 3 && (strcmp(asToken[0].uValue.pcString,"obowiązkowy 0x11 test") == 0) && (strcmp(asToken[1].uValue.pcString,"0x11 test") == 0) && (strcmp(asToken[2].uValue.pcString,"test") == 0)) printf("OK\n"); else printf("Error\n");

    printf("Test 4 - "); // Testowanie funkcji dla wielu delimiterów między tokenami
    ucTokenNr = ucFindTokensInString(cString4);
    if (ucTokenNr == 3 && (strcmp(asToken[0].uValue.pcString,"obowiązkowy   0x11 test") == 0) && (strcmp(asToken[1].uValue.pcString,"0x11 test") == 0) && (strcmp(asToken[2].uValue.pcString,"test") == 0)) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_eStringToKeyword(void) {
    char cString1[] = "reset";
    char cString2[] = "ressett";
    enum KeywordCode eTest;

    printf("eStringToKeyword test:\n");
    printf("Test 1 - "); // Weryfikacja poprawnego mapowania łańcucha na odpowiednie słowo kluczowe enum
    if ((eStringToKeyword(cString1,&eTest) == OK) && eTest == RST) printf("OK\n"); else printf("Error\n");
    printf("Test 2 - "); // Sprawdzenie, czy funkcja poprawnie zgłasza błąd dla nierozpoznanego słowa
    if (eStringToKeyword(cString2,&eTest) == ERROR) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_DecodeTokens(void) {
    char cString[] = "reset 0x11 dom";

    ucTokenNr = ucFindTokensInString(cString);
    ReplaceCharactersInString(cString, DELIMITER_CHARACTER, '\0');

    DecodeTokens();

    printf("DecodeTokens test:\n");
    printf("Test 1 - "); // Weryfikacja, czy token STRING jest poprawnie zdekodowany
    if ((asToken[2].eType == STRING) && (asToken[2].uValue.pcString == &cString[11])) printf("OK\n"); else printf("Error\n");
    printf("Test 2 - "); // Weryfikacja, czy token KEYWORD jest poprawnie zdekodowany
    if ((asToken[0].eType == KEYWORD) && (asToken[0].uValue.eKeyword = RST)) printf("OK\n"); else printf("Error\n");

    printf("Test 3 - "); // Weryfikacja, czy token NUMBER jest poprawnie zdekodowany
    if ((asToken[1].eType == NUMBER) && (asToken[1].uValue.uiValue = 0x11)) printf("OK\n\n"); else printf("Error\n\n");
}

void TestOf_DecodeMsg(void) {
    char cStr[] = "reset 0x11 dom";
    
    printf("DecodeMsg test:\n");
    printf("Test - "); // Kompleksowy test dekodowania pełnej wiadomości: sprawdzenie wszystkich typów tokenów i ich wartości
    DecodeMsg(cStr);
    if ((asToken[2].eType == STRING) && (asToken[2].uValue.pcString = &cStr[11]) && (asToken[0].eType == KEYWORD) && (asToken[0].uValue.eKeyword = RST) && (asToken[1].eType == NUMBER) && (asToken[1].uValue.uiValue = 0x11)) printf("OK\n\n"); else printf("Error\n\n");
}
int main() {
    printf("TESTY FUNKCJI DO OPERACJI NA STRINGACH \n\n\n ");
    TestOf_CopyString();
    TestOf_eCompareString();
    TestOf_AppendString();
    TestOf_ReplaceCharactersInString();
    TestOf_UIntToHexStr();
    TestOf_eHexStringToUInt();
    TestOf_AppendUIntToString();

    printf("TESTY FUNKCJI DO DEKODOWANIA KOMUNIKATÓW\n\n\n ");
    TestOf_ucFindTokensInString();
    TestOf_eStringToKeyword();
    TestOf_DecodeTokens();
    TestOf_DecodeMsg();

    return 0;
}
