#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Library {
    string name;
    int id;
    int license_limit;
    int borrow_count;
};

class LibraryManager {
    private:
        unordered_map<int, Book> books;
        unordered_map<string, int> book_names;
        unordered_set<int> users;
    public:
        void addBook(string name, int id, int license_limit);
        void addUser(int userID);
        int search(string name); 
        bool borrowBook(int bookid, int userID); 
        void returnBook(int bookid, int userID);
};

#endif
