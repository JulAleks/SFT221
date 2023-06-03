/*Course: SFT221 | Workshop: 4 | Professor: Robin Huang
Section: NEE | Student Name: Julia Alekseev | Student ID: 051292134
*/
#include <stdio.h>
int factorial(const int n);
int reduceFactorial(const int n);
int main(void) {

//TEST 1 white box as seeing the code return n / n, passing 4, expecting to recieve 1 
// result 1, pass
//int x =reduceFactorial(4);
//printf("%d", x);

//TEST 2 
//printf("%d", reduceFactorial(40000000000000000000000)); 
//trying to pass a long long int to see how the program would hand it, because with factorials, very long numbers can be genarated. 
//Error: implicit conversion from 'unsigned long long' to 'int' changes value from 7458848197692096512 to -922746880


//TEST 3 examining the name,  reduceFactorial, any number dividing by iteslf will result in 1, no reduction is actually being done here
//updated reduceFactorial(const int n) is tested, passed 4 and returned 4. Although it seems like the same output is achieved with factorial and reduceFactorial. Something to consider after checking other parts of the code
printf("%d", reduceFactorial(4));
printf("%d", factorial(4)); 

  
  return 0;
}


int factorial(const int n)
{
	return (n <= 1) ? 1 : n * factorial(n - 1);
}

int reduceFactorial(const int n)
{
// return n / n;
//The formula for factorial reduction is (n+1)! = n! * (n+1), not n/n
int result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}