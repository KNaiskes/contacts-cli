#include <stdio.h>
#include <sqlite3.h>

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
           "address CHAR(30)"                               \
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
