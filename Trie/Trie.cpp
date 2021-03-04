//
//
// Created by GM on 06/01/2021.

#include "Trie.h"

Trie::Trie() {
    head = nullptr;
}

Trie::Node *Trie::getNewTrieNode() {
    Node* node = new Node;
    node->end = false;
    return node;
}

void Trie::insert(const string& word, const string& meaning) {
    insertUtil(head, word, meaning);
}

void Trie::insertUtil(Trie::Node *&root, const string& word, const string& meaning) {
    if (!root)
        root = getNewTrieNode();

    Node* temp = root;
    for (char x : word) {
        // Make a new node if there is no path
        if (temp->map.find(x) == temp->map.end())
            temp->map[x] = getNewTrieNode();

        temp = temp->map[x];
    }
    // Iterates through each letter of input word . If letter already not in tree then it makes new node
    // else if word already exists it searches down the tries till whole word is completed.

    // Mark end of word and store the meaning
    temp->end = true;
    temp->meaning = meaning; // storing input meaning in the leaf node
}

string Trie::search(const string& word) {
    return searchUtil(head, word);
}

string Trie::searchUtil(Trie::Node *root, const string& word) {
    if (!root)
        return "";

    Node* temp = root;
    // Search a word in the Trie
    for (char i : word) {
        temp = temp->map[i];
        if (!temp) // if word not found return empty string
            return "";
    }
    // If it is the end of a valid word stored
    // before then return its meaning
    return temp->end ? temp->meaning : "";
}
