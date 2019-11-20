#include <stdio.h>
#include <string.h>

#include "contact.h"
#include "database.h"

int phoneLength(char *phoneNumber)
{
    const int maxLength = 13;
    const int leastLength = 5;

    if(strlen(phoneNumber) > maxLength || strlen(phoneNumber) < leastLength) {
        return 0;
    }

    return 1;
}

void addNewContact()
{
    struct Contact newConctact;

    printf("\n**** Add a new contact ****\n");
    printf("---------------------------\n");
    printf("Name: ");
    fgets(newConctact.Name, sizeof(newConctact.Name), stdin);
    printf("Lastname: ");
    fgets(newConctact.LastName, sizeof(newConctact.LastName), stdin);

    if(contactExists(newConctact.Name, newConctact.LastName)) {
        printf("Contact already exists\n");
    }
    else {
        do {
            printf("Phone number(Must be at least 4 digits and 12 at most): ");
            fgets(newConctact.PhoneNumber1, sizeof(newConctact.PhoneNumber1), stdin);
        } while(!phoneLength(newConctact.PhoneNumber1));
        do {
            printf("Mobile phone number (Must be at least 4 digits and 12 at most): ");
            fgets(newConctact.PhoneNumber2, sizeof(newConctact.PhoneNumber2), stdin);
        } while(!phoneLength(newConctact.PhoneNumber2));
        printf("Email address: ");
        fgets(newConctact.Email, sizeof(newConctact.Email), stdin);
        printf("Street address: ");
        fgets(newConctact.Address, sizeof(newConctact.Address), stdin);

        InsertContact(&newConctact);
    }
}

void removeContact()
{
    struct Contact deleteContact;

    printf("\n**** Delete a contact ****\n");
    printf("---------------------------\n");
    printf("Name: ");
    fgets(deleteContact.Name, sizeof(deleteContact.Name), stdin);
    printf("Lastname: ");
    fgets(deleteContact.LastName, sizeof(deleteContact.LastName), stdin);

    if(contactExists(deleteContact.Name, deleteContact.LastName)) {
        DeleteContact(&deleteContact);
    } else {
        printf("Contact does not exist\n");
    }
}

void editContact()
{
    struct Contact updateContactStruct;

    char name[20];
    char lastname[20];
    // TODO: malloc memory in runtime rather than using a fixed value

    printf("\n**** Update contact  ****\n");
    printf("---------------------------\n");
    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    printf("Lastname: ");
    fgets(lastname, sizeof(lastname), stdin);

    if(contactExists(name, lastname)) {
        printf("Update name: ");
        fgets(updateContactStruct.Name, sizeof(updateContactStruct.Name), stdin);
        printf("Update lastname: ");
        fgets(updateContactStruct.LastName, sizeof(updateContactStruct.LastName), stdin);
	do {
	     printf("Update phone number (Must be at least 4 digits and 12 digits at most: ");
	     fgets(updateContactStruct.PhoneNumber1, sizeof(updateContactStruct.PhoneNumber1), stdin);
	} while(!phoneLength(updateContactStruct.PhoneNumber1));
	do {
	     printf("Update mobile phone number (Must be at least 4 digits and 12 digits at most: ");
	     fgets(updateContactStruct.PhoneNumber2, sizeof(updateContactStruct.PhoneNumber2), stdin);
	} while(!phoneLength(updateContactStruct.PhoneNumber2));
        printf("Update email: ");
        fgets(updateContactStruct.Email, sizeof(updateContactStruct.Email), stdin);
        printf("Update address: ");
        fgets(updateContactStruct.Address, sizeof(updateContactStruct.Address), stdin);

        updateContact(&updateContactStruct, name, lastname);

    } else {
        printf("Contact does not exist\n");
    }
}
