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
}
