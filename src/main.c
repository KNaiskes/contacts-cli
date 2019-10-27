#include <stdio.h>
#include <string.h>

#include "database.h"
#include "contact.h"

int main(void)
{
    const char *dbName = "contacts.db";

    char userOption;

    printf("**** Welcome to contacts-cli ****\n");

    printf("Enter: \n"                              \
            "a to insert a new contact\n"           \
            "v to view all your contacts\n"         \
            "s to search for a contact\n"           \
            "d to delete a contact\n"               \
            "> "                                    \
          );

    userOption = getchar();
    while((getchar()) != '\n'); // clean STDIN buffer

    switch(userOption) {
        case 'A': case 'a':
            addNewContact();
            break;
        case 'v': case 'V':
            // view all contacts
            break;
        case 'd': case 'D':
            // delete contact
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}
