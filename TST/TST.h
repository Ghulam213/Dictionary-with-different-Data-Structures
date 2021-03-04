//
// Created by GM on 05/01/2021.
//

#ifndef PROJECT_TST_H
#define PROJECT_TST_H

#include <string>
#include "../interface/DictionaryInterface.h"

using namespace std;


class TST: public DictionaryInterface {
    private:
        // A node of ternary search tree
        struct Node {
            char letter;
            string meaning;
            // True if this character is last character of one of the words
            unsigned isEndOfString: 1;
            struct Node *left, *eq, *right;
        };

        int MAX = 50;
        Node * head;

    public:
        TST();
        Node* newNode(char letter);
        Node* insertRecursively(Node* root, string word, const string& meaning);
        void insert(const string& word, const string& meaning) override;
        string searchRecursively(Node* root, string word);
        string search(const string& word) override;
        void traverseUtil(Node* root, char* buffer, int depth);
        void traverse();

};


#endif //PROJECT_TST_H
