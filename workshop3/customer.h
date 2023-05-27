/*Course: SFT221 | Workshop: 1 | Professor: Robin Huang
Section: NEE | Student Name: Julia Alekseev | Student ID: 051292134
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H


struct Customer {
    char firstName[15];
    char lastName[15];
    char streetAddress[20];
    char city[15];
    char province[15];
    char postalCode[10];
};

void setData(struct Customer* customer);
int checkString(char* string);
int postIsValid(char* tempPostal);
int stringIsValid(char* tempString);
#endif 
