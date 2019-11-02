#include <stdio.h>
#include <sqlite3.h>

#include "contact.h"

static sqlite3 *db;
static int *zErrMsg = 0;
static int rc;

char *dbName = "contacts.db";

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for(int i = 0; i < argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void checkSQLiteOK(int rc, int zErrMsg, char *successMsg, char *failMsg)
{
    if(rc != SQLITE_OK) {
        fprintf(stderr, "%s\n", failMsg, zErrMsg);
    }
    else {
        fprintf(stdout, "%s\n", successMsg);
    }
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

    checkSQLiteOK(rc, zErrMsg, "Database was successfully created",
            "Could not create database");

    sqlite3_close(db);
}

void InsertContact(const struct Contact* contact)
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
        fprintf(stderr, "Error while inserting new contact %s\n",
                sqlite3_errmsg(db));
    }

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    checkSQLiteOK(rc, zErrMsg, "Contact was added", "Something went wrong");

    sqlite3_close(db);
}

void DeleteContact(const struct Contact* contact)
{
    char *sql = sqlite3_mprintf(
            "DELETE FROM contacts WHERE name = ('%q') AND lastname = ('%q');",
                contact->Name, contact->LastName);

    rc = sqlite3_open(dbName, &db);

    if(rc) {
        fprintf(stderr, "Error while deleting a contact %s\n",
                sqlite3_errmsg(db));
    }

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    checkSQLiteOK(rc, zErrMsg, "Contact was successfully deleted",
            "Could not delete contact");

    sqlite3_close(db);
}
