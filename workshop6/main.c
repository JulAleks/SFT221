/**************************************************************************
Course: SFT221 | Workshop: 6 | Professor: Robin Huang
Section: NEE | Student Name: Julia Alekseev | Student ID: 051292134
***************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "stringhelp.h"
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "log4c.h"
int main(void)
{

	char errMsg[L4C_ERROR_MSG_MAX + 1] = { 0 };
	struct Log4cStruct log = l4cOpen("logW6.txt", 1);//1 to keep records insted of 0
	if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);
	else
	{

	/*char testStr[] = { "This is a\n string with embedded newline characters and \n12345 numbers inside it as well 7890" };*/
	char testStr[] =  "This is a\n string with embedded newline characters and \n12345 numbers inside it as well 7890" ; //removing curly braces
	struct StringIndex index = indexString(testStr);
	int i;

	//===========================Log lines========================================================================
	l4cInfo(&log, "LINES");
	if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);
	printf("LINES\n");


	char printedOutput[1000] = ""; // Initialize to an empty string

	for (i = 0; i < index.numLines; i++) {
		//printUntil(index.str, index.lineStarts[i], '\n');
		printUntil(index.str, index.lineStarts[i], '\0');
		printf("\n");
		strcat(printedOutput, index.str + index.lineStarts[i]);
	}
	assert(strcmp(printedOutput, testStr) == 0); // Compare printed output with expected line
	//warning, error printing the line
	//l4cWarning(&log, "ERROR PRINTING THE LINES");
	//if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);

	//============================ Log words=====================================================================
	l4cInfo(&log, "WORDS");
	if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);
	printf("\nWORDS\n");
	int matchFoundW = 0; // Initialize the matchFoundW flag outside the loop

	for (i = 0; i < index.numWords; i++) {
		char printedWords[1000] = ""; // Initialize a temporary buffer for the printed words

		printUntilSpace(index.str, index.wordStarts[i]);
		printf("\n");

		// Extract the printed words from the input string
		int expectedWordLength = strcspn(index.str + index.wordStarts[i], " \n");
		strncpy(printedWords, index.str + index.wordStarts[i], expectedWordLength);
		printedWords[expectedWordLength] = '\0';

		// Define the expected words for comparison
		char* expectedWords[] = { "This", "is", "a", "string", "with", "embedded", "newline", "characters", "and", "numbers", "inside", "it", "as", "well" };
		int numExpectedWords = sizeof(expectedWords) / sizeof(expectedWords[0]);

		// Compare printed words with each expected word
		int matchFoundWords = 0;

		for (int j = 0; j < numExpectedWords; j++) {
			if (strcmp(printedWords, expectedWords[j]) == 0) {
				matchFoundWords = 1;
				j= numExpectedWords;
			}
		}
		matchFoundW |= matchFoundWords; // Set matchFoundW to 1 if matchFoundWords is 1
	}
	assert(matchFoundW); // Assert that a match was found at least once


	//============================== Log numbers====================================================================
	l4cInfo(&log, "NUMBERS");
	if (l4cCheck(&log, errMsg)) printf("%s\n", errMsg);
	printf("\nNUMBERS\n");


	int matchFound = 0;
	for (i = 0; i < index.numNumbers; i++) {
		char printedNumber[1000] = ""; // Initialize a temporary buffer for the printed number

		printUntilSpace(index.str, index.numberStarts[i]);
		printf("\n");

		// Extract the printed number from the input string
		int expectedNumberLength = strcspn(index.str + index.numberStarts[i], " \n");
		strncpy(printedNumber, index.str + index.numberStarts[i], expectedNumberLength);
		printedNumber[expectedNumberLength] = '\0';

		// Define the expected numbers for comparison
		char* expectedNumbers[] = { "12345", "7890" };
		int numExpectedNumbers = sizeof(expectedNumbers) / sizeof(expectedNumbers[0]);

		// Compare printed number with each expected number
		int currentMatch = 0;
		for (int j = 0; j < numExpectedNumbers; j++) {
			if (strcmp(printedNumber, expectedNumbers[j]) == 0) {
				currentMatch = 1;
				j= numExpectedNumbers;
			}
		}
		matchFound |= currentMatch; // Set matchFound to 1 if currentMatch is 1
	}
	assert(matchFound); // Assert that a match was found at least once


	l4cClose(&log);
	}

	return 0;
	}
