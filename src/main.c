#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "database.h"
#include "contact.h"

int main(void)
{

    if(access(dbName, F_OK) == -1) {
        CreateDatabase(dbName);
    }

    char userOption;

    printf("**** Welcome to contacts-cli ****\n");

    printf("Enter: \n"                              \
            "a to insert a new contact\n"           \
            "v to view all your contacts\n"         \
            "e to edit a contact\n"                 \
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
        case 'e': case 'E':
            // edit contact
        case 'd': case 'D':
            removeContact();
            break;
        default:
            printf("Invalid option\n");
    }

    return 0;
}
