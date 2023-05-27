/*Course: SFT221 | Workshop: 1 | Professor: Robin Huang
Section: NEE | Student Name: Julia Alekseev | Student ID: 051292134
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include "customer.h"

int isValid(char* tempPostal) {
    size_t length = strlen(tempPostal);
    int isValidPostal = 0;

    if (length == 6) {
        if (isalpha(tempPostal[0]) && isdigit(tempPostal[1]) && isalpha(tempPostal[2]) &&
            isdigit(tempPostal[3]) && isalpha(tempPostal[4]) && isdigit(tempPostal[5])) {
            return 1;
            for (int i = 0; i < length; i++) {
                tempPostal[i] = toupper(tempPostal[i]); 
            }
            tempPostal[7] = '\0';

        }
    }
    else if (length == 7) {
        if (isalpha(tempPostal[0]) && isdigit(tempPostal[1]) && isalpha(tempPostal[2]) &&
            tempPostal[3] == ' ' && isdigit(tempPostal[4]) && isalpha(tempPostal[5]) &&
            isdigit(tempPostal[6])) {
            return 1;
            for (int i = 0; i < length; i++) {
                tempPostal[i] = toupper(tempPostal[i]); 
            }
            tempPostal[8] = '\0';
        }
    }
    return 0;
}

int checkString(char* string) {
    size_t inputLength = strlen(string);
    if (inputLength > 1 && string[0] != '\n') {
        return 1; 
    }else if (inputLength == 1 && string[0] == '\n') {
        return 0;
        }
    else {
        return 0; 
    }
}



void setData(struct Customer* customer) {
    
    int validFname = 0;
    do {
        char input[80];
        printf("Enter your first name: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check= checkString(input);
        size_t inputLength = strlen(input);
        if (!check){
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->firstName, input, sizeof(customer->firstName) - 1);
            validFname = 1;
        }
    } while (!validFname);


    int validLname = 0;
    do {
        char input[80];
        printf("Enter your last name: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkString(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->lastName, input, sizeof(customer->lastName) - 1);
            validLname = 1;
        }
    } while (!validLname);


    int validStreet = 0;
    do {
        char input[80];
        printf("Enter your street address: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkString(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->streetAddress, input, sizeof(customer->streetAddress) - 1);
            validStreet = 1;
        }
    } while (!validStreet);
  
  
    int validCity = 0;
    do {
        char input[80];
        printf("Enter your city: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkString(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->city, input, sizeof(customer->city) - 1);
            validCity = 1;
        }
    } while (!validCity);

    int validProvince = 0;
    do {
        char input[80];
        printf("Enter your province: ");
        fgets(input, sizeof(input), stdin);
        int check = 0;
        check = checkString(input);
        size_t inputLength = strlen(input);
        if (!check) {
            printf("Invalid Entry: ");
        }
        else {
            input[inputLength - 1] = '\0';
            strncpy(customer->province, input, sizeof(customer->province) - 1);
            validProvince = 1;
        }
    } while (!validProvince);


    char tempPostal[10];
    int validPostal = 0;

    do {
        printf("Enter your postal code: ");
        fgets(tempPostal, sizeof(tempPostal), stdin);
        size_t inputLength = strlen(tempPostal);

        if (inputLength > 0 && tempPostal[inputLength - 1] == '\n') {
            tempPostal[inputLength - 1] = '\0';

            if (tempPostal[0] == '\0') {
                printf("Invalid Entry: ");
            }
            else {
                int check = isValid(tempPostal);
                if (check) {
                    validPostal = 1;  
                    strcpy(customer->postalCode, tempPostal);
                }
                else {
                    printf("Invalid Entry: ");
                    validPostal = 0;
                }
            }
        }

    } while (!validPostal);

}

int postIsValid(const char* tempPostal) {
    return isValid(tempPostal);
   
}

int stringIsValid(char* tempString) {
    int result = 0;
    int resBool = 0;
    result = checkString(tempString);
    if (result) {
        resBool = 1;
    }
    else {
        resBool = 0;
    }
    return resBool;
}


int main() {
    struct Customer customer;
    setData(&customer);

    printf("\nYou entered:\n");
    printf("%s %s\n", customer.firstName, customer.lastName);
    printf("%s,\n", customer.streetAddress);
    printf("%s, %s\n", customer.city, customer.province);
    printf("%s\n", customer.postalCode);



    return 0; 
}