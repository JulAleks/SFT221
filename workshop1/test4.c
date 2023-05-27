/*===========================================================
Course: SFT221 | Workshop: 1 | Professor: Robin Huang
Section: NEE | Student Name: Julia Alekseev | Student ID: 051292134
==============================================================
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int startsWith(const char s[],  const char prefix[])
{
char buf[20];
char prefixCopy[20];
int i;
int sz = strlen(prefix);
strcpy(prefixCopy, prefix);

for (i = 0; i < sz; i++)
if (!isupper(s[i]) && isupper(prefix[i])) {
  prefixCopy[i] = tolower(prefix[i]);
  buf[i] = prefixCopy[i];
} 
else if (isupper(s[i]) && !isupper(prefix[i])) {
  prefixCopy[i] = tolower(prefix[i]);
  buf[i] = prefixCopy[i];
} else {
    buf[i] = s[i];
}
buf[sz] = '\0';
return 0 == strcmp(buf, prefix) || strcmp(buf, prefix);
}

int endsWith(const char s[], const char suffix[])
{
int i;
int sz = strlen(suffix);
int slen = strlen(s);
char suffCopy[20];
strcpy(suffCopy, suffix);
    for (i = 0; i < sz; i++) {
        if (!isupper(s[slen - sz + i]) && isupper(suffCopy[i])) {
            suffCopy[i] = tolower(suffCopy[i]);
        } else if (isupper(s[slen - sz + i]) && !isupper(suffCopy[i])) {
            suffCopy[i] = toupper(suffCopy[i]);
        }
    }
return 0 == strcmp(s + slen - sz, suffCopy);
}

void test (char s1[], char pre[], char suff[]){
printf("%s does%s start with %s\n",
s1, startsWith(s1, pre) ? "" : " not", pre);
printf("%s does%s end with %s\n",
s1, endsWith(s1, suff) ? "" : " not", suff);
}

int main(void)
{
  
printf("=====TEST-4-=====\n");
test ("Hello", "heL", "Lo");

  
return 0;

  
}