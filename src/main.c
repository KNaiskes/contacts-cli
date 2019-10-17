#include <stdio.h>
#include <string.h>

#include "database.h"
#include "contact.h"

int main(void)
{
    const char *dbName = "contacts.db";

    struct Contact *contactTest = {
        "kiriakos",
        "naiskes",
        "3949393",
        "3030400",
        "xxxxxxxxxxxxxxx@gmail.com",
        "xxxxxkkkk fkfkfkkf"
    };

    CreateDatabase(dbName);
    InsertContact(dbName, contactTest);


    return 0;
}
