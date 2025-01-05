#include "LibraryManager.h"

void LibraryManager::addBook(string name, int id, int license_limit) {
    Book book;
    book.name = name;
    book.id = id;
    book.license_limit = license_limit;
    book.borrow_count = 0;
    book[id] = book;
    book_names[name] = id;
}

void LibraryManager::addUser(int userID) {
    users.insert(userID);
} 

int LibraryManager::search(string name) {
    if (book_names.find(name) == book_names.end()) {
        return 0;
    }
    return book_names.at(name);
}

bool LibraryManager::borrowBook(int bookid, int userID) {
    if (users.find(userID) == users.end()) {
        return false;
    }
    if (books.at(bookid).borrow_count == books.at(bookid).license_limit) {
        return false;
    }
    books.at(bookid).borrow_count++;
    return true;
}

void LibraryManager::returnBook(int bookid, int userID) {
    if ((users.find(userID) != users.end()) || (books.at(bookid).borrow_count != 0)) {
        books.at(bookid).borrow_count--;
    }
}
