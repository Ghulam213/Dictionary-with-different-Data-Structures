//
// Created by GM on 06/01/2021.
//

#ifndef PROJECT_LINKEDDICTIONARY_H
#define PROJECT_LINKEDDICTIONARY_H

#include <string>
#include <iostream>
#include "../interface/DictionaryInterface.h"

using namespace std;

class LinkedDictionary: public DictionaryInterface {
    private:
        struct Node {
            string word;
            string meaning;
            Node *next;
        };
        Node *head;
    public:
        LinkedDictionary();
        void insert(const string& word, const string& meaning);
        void deleteNode(const string& delWord);
        void displayList();
        void countList();
        string search(const string& word) override;

};


#endif //PROJECT_LINKEDDICTIONARY_H
