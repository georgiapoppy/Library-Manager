#ifndef LIBRARYMANAGER_H
#define LIBRARYMANAGER_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>

struct Book {
    std::string name;
    int id;
    int license_limit;
    int borrow_count;
};

class LibraryManager {
    private:
        std::unordered_map<int, Book> books;
        std::unordered_map<std::string, int> book_names;
        std::unordered_set<int> users;
    public:
        void addBook(std::string name, int id, int license_limit);
        void addUser(int userID);
        int search(std::string name); 
        int borrowBook(int bookid, int userID); 
        bool returnBook(int bookid, int userID);
        void allBooks();
        void allUsers();
};

#endif
