//
// Created by GM on 06/01/2021.
//

#ifndef PROJECT_TRIE_H
#define PROJECT_TRIE_H

#include <iostream>
#include <unordered_map> // for storing char in  tries . Each value is in key value form
#include "../interface/DictionaryInterface.h"

using namespace std;

class Trie: public DictionaryInterface {
    private:
        struct Node {
            bool end; // for making record if node is leaf node . If it is -> searching stops
            unordered_map<char, Node*> map;
            // For each char (key) in tries there is a value of meaning (string)
            string meaning; // meaning for words in dictionary
        };
        Node* head;
    public:
        Trie();
        Node* getNewTrieNode();
        void insert(const string& word, const string& meaning) override;
        void insertUtil(Node*& root, const string& word, const string& meaning);
        string search(const string& word) override;
        string searchUtil(Node* root, const string& word);

};


#endif //PROJECT_TRIE_H
