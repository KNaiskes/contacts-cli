#include <stdio.h>

#include "contact.h"
#include "database.h"

void addNewContact()
{
    struct Contact newConctact;

    printf("\n**** Add a new contact ****\n");
    printf("---------------------------\n");
    printf("Name: ");
    fgets(newConctact.Name, sizeof(newConctact.Name), stdin);
    printf("Lastname: ");
    fgets(newConctact.LastName, sizeof(newConctact.LastName), stdin);
    printf("Phone number: ");
    fgets(newConctact.PhoneNumber1, sizeof(newConctact.PhoneNumber1), stdin);
    printf("Mobile phone number: ");
    fgets(newConctact.PhoneNumber2, sizeof(newConctact.PhoneNumber2), stdin);
    printf("Email address: ");
    fgets(newConctact.Email, sizeof(newConctact.Email), stdin);
    printf("Street address: ");
    fgets(newConctact.Address, sizeof(newConctact.Address), stdin);

    InsertContact(&newConctact);
}
