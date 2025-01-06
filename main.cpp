#include "LibraryManager.h"
#include <iostream>

int main(void) {
    LibraryManager library;

    std::cout << "  _      _____ ____  _____            _______     __ " << std::endl;
    std::cout << " | |    |_   _|  _ \|  __ \     /\   |  __ \ \   / / " << std::endl;
    std::cout << " | |      | | | |_) | |__) |   /  \  | |__) \ \_/ /  " << std::endl;
    std::cout << " | |      | | |  _ <|  _  /   / /\ \ |  _  / \   /   " << std::endl;
    std::cout << " | |____ _| |_| |_) | | \ \  / ____ \| | \ \  | |    " << std::endl;
    std::cout << " |______|_____|____/|_|  \_\/_/    \_\_|  \_\ |_|    " << std::endl;
    std::endl; 
    std::cout << "-----------------------------------------------------" << std::endl;   
    std::endl;                                   
    std::cout << "Welcome to Library Manager! Use the following commands" << std::endl;
    std::cout << "to add users, add, borrow, and return books and search" << std::endl;      
    std::cout << "the library inventory! Have a good day :)" << std::endl;  
    std::endl; 
    std::cout << "-----------------------------------------------------" << std::endl;   
    std::endl; 
    std::cout << "INSTRUCTIONS:" << std::endl;   
    std::cout << " - Add User: 'AU'" << std::endl;   
    std::cout << " - Add Book: 'AB'" << std::endl;   
    std::cout << " - Search for a Book: 'S'" << std::endl;   
    std::cout << " - Borrow Book: 'B'" << std::endl;   
    std::cout << " - Return Book: 'R'" << std::endl;    
    std::endl; 
    std::cout << "-----------------------------------------------------" << std::endl;   
    
    std::string input;
    while (input != "STOP") {
        std::endl;
        std::cout << "-----------------------------------------------------" << std::endl; 
        std::endl;
        std::cout << "ENTER INSTRUCTION: ";
        std::cin >> input;
        if (input == 'AU') {
            int id;
            std::cout << "Enter User ID: ";
            std::cin >> id;
            library.addUser(id);
            std::cout << "User " << id << " added successfully." << std::endl;
        if (input == 'AB') {
            std::string name;
            std::cout << "Enter Book Name: ";
            std::cin >> name;
            int id;
            std::cout << "Enter Book ID: ";
            std::cin >> id;
            int license;
            std::cout << "Enter Liscense Limit: ";
            std::cin >> license;
            library.addBook(name, id, license);
            std::cout << "Book " << name << " added successfully." << std::endl;
        if (input == 'S') {
            std::string name;
            std::cout << "Enter Book Name: ";
            std::cin >> name;
            int id = library.search(name);
            std::cout << "Book " << name << " has ID " << id << "." << std::endl;
        if (input == 'B') {
            int id;
            std::cout << "Enter Book ID: ";
            std::cin >> id;
            int id2;
            std::cout << "Enter User ID: ";
            std::cin >> id2;
            bool outcome = library.borrowBook(id, id2);
            if (outcome == true) {
                std::cout << "Book " << id << " borrowed successfully by user " << id2 << "." << std::endl;
            } else {
                std::cout << "Unsuccessful. Make sure the Book ID and User ID is correct." << std::endl;
            }
        } else if (input == 'R') {
            int id;
            std::cout << "Enter Book ID: ";
            std::cin >> id;
            int id2;
            std::cout << "Enter User ID: ";
            std::cin >> id2;
            library.returnBook(id, id2);
            std::cout << "Book " << id << " returned by user " << id2 << "." << std::endl;
        }
    }
}
