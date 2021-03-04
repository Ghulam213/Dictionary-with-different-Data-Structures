//
// Created by GM on 05/01/2021.
//

#include "TST.h"

#include <utility>

TST::TST() {
    head = nullptr;
}

TST::Node *TST::newNode(char letter) {
    Node* temp = new struct Node;
    temp->letter = letter;
    temp->meaning = "";
    temp->isEndOfString = 0;
    temp->left = temp->eq = temp->right = nullptr;
    return temp;
}

TST::Node *TST::insertRecursively(TST::Node *root, string word, const string &meaning) {

    if (!root)
        root = newNode(word[0]);

    // If current character of word is smaller than root's character,
    // then insert this word in left subtree of root
    if (word[0] < root->letter)
        root->left = insertRecursively(root->left, word, meaning);

    // If current character of word is greater than root's character,
    // then insert this word in right subtree of root
    else if (word[0] > (root)->letter)
        root->right = insertRecursively(root->right, word, meaning);

    // If current character of word is same as root's character,
    else {
        if (word[1])
            root->eq = insertRecursively(root->eq, word.substr(1, word.length() -1), meaning);
            // the last character of the word
        else {
            (root)->isEndOfString = 1;
            (root)->meaning = meaning;
        }
    }
    return root;
}

void TST::insert(const string& word, const string &meaning) {
    head = insertRecursively(head, word, meaning);
}

string TST::searchRecursively(TST::Node *root, string word) {
    if (!root)
        return "";

    if (word[0] < (root)->letter)
        return searchRecursively(root->left, word);

    else if (word[0] > (root)->letter)
        return searchRecursively(root->right, word);

    else {
        if (word.length() == 1)
            return root->meaning;

        return searchRecursively(root->eq, word.substr(1, word.length() -1));
    }
}

string TST::search(const string& word) {
    return searchRecursively(head,word);
}

void TST::traverseUtil(TST::Node *root, char *buffer, int depth) {
    if (root) {
        // First traverse the left subtree
        traverseUtil(root->left, buffer, depth);

        // Store the character of this node
        buffer[depth] = root->letter;
        if (root->isEndOfString) {
            buffer[depth+1] = '\0';
            printf( "%s\n", buffer);
        }

        // Traverse the subtree using equal pointer (middle subtree)
        traverseUtil(root->eq, buffer, depth + 1);

        // Finally Traverse the right subtree
        traverseUtil(root->right, buffer, depth);
    }
}

void TST::traverse() {
    char buffer[MAX];
    traverseUtil(head, buffer, 0);
}
