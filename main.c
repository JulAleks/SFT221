#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Determine if the string s starts with the string prefix.
 * @param s - the string to see if it starts with prefix
 * @param prefix - the prefix to test
 * @returns true if the strings begins with the prefix.
 */
int startsWith(const char s[], const char prefix[]) {

    int i;
    int sz = strlen(prefix);

    char* buf = (char*)malloc((strlen(prefix) + 1) * sizeof(char));
    if (buf == NULL) {
        return 0;
    }

    char* preFixCopy = (char*)malloc((strlen(prefix) + 1) * sizeof(char));
    if (preFixCopy == NULL) {
        free(preFixCopy);
        return 0;
    }

    if (prefix[0] == ' ') {
        for (i = 0; i < sz - 1; i++) {
            preFixCopy[i] = prefix[i + 1];
        }
        preFixCopy[sz - 1] = '\0';
        sz--;
    }
    else {
        strcpy(preFixCopy, prefix);
    }
    if (preFixCopy[sz - 1] == ' ') {
        while (preFixCopy[sz - 1] == ' ') {
            sz--;
        }
        preFixCopy[sz] = '\0';
    }

    for (i = 0; i < sz; i++) {
        buf[i] = s[i];
    }
    buf[sz] = '\0';
    int result = (strcmp(buf, preFixCopy) == 0);
    free(buf);
    free(preFixCopy);
    return result;
}
/**
 * Determine if the string s ends with the string suffix.
 * @param s - the string to see if it ends with suffix
 * @param suffix - the suffix to test
 * @returns true if the strings ends with the suffix.
 */
int endsWith(const char s[], const char suffix[]) {
    int sLen = strlen(s);
    int suffLen = strlen(suffix);

    if (suffix[suffLen - 1] == ' ') {
        suffLen--;
    }
    if (s[sLen - 1] == ' ') {
        sLen--;
    }
    return 0 == strncmp(s + (sLen - suffLen), suffix, suffLen);
}

//testing function//
void test(char s1[], char pre[], char suff[]) {
    printf("%s does%s start with %s\n", s1, startsWith(s1, pre) ? "" : " not",
        pre);
    printf("%s does%s end with %s\n", s1, endsWith(s1, suff) ? "" : " not", suff);
}

int main(void) {

    printf("=====TEST-1-=====\n");
    test("upended", "up", "ed");

    printf("\n=====TEST-2-=====\n");
    test("Photosynthesis", "Photo", "sis");

    printf("\n=====TEST-3-=====\n");
    test("Photosynthesis", "photo", "sis");

    printf("\n=====TEST-5-=====\n");
    test("pseudopseudohypoparathyroidism", "pseudopseudohypoparathyroi", "dism");

    printf("\n=====TEST-6-=====\n");
    test("pseudopseudohypoparathyroidism", "pseudo", "pseudohypoparathyroidism");

    printf("\n=====TEST-7-=====\n");
    test("Seneca College", "Seneca", "College ");

    printf("\n=====TEST-8-=====\n");
    test("black dogs", " black", "dogs ");

    printf("\n=====TEST-9-=====\n");
    test("cherry", " che ", "rry ");
    return 0;
}