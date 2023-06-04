/*Course: SFT221 | Workshop: 4 | Professor: Robin Huang
Section: NEE | Student Name: Julia Alekseev | Student ID: 051292134
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_FACTORIALS 10000
#define NUM_FACTS 100

struct FactorialResults
{
  //int results[MAX_FACTORIALS];
  //updating for dynamic memory allocation 
    int* results;
    int numResults;
};

int factorial(const int n)
{
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

void computeFactorials(struct FactorialResults* results, int numFactorials)
{
    results->results = (int*)malloc(sizeof(int) * (numFactorials + 1)); // Allocate one extra element for the null terminator

    if (results->results == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < numFactorials; i++)
    {
        results->results[i] = factorial(i);
    }

    results->results[numFactorials] = 0; // Null terminate the buffer
    results->numResults = numFactorials;
}


//clearing unused memory
void freeFactorials(struct FactorialResults* results)
{
    free(results->results);
    results->results = NULL;
    results->numResults = 0;
}


int main() 
//main still has memory warnings:
//main finction uses 40047 bytes of stack. consider mioving some data to heap
{
    struct FactorialResults results;
    computeFactorials(&results, NUM_FACTS);

    int i;
    for (i = 0; i < results.numResults; i++)
    {
        printf("%4d\t%10d\n", i, results.results[i]);
    }

    freeFactorials(&results);

    return 0;
}
