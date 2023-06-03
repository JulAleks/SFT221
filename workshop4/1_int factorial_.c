/*Course: SFT221 | Workshop: 4 | Professor: Robin Huang
Section: NEE | Student Name: Julia Alekseev | Student ID: 051292134
*/
#include <stdio.h>
int factorial(const int n);

int main(void) {

//TEST 1, expected output 2, result no output, return (n <= n) ? n * factorial(n - 1) : 1;
//int x = factorial(2); --FAIL
//printf("%d", x);

//TEST 2 return (n <= 1) ? n * factorial(n - 1) : 1;
//expected output 2, restul is 1 -FAIL
//int x = factorial(2);
//printf("%d", x);

//TEST 3 return (n <= 1) ?  1: n * factorial(n - 1);
//expected output 2, restul is 2 - PASS
//int x = factorial(2);
//printf("%d", x);
  
//TEST 4, passing negative number, expected result is 1, result is 1 - PASS
int x = factorial(-2);
printf("%d", x);
  
  return 0;
}


int factorial(const int n)
{

//return (n <= n) ? n * factorial(n - 1) : 1;
 //1. n <= n, always returns true makes the condition statment useless
//return (n <= 1) ? n * factorial(n - 1) : 1;
//2. trying to replace n with 1, if n is maller than 1, and trying to run the function
//using a printf statment and n=2, expecting a result of 2.
// a result of 1 was generated. Procedding to analyze the consition. 
//if n is bigger than 1, the execution should be 2! = 2 × 1 = 2
// we can see that the second condition is executed, return 1, the calculation is not done.
// if a number is lower than or equal to 1, the return should be 1, and if it is bigger that it should multiply itself by iteslf -1 
return (n <= 1) ?  1: n * factorial(n - 1);
// by chnaging the condition and the oparations we now know that this function is preforming as expected 
}