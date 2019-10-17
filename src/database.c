#include <stdio.h>
#include <sqlite3.h>

#include "contact.h"

static sqlite3 *db;
static int *zErrMsg = 0;
static int rc;

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for(int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void CreateDatabase(const char *dbName)
{
    char* sql;
    rc = sqlite3_open(dbName, &db);

    sql = "CREATE TABLE IF NOT EXISTS contacts("            \
           "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
           "NAME CHAR(20) NOT NULL,"                        \
           "LASTNAME CHAR(20) NOT NULL,"                    \
           "PHONENUMER1 CHAR(20),"                          \
           "PHONENUMER2 CHAR(20),"                          \
           "EMAIL CHAR(30),"                                \
           "ADDRESS CHAR(30)"                               \
           ");"                                             \
           ;

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "Something went wrong: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Database was successfully created\n");
    }

    sqlite3_close(db);
}

void InsertContact(const char *dbName, const struct Contact* contact)
{
    char *sql = sqlite3_mprintf(
            "INSERT INTO contacts"                                       \
            "(NAME, LASTNAME, PHONENUMER1, PHONENUMER2, EMAIL, ADDRESS)" \
            "VALUES('%q','%q','%q','%q','%q','%q');",                    \
            contact->Name, contact->LastName, contact->PhoneNumber1,
            contact->PhoneNumber2, contact->Email, contact->Address
    );

    rc = sqlite3_open(dbName, &db);

    if(rc) {
        fprintf(stderr, "Error whiling inserting new contact %s\n",
                sqlite3_errmsg(db));
    }

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if(rc != SQLITE_OK) {
        fprintf(stderr, "Someting went wrong: %s\n", zErrMsg);

        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "Contact %s %s was added\n",
                contact->Name, contact->LastName);
    }

    sqlite3_close(db);
}
