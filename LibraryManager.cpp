#include "LibraryManager.h"

void LibraryManager::addBook(std::string name, int id, int license_limit) {
    Book book;
    book.name = name;
    book.id = id;
    book.license_limit = license_limit;
    book.borrow_count = 0;
    books[id] = book;
    book_names[name] = id;
}

void LibraryManager::addUser(int userID) {
    users.insert(userID);
} 

int LibraryManager::search(std::string name) {
    if (book_names.find(name) == book_names.end()) {
        return 0;
    }
    return book_names.at(name);
}

int LibraryManager::borrowBook(int bookid, int userID) {
    if (users.find(userID) == users.end()) {
        return -1;
    }
    if (books.at(bookid).borrow_count == books.at(bookid).license_limit) {
        return 0;
    }
    books.at(bookid).borrow_count++;
    return 1;
}

bool LibraryManager::returnBook(int bookid, int userID) {
    if ((users.find(userID) != users.end()) || (books.at(bookid).borrow_count != 0)) {
        books.at(bookid).borrow_count--;
        return true;
    } else {
        return false;
    }
}

void LibraryManager::allBooks() {
    std::unordered_map<int, Book>::iterator it = books.begin();
    std::cout << std::endl;
    while (it != books.end()) {
        std::cout << "Book ID: " << it->first;
        std::cout << ", Name: " << it->second.name;
        std::cout << ", Borrow Count: " << it->second.borrow_count;
        std::cout << ", License Limit: " << it->second.license_limit << std::endl;
        ++it;
    }
}

void LibraryManager::allUsers() {
    std::cout << std::endl;
    std::unordered_set<int>::iterator it = users.begin();
    while (it != users.end()) {
        std::cout << "User ID: " << *it << std::endl;
        ++it;
    }
}
