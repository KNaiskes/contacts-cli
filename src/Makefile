CC = gcc

main: main.o database.o contact.o
	$(CC) main.o database.o contact.o -l sqlite3 -o contacts-cli

main.o: main.c
	$(CC) -c main.c

database.o: database.c
	$(CC) -c database.c

contact.o: contact.c
	$(CC) -c contact.c

clean:
	rm *.o contacts-cli contacts.db
