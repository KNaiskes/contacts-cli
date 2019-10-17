#ifndef DATABASE_H_
#define DATABASE_H_

#include "contact.h"

void CreateDatabase(const char* dbName);
void InsertContact(const char* dbName, const struct Contact* contact);
void DeleteContact(const char* dbName, const struct Contact* contact);
void EditContact(const char* dbName, struct Contact* contact);

#endif // DATABASE_H_
