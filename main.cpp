#include "DocumentManager.h"
#include <iostream>

int main(void) {
    DocumentManager documentmanager;
    
    documentmanager.addPatron(1);
    documentmanager.addPatron(2);
    documentmanager.addDocument("hi", 1, 2);
    documentmanager.addDocument("hello", 2, 1);

    std::cout << documentmanager.borrowDocument(2, 1) << std::endl;
    std::cout << documentmanager.borrowDocument(2, 2) << std::endl;

    documentmanager.returnDocument(2, 2);
    documentmanager.returnDocument(2, 2); 

    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    std::vector<std::string> functions;
    std::string function;
    while (iss >> function) {
        functions.push_back(function);
    }
    
    for (int i=0; i<functions.size()-1; i++) {
        if (functions[i][0] == 'P') {
            int id = stoi(functions[i].substr(1));
            addPatron(id);
            std::cout << "Patron " << id << " added successfully." << std::endl;
        if (functions[i][0] == 'D') {
            int name = stoi(functions[i].substr(1));
            int id = stoi(functions[i].substr(2));
            int license = stoi(functions[i].substr(3));
            addDocument(name, id, license);
            std::cout << "Document " << name << " added successfully." << std::endl;
        if (functions[i][0] == 'S') {
            int name = stoi(functions[i].substr(1));
            int id = search(name);
            std::cout << "Document " << name << " has ID " << id << "." << std::endl;
        if (functions[i][0] == 'B') {
            int id = stoi(functions[i].substr(1));
            int id2 = stoi(functions[i].substr(2));
            bool outcome = borrowDocument(id, id2);
            if (outcome == true) {
                std::cout << "Document " << id << " borrowed successfully by patron " << id2 << "." << std::endl;
            } else {
                std::cout << "Unsuccessful. Make sure the Document ID and Patron ID is correct." << std::endl;
            }
        } else if (functions[i][0] == 'R') {
            int id = stoi(functions[i].substr(1));
            int id2 = stoi(functions[i].substr(2));
            returnDocument(id, id2);
            std::cout << "Document " << id << " returned by patron " << id2 << "." << std::endl;
        }
    }
}
