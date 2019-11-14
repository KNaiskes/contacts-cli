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

    if(contactExists(&newConctact)) {
        printf("Contact already exists\n");
        // TODO: return back to menu
    }
    else {

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

    if(contactExists(&deleteContact)) {
        DeleteContact(&deleteContact);
    } else {
        printf("Contact does not exist\n");
    }
}

void editContact()
{
    struct Contact updateContactStruct;

    printf("\n**** Update contact  ****\n");
    printf("---------------------------\n");
    printf("Name: ");
    fgets(updateContactStruct.Name, sizeof(updateContactStruct.Name), stdin);
    printf("Lastname: ");
    fgets(updateContactStruct.LastName, sizeof(updateContactStruct.LastName), stdin);

    if(contactExists(&updateContactStruct)) {
        // TODO get the updated values
        //updateContact(&updateContactStruct);
    } else {
        printf("Contact does not exist\n");
    }

}
