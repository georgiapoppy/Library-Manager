#include "DocumentManager.h"

void DocumentManager::addDocument(string name, int id, int license_limit) {
    Document document;
    document.name = name;
    document.id = id;
    document.license_limit = license_limit;
    document.borrow_count = 0;
    documents[id] = document;
    doc_names[name] = id;
}

void DocumentManager::addPatron(int patronID) {
    patrons.insert(patronID);
} 

int DocumentManager::search(string name) {
    if (doc_names.find(name) == doc_names.end()) {
        return 0;
    }
    return doc_names.at(name);
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
    if (patrons.find(patronID) == patrons.end()) {
        return false;
    }
    if (documents.at(docid).borrow_count == documents.at(docid).license_limit) {
        return false;
    }
    documents.at(docid).borrow_count++;
    return true;
}

void DocumentManager::returnDocument(int docid, int patronID) {
    if ((patrons.find(patronID) != patrons.end()) || (documents.at(docid).borrow_count != 0)) {
        documents.at(docid).borrow_count--;
    }
}
