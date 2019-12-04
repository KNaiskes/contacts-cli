# contacs-cli

Organise your contacts on the cli (command line)

### Functionality

- Add a new contact (checks if contact with the same name and lastname already
exists)
- Remove a contact (checks if contact exists)
- Edit an existing contact (same as remove option, checks first if contact
exists)
- List all your contacts

### Requirements
A C compiler (like [GCC](https://gcc.gnu.org/))
[SQLite](https://sqlite.org/index.html/) (It is already installed in most
GNU/Linux distributions)

### Build and run

```
$ git clone https://github.com/KNaiskes/contacts-cli
$ cd contacts-cli/src/
$ make
$ ./contacts-cli
```
![project](https://user-images.githubusercontent.com/6069054/70173772-408fbf00-16dc-11ea-8425-8294eb90f7a9.gif)