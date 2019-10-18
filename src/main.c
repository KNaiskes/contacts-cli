#include <stdio.h>
#include <string.h>

#include "database.h"
#include "contact.h"

int main(void)
{
    const char *dbName = "contacts.db";

    struct Contact testContact = {
        "kiriakos",
        "naiskes",
        "3949393",
        "3030400",
        "xxxxxxxxxxxxxxx@gmail.com",
        "xxxxxkkkk fkfkfkkf"
    };


    struct Contact *contactTest = &testContact;

    CreateDatabase(dbName);
    //InsertContact(dbName, contactTest);
    DeleteContact(dbName, contactTest);


    return 0;
}
