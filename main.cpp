#include "DocumentManager.h"
#include <iostream>

int main(void) {
    DocumentManager documentmanager;

    std::string input;
    while (input != "STOP") {
        std::cout << "ENTER INSTRUCTION: ";
        std::cin >> input;
        if (input == 'AU') {
            int id;
            std::cout << "Enter User ID: ";
            std::cin >> id;
            documentmanager.addPatron(id);
            std::cout << "Patron " << id << " added successfully." << std::endl;
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
            documentmanager.addDocument(name, id, license);
            std::cout << "Document " << name << " added successfully." << std::endl;
        if (input == 'S') {
            std::string name;
            std::cout << "Enter Book Name: ";
            std::cin >> name;
            int id = documentmanager.search(name);
            std::cout << "Document " << name << " has ID " << id << "." << std::endl;
        if (input == 'B') {
            int id;
            std::cout << "Enter Book ID: ";
            std::cin >> id;
            int id2;
            std::cout << "Enter User ID: ";
            std::cin >> id2;
            bool outcome = documentmanager.borrowDocument(id, id2);
            if (outcome == true) {
                std::cout << "Document " << id << " borrowed successfully by patron " << id2 << "." << std::endl;
            } else {
                std::cout << "Unsuccessful. Make sure the Document ID and Patron ID is correct." << std::endl;
            }
        } else if (input == 'R') {
            int id;
            std::cout << "Enter Book ID: ";
            std::cin >> id;
            int id2;
            std::cout << "Enter User ID: ";
            std::cin >> id2;
            documentmanager.returnDocument(id, id2);
            std::cout << "Document " << id << " returned by patron " << id2 << "." << std::endl;
        }
    }
}
