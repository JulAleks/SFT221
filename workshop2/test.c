#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STRING_LEN 25
#define MAX_PRODUCTS 10
#define MAX_CART 10
#define TAX_RATE 0.13

struct Cart
{
    int items[MAX_CART];
    int nItems;
};

// Function prototypes
int findString(const char str[], const char list[][MAX_STRING_LEN + 1], const int nstrings);
int add2Cart(struct Cart* cart, const int item);

int main(void)
{
    // Set up test data
    struct Cart cart = { {0}, 0 };
    double prices[MAX_PRODUCTS] = { 1.99, 2.48, 4.56, 3.47, 6.99, 2.99 };
    char descriptions[][MAX_STRING_LEN + 1] =
    {
        "flour",
        "sugar",
        "bananas",
        "potatoes",
        "milk",
        "tea"
    };
    char productName[MAX_STRING_LEN + 1] = { 0 };

    // Set up test case
    strcpy(productName, "potatoes");  // Valid product name to add
    int expectedItem = 3;  // Expected index of the item in descriptions array

    
    int foundItem = findString(productName, descriptions, MAX_PRODUCTS);
    int addResult = add2Cart(&cart, foundItem);

    // Compare the result to the expected outcome
    if (foundItem == expectedItem && addResult == 0)
    {
        printf("Integration test passed!\n");
      
    }
    else
    {
        printf("Integration test failed.\n");
        
    }

    return 0;
}





/*
* Find the position of a string in an array of strings.
* @param str - the string to find
* @param list - the list of strings to search
* @param nstrings - the number of strings in the list
* @returns the position of the string in the list or -1 if not found
*/
int findString(const char str[], const char list[][MAX_STRING_LEN + 1], const int nstrings)
{
    int i, result = -1, found = 0;
    for (i = 0; i < nstrings && !found; i++)
    {
        if (0 == strcmp(str, list[i]))
        {
            result = i;
        }
    }
    return result;
}

int add2Cart(struct Cart* cart, const int item)
{
    int result = 0;

    if (cart->nItems >= MAX_CART)
    {
        result = -1;
    }
    else
    {
        if (item >= 0 && item < MAX_PRODUCTS)
        {
            cart->items[cart->nItems] = item;
            cart->nItems++;
        }
        else
        {
            result = -2;
        }
    }
    return result;
}