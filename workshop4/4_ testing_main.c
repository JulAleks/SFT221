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
void computeFactorials(struct FactorialResults* results, const int numFactorials); 


int main(void) {
  struct FactorialResults results = {{0}, 0};

  //testing main = exit code Warning C6262 for both main and computeFactorials
  //updating computeFactorials to recieve a pointer and pass an address to prevent passing the whole struct for better memory usage
/*    computeFactorials(&results, NUM_FACTS);

    int i;
    for (i = 0; i < results.numResults; i++)
    {
        printf("%4d\t%10d\n", i, results.results[i]);
    }*/

//still result not as expected. Revisiting back the computeFactorials(struct FactorialResults* results, const int numFactorials)
//updating back to the original code and testing again  
/*   computeFactorials(&results, NUM_FACTS);

    int i;
    for (i = 0; i < results.numResults; i++)
    {
        printf("%4d\t%10d\n", i, results.results[i]);
    }*/
//restuls as expected. Trying again with a diffrent number, passes 
computeFactorials(&results, 10);

    int i;
    for (i = 0; i < results.numResults; i++)
    {
        printf("%4d\t%10d\n", i, results.results[i]);
    }

  //as suspected reduceFactorial(const int n) function is not needed in the code
  
  return 0;
}



int factorial(const int n) { return (n <= 1) ? 1 : n * factorial(n - 1); }

/*int reduceFactorial(const int n) {
    int result = 1;
    int i;
    for (i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}*/

void computeFactorials(struct FactorialResults* results, const int numFactorials)
{
int i;
for (i = 0; i < numFactorials; i++)
{
results->results[i] = factorial(i);
}
results->numResults = numFactorials;
}