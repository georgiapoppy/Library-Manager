#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Document {
    string name;
    int id;
    int license_limit;
    int borrow_count;
};

class DocumentManager {
    private:
        unordered_map<int, Document> documents;
        unordered_map<string, int> doc_names;
        unordered_set<int> patrons;
    public:
        void addDocument(string name, int id, int license_limit);
        void addPatron(int patronID);
        int search(string name); 
        bool borrowDocument(int docid, int patronID); 
        void returnDocument(int docid, int patronID);
};

#endif
