#include <stdio.h>
#include <string.h>
#include <stddef.h> 
#include "stringi.h"
#include "konwersje.h"
#include "dekodowanie.h"

void TestOf_CopyString(void) {
    char cString1[] = "Compare String Test";
    char cString2[20] = "";

    printf("CopyString test:\n");
    printf("Test - "); // Sprawdzenie poprawnosci skopiowania lancucha
    CopyString(cString1, cString2);
    if(strcmp(cString2, cString1) == 0){
        printf("OK\n\n");
    }
    else{
        printf("Error\n\n");
    }
}

void TestOf_eCompareString(void) {
    char cString1[] = "test funckji ";
    char cStringShort[] = "test";
    char cStringLonger[] = "test funkcji eCompare";
    char cDifferentString[] = "Inny lancuch";


    printf("eCompareString test:\n");
    printf("Test 1 - "); // Sprawdzenie porównania identycznych łańcuchów
    if (eCompareString(cString1, cString1) == EQUAL){
        printf("OK\n");
    }
    else{
        printf("Error\n");
    }
    printf("Test 2 - "); // Sprawdzenie porownania dla dluzszego lancucha
    if (eCompareString(cString1, cStringLonger) == DIFFERENT){
        printf("OK\n");
    }
    else{
        printf("Error\n");
    }
    printf("Test 3 - "); // Sprawdzenie porownania dla krotszego lancucha
    if (eCompareString(cString1, cStringShort) == DIFFERENT){
        printf("OK\n"); 
    }
    else{
        printf("Error\n");
    }
    printf("Test 4 - "); // Sprawdzenie porownania dla zupelnie roznych lancuchow
    if ((strcmp(cString1, cDifferentString) != 0) && (eCompareString(cString1, cDifferentString) == DIFFERENT)){ 
        printf("OK\n\n");
    }
    else{
        printf("Error\n\n");
    }
}

void TestOf_AppendString(void) {
    char cTestDest1[20] = "lancuch1";
    char cTestSrc1[] = "lancuch2";

    char cTestDest2[15] = "";
    char cTestSrc2[] = "NiepustyLancuch";

    char cTestDest3[20] = "lancuch";
    char cTestSrc3[] = "";

    char cTestDest4[30] = "test";
    char cTestSrc4[] = "dodawania";


    printf("Testy funkcji AppendString:\n");
    printf("Test 1 - "); // dodanie dwoch niepustych lancuchow
    AppendString(cTestSrc1, cTestDest1);
    if (strcmp(cTestDest1, "lancuch1lancuch2") == 0){ 
        printf("OK\n"); 
    }
    else{ 
        printf("Error\n");
    }
    printf("Test 2 - "); // dodanie niepustego lancucha do pustego
    AppendString(cTestSrc2, cTestDest2);

    if (strcmp(cTestDest2, "NiepustyLancuch") == 0){ 
        printf("OK\n"); 
    }
    else{ 
        printf("Error\n");
    }
    printf("Test 3 - "); // dodanie pustego lancucha do niepustego
    AppendString(cTestSrc3, cTestDest3);

    if (strcmp(cTestDest3, "lancuch") == 0){ 
        printf("OK\n");
    } 
    else{ 
        printf("Error\n");
    }
    printf("Test 4 - "); // test ogolny
    AppendString(cTestSrc4, cTestDest4);

    if (strcmp(cTestDest4, "testdodawania") == 0){ 
        printf("OK\n"); 
    }
    else{ 
        printf("Error\n");
    }
}

void TestOf_ReplaceCharactersInString(void) {
    char cOldChar = 'r';
    char cNewChar = 'g';
    char cNewString[] = "Character replacement";

    printf("ReplaceCharactersInString test:\n");
    printf("Test - "); // Sprawdzenie, czy funkcja poprawnie zamienia wszystkie wystapienia znaku
    ReplaceCharactersInString(cNewString, cOldChar, cNewChar);
    if (strcmp(cNewString, "Chagacteg geplacement") == 0){
        printf("OK\n\n"); 
    }
    else{ 
        printf("Error\n\n");
    }
}

void TestOf_UIntToHexStr(void) {
    char cString[7];

    printf("UIntToHexStr test:\n");
    printf("Test 1 - "); // Sprawdzenie konwersji wartości dziesiętnej na hekasdecymalna
    UIntToHexStr(37039, cString); //37039 = 0x90AF
    if (strcmp(cString, "0x90AF") == 0){ 
        printf("OK\n"); 
    }
    else{
        printf("Error\n");
    }
}

void TestOf_eHexStringToUInt(void) {
    
    unsigned int uiTestResult;

    printf("eHexStringToUInt test:\n");
    printf("Test 1 - "); // wykrycie niepoprawnego formatu (brak "0x")
    if (eHexStringToUInt("test",&uiTestResult) == ERROR){
        printf("OK\n");
    }
    else{
        printf("Error\n");
    }
    printf("Test 2 - "); // wykrycie za krotkiego lancucha("0x" bez cyfr)
    if (eHexStringToUInt("0x",&uiTestResult) == ERROR){
        printf("OK\n");
    }
    else{
        printf("Error\n");
    }
    printf("Test 3 - "); // wykrycie za dlugiego lancucha(przekroczenie limitu 4 cyfr HEX)
    if (eHexStringToUInt("0x12345",&uiTestResult) == ERROR){
        printf("OK\n");
    }
    else{
        printf("Error\n");
    }
    printf("Test 4 - "); // Weryfikacja poprawnej konwersji z formatu hex na liczbe calkowita
    if ((eHexStringToUInt("0xFDE8",&uiTestResult) == OK) && uiTestResult == 0xFDE8){
        printf("OK\n\n");
    }
    else{
        printf("Error\n\n");
    }
}

void TestOf_AppendUIntToString(void) {
    char cDestinationStr1[20] = "AppendTest";
    char cDestinationStr2[10] = "";
    unsigned int uiValue = 1;

    printf("AppendUIntToString test:\n");
    printf("Test 1 - "); // test dolaczania hexa do niepustego lancucha
    AppendUIntToString(uiValue, cDestinationStr1);
    if (strcmp(cDestinationStr1, "AppendTest0x0001") == 0){
        printf("OK\n");
    }
    else{
        printf("Error\n");
    }

    printf("Test 2 - "); // test dolaczenie hexa do pustego lancucha
    AppendUIntToString(uiValue, cDestinationStr2);
    if (strcmp(cDestinationStr2, "0x0001") == 0){
        printf("OK\n\n");
    }
    else{
        printf("Error\n\n");
    }
}

void TestOf_ucFindTokensInString(void) {
    char cString1[] = "function 0x1A test";
    char cString2[] = "    ";
    char cString3[] = " function 0x1A test";
    char cString4[] = "function   0x1A test";


    printf("ucFindTokensInString test:\n");
    printf("Test 1 - "); // Weryfikacja poprawnego znajdowania i zliczania tokenów w standardowym łańcuchu
    ucTokenNr = ucFindTokensInString(cString1);
    if (ucTokenNr == 3 && (strcmp(asToken[0].uValue.pcString,"function 0x1A test") == 0) && (strcmp(asToken[1].uValue.pcString,"0x1A test") == 0) && (strcmp(asToken[2].uValue.pcString,"test") == 0)){
        printf("OK\n"); 
    }
    else{
        printf("Error\n");
    }
    printf("Test 2 - "); // Sprawdzenie działania funkcji dla łańcucha zawierającego tylko delimitery
    ucTokenNr = ucFindTokensInString(cString2);
    if (ucTokenNr == 0) printf("OK\n"); else printf("Error\n");

    printf("Test 3 - "); // Weryfikacja, czy funkcja radzi sobie z delimiterem na początku
    ucTokenNr = ucFindTokensInString(cString3);
    if (ucTokenNr == 3 && (strcmp(asToken[0].uValue.pcString,"function 0x1A test") == 0) && (strcmp(asToken[1].uValue.pcString,"0x1A test") == 0) && (strcmp(asToken[2].uValue.pcString,"test") == 0)){
        printf("OK\n");
    }
    else{
        printf("Error\n");
    }
    printf("Test 4 - "); // Testowanie funkcji dla wielu delimiterów między tokenami
    ucTokenNr = ucFindTokensInString(cString4);
    if (ucTokenNr == 3 && (strcmp(asToken[0].uValue.pcString,"function   0x1A test") == 0) && (strcmp(asToken[1].uValue.pcString,"0x1A test") == 0) && (strcmp(asToken[2].uValue.pcString,"test") == 0)){
        printf("OK\n\n");
    } 
    else{
    printf("Error\n\n");
    }
}

void TestOf_eStringToKeyword(void) {
    char cString1[] = "store";
    char cString2[] = "sttorre";
    enum KeywordCode eTest;

    printf("eStringToKeyword test:\n");
    printf("Test 1 - "); // Sprawdzenie poprawnego mapowania łańcucha na odpowiednie słowo kluczowe enum
    if ((eStringToKeyword(cString1,&eTest) == OK) && eTest == ST){
        printf("OK\n");
    }
    else{ 
        printf("Error\n");
    }
    printf("Test 2 - "); // Sprawdzenie zgloszenia bledu dla nierozpoznania słowa
    if (eStringToKeyword(cString2,&eTest) == ERROR){
        printf("OK\n\n"); 
    }
    else{
        printf("Error\n\n");
    }
}

void TestOf_DecodeTokens(void) {
    char cString[] = "reset 0x1A cos";

    ucTokenNr = ucFindTokensInString(cString);
    ReplaceCharactersInString(cString, ' ', '\0');

    DecodeTokens();

    printf("DecodeTokens test:\n");
    printf("Test 1 - "); // Weryfikacja, czy token STRING jest poprawnie zdekodowany
    if ((asToken[2].eType == STRING) && (asToken[2].uValue.pcString == "cos")){
        printf("OK\n");
    } 
    else{
        printf("Error\n");
    }
    //printf("Expected address: %p\n", (void*)&cString[11]);
    //printf("Actual address:   %p\n", (void*)asToken[2].uValue.pcString);
    //printf("Token count: %d\n", ucTokenNr);
    //printf("%c\n", cString[11]);
    printf("Test 2 - "); // Weryfikacja, czy token KEYWORD jest poprawnie zdekodowany
    if ((asToken[0].eType == KEYWORD) && (asToken[0].uValue.eKeyword = RST)){
        printf("OK\n"); 
    }
    else{
        printf("Error\n");
    }
    printf("Test 3 - "); // Weryfikacja, czy token NUMBER jest poprawnie zdekodowany
    if ((asToken[1].eType == NUMBER) && (asToken[1].uValue.uiValue = 0x1A)){
        printf("OK\n\n"); 
    }
    else{
        printf("Error\n\n");
    }
}

void TestOf_DecodeMsg(void) {
    char cStr[] = "reset 0x1A test";
    
    printf("DecodeMsg test:\n");
    printf("Test - "); // Ogolny test dekodowania wiadomosci 
    DecodeMsg(cStr);
    if ((asToken[2].eType == STRING) && (asToken[2].uValue.pcString = &cStr[11]) && (asToken[0].eType == KEYWORD) && (asToken[0].uValue.eKeyword = RST) && (asToken[1].eType == NUMBER) && (asToken[1].uValue.uiValue = 0x1A)){
        printf("OK\n\n");
    }
    else{
        printf("Error\n\n");
    }
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
    
    if ((asToken[2].eType == STRING) && (eCompareString(asToken[2].uValue.pcString, "test") == EQUAL)) {
        printf("OK\n");
    } 
    else {
        printf("Error\n");
    }
    //printf("Token[2] type: %d (expected STRING = %d)\n", asToken[2].eType, STRING);
    

    return 0;
}
