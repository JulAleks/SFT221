/*Course: SFT221 | Workshop: 4 | Professor: Robin Huang
Section: NEE | Student Name: Julia Alekseev | Student ID: 051292134
*/
#include <stdio.h>

#define MAX_FACTORIALS 10000
#define NUM_FACTS 100

struct FactorialResults {
  int results[MAX_FACTORIALS];
  int numResults;
};

int factorial(const int n);
int reduceFactorial(const int n);
void computeFactorials(struct FactorialResults results, const int numFactorials); 
int main(void) {
  struct FactorialResults results = {{0}, 0};
  // Test 1 == passing 2, factorial of 2 is 2, test fails, the logic is wrong
  /*
     int i;
     int numFactorials = 2;

     for (i = 0; i < numFactorials; i++)
     {
         results.results[i] = factorial(i);
     }

     if (results.numResults == numFactorials)
     {
         printf("True\n");
     }
     else
     {
         printf("False\n");
     }*/

  // Test 2 == updated code
  /*int i, limit;
   int numFactorials = 2;
  if (numFactorials < MAX_FACTORIALS) {
    limit = numFactorials;
  } else {
    limit = MAX_FACTORIALS;
  }

  for (i = 0; i < limit; i++) {
    results.results[i] = factorial(i);
  }


  //passing 2 expecting 2, passes

  results.numResults = limit;
  printf("%d", results.numResults);*/

  // TEST 2, B
  /*int i, limit;
   int numFactorials = 9;
  if (numFactorials < MAX_FACTORIALS) {
    limit = numFactorials;
  } else {
    limit = MAX_FACTORIALS;
  }

  for (i = 0; i < limit; i++) {
    results.results[i] = factorial(i);
  }
  //passing 9, expecting 9, passes

  results.numResults = limit;
  printf("%d", results.numResults);*/

  // TEST 3 passing 999999999, expecting 1000, passes
  /*int i, limit;
   int numFactorials = 999999999;
  if (numFactorials < MAX_FACTORIALS) {
    limit = numFactorials;
  } else {
    limit = MAX_FACTORIALS;
  }

  for (i = 0; i < limit; i++) {
    results.results[i] = factorial(i);
  }


  results.numResults = limit;
  printf("%d", results.numResults);*/

  // updating to a shorter version of the same if else condiotion
  // TEST 4 passing 999999999, expecting 1000, passes
  /*int i;
   int numFactorials = 999999999;
  int limit = (numFactorials < MAX_FACTORIALS) ? numFactorials : MAX_FACTORIALS;
  //passing 1000, expecting 1000, passes
  results.numResults = limit;
  printf("%d", results.numResults);*/

  // TEST 5 with updated code
  /* int i;
  int numFactorials = 9;
 int limit = (numFactorials < MAX_FACTORIALS) ? numFactorials : MAX_FACTORIALS;
 //passing 9, expecting 9, passes
 results.numResults = limit;
 printf("%d", results.numResults);*/
  // ready to be implamented in the function


  

  return 0;
}

int factorial(const int n) { return (n <= 1) ? 1 : n * factorial(n - 1); }

int reduceFactorial(const int n) {
  int result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  return result;
}

void computeFactorials(struct FactorialResults results, const int numFactorials)
{
    int i;
    int limit = (numFactorials < MAX_FACTORIALS) ? numFactorials : MAX_FACTORIALS;
    for (i = 0; i < limit; i++)
    {
        results.results[i] = factorial(i);
    }
    results.numResults = limit;
}