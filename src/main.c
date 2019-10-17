#include <stdio.h>

#include "database.h"

int main(void)
{
    const char *dbName = "contacts.db";

    CreateDatabase(dbName);

    return 0;
}
