#include "DocumentManager.h"
#include <iostream>

int main(void) {
    DocumentManager documentmanager;

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
            documentmanager.addPatron(id);
            std::cout << "Patron " << id << " added successfully." << std::endl;
        if (functions[i][0] == 'D') {
            int name = stoi(functions[i].substr(1));
            int id = stoi(functions[i].substr(2));
            int license = stoi(functions[i].substr(3));
            documentmanager.addDocument(name, id, license);
            std::cout << "Document " << name << " added successfully." << std::endl;
        if (functions[i][0] == 'S') {
            int name = stoi(functions[i].substr(1));
            int id = documentmanager.search(name);
            std::cout << "Document " << name << " has ID " << id << "." << std::endl;
        if (functions[i][0] == 'B') {
            int id = stoi(functions[i].substr(1));
            int id2 = stoi(functions[i].substr(2));
            bool outcome = documentmanager.borrowDocument(id, id2);
            if (outcome == true) {
                std::cout << "Document " << id << " borrowed successfully by patron " << id2 << "." << std::endl;
            } else {
                std::cout << "Unsuccessful. Make sure the Document ID and Patron ID is correct." << std::endl;
            }
        } else if (functions[i][0] == 'R') {
            int id = stoi(functions[i].substr(1));
            int id2 = stoi(functions[i].substr(2));
            documentmanager.returnDocument(id, id2);
            std::cout << "Document " << id << " returned by patron " << id2 << "." << std::endl;
        }
    }
}
