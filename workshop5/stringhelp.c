/*Course: SFT221 | Workshop: 4 | Professor: Robin Huang
Section: NEE | Student Name: Julia Alekseev | Student ID: 051292134
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>

//int nextWhite(const char* str)
int nextWhite(const char* str, int start) {
    /*int i, result = -1;
    for (i = 0; result < 0 && str[i] != '\0'; i++)
    {
    if (isspace(str[i]))
    {
    result = i;
    }
    }
    return (result < 0) ? i : result;*/
    //suposed to returns the index of the next white space or the position of the string terminator.
    //Looking throught the debugger the return values were off, this way the function returns the proper index
    int i = start;
    while (str[i] != '\0' && !isspace(str[i]))
    {
        i++;
    }
    return i;
}

int isNumber(const char* str, const int len) {
    int i, result = 1;;
    
    /*for (i = 0; i < len && result; i++)
        {
       result = result && isdigit(str[i]);
        }
        return result;*/
    //Return true if the string contains only digits.
    //in the version above does not return boolean and check properly the values
    for (i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            result = 0; 
        }
    }
    return result;
}

struct StringIndex indexString(const char* str) {
    struct StringIndex result = { {0}, {0}, {0}, 0, 0, 0 };
    int i = 0, sp;
    strcpy(result.str, str);
    if (str[0] != '\0') {
        result.lineStarts[0] = 0;
        result.numLines = 1;
    }
    /*for (i = 0; str[i] != '\0'; i++)
    {
    while (str[i] != '\0' && isspace(str[i]))
        {
    if (str[i] == '\n')
    {
    result.lineStarts[result.numLines] = i + 1;
    }
    i++;
    }
    sp = nextWhite(str + i);
    if (isNumber(str + i, sp - i + 1))
    {
    result.numberStarts[result.numNumbers++] = i;
    }
    else
    {
    result.wordStarts[result.numWords++] = i;
    }*/

    //build an index for a string showing the start of the lines,words, and numbers in the string.
   //the modification of the code lets us iterate throug the array until we his a null terminator, 
    //exemin then if there is a space at the specific loctaion andd and if there is assing the linestarts with the 
    //itaration plus 1, if then nextWhite will return the index of the white spot.
    //checking then if the position contains a numebr if so assign the position if not assign it to words and return the result 
    //the modifuication improves accurately handling the loop condition, ensuring proper termination of the loop when reaching 
    //the end of the string, and providing correct index assignments for lines, words, and numbers within the input string

    while (str[i] != '\0') {
        while (isspace(str[i])) {
            if (str[i] == '\n') {
                result.lineStarts[result.numLines] = i + 1;
            }
            i++;
        }
        sp = nextWhite(str, i);
        if (isNumber(str + i, sp - i)) {
            result.numberStarts[result.numNumbers++] = i;
        }
        else {
            result.wordStarts[result.numWords++] = i;
        }
        i = sp;
    }
    return result;
}

int getNumberLines(const struct StringIndex* idx) {
    return idx->numLines;
}

int getNumberWords(const struct StringIndex* idx) {
    return idx->numWords;
}

int getNumberNumbers(const struct StringIndex* idx) {
    return idx->numNumbers;
}

void getWord(char word[], const struct StringIndex* idx, int wordNum) {
    int i, sp, start;
    word[0] = '\0';
    if (wordNum < idx->numWords && wordNum >= 0) {  
        start = idx->wordStarts[wordNum];
        // sp = nextWhite(idx->str + start);
        //after changing the passing parameters of nextWhite, start would be passed as a parameter 
        sp = nextWhite(idx->str, start);
        for (i = 0; i < sp; i++) {
            word[i] = idx->str[i];
        }
        word[sp] = '\0';
        ((struct StringIndex*)idx)->numWords--;
    }
}

void getNumber(char word[], const struct StringIndex* idx, int numberNum) {
    int i, sp, start;
    word[0] = '\0';
    if (numberNum < idx->numNumbers && numberNum >= 0) {
        start = idx->numberStarts[numberNum];
        sp = nextWhite(idx->str, start);
        //sp = nextWhite(idx->str + start);
        //after changing the passing parameters of nextWhite, start would be passed as a parameter 
        for (i = 0; i < sp - start; i++) {
            word[i] = idx->str[start + i];
        }
        word[sp - start] = '\0';
    }
}

char* getLine(struct StringIndex* idx, int lineNum)
{
    char* result = NULL;
    if (lineNum < idx->numLines && lineNum >= 0)
    {
        result = idx->str + idx->lineStarts[lineNum];
    }
    return result;
}

void printUntil(const char* s, const int start, const char terminator)
{
    int i;
    for (i = start; s[i] != '\0' && s[i] != terminator; i++)
        printf("%c", s[i]);
}

void printUntilSpace(const char* s, const int start)
{
    int i;
    for (i = start; s[i] != '\0' && !isspace(s[i]); i++)
        printf("%c", s[i]);
}