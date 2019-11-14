#ifndef DATABASE_H_
#define DATABASE_H_

#include "contact.h"

extern char *dbName;

void CreateDatabase(const char* dbName);
void InsertContact(const struct Contact* contact);
void DeleteContact(const struct Contact* contact);
void EditContact(struct Contact* contact);
int contactExists(char *name, char *lastName);
void listAllContacts();
void updateContact(struct Contact* contact, char *name, char *lastname);

#endif // DATABASE_H_
