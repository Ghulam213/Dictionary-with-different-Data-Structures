//
//
// Created by GM on 06/01/2021.

#include "LinkedDictionary.h"

#include <utility>

LinkedDictionary::LinkedDictionary(){
    head = nullptr;
}

void LinkedDictionary:: insert(const string& word, const string& meaning){

    Node *newNode,*nodePtr;

    newNode = new Node;
    newNode->word = word;
    newNode->meaning = meaning;

    newNode->next = nullptr;

    if(!head)
        head = newNode;

    else{
        newNode->next = head;
        head = newNode;
    }
}

void LinkedDictionary::deleteNode(const string& delWord) {

    Node *preNode,*nodePtr;
    // If the list is empty, do nothing.
    if(!head){
        return;
    }
    // Determine if the first node is the one.
    if(head->word == delWord){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        cout << "first Node deleted" << endl;
    }
    else{
        nodePtr = head;
        while(nodePtr != nullptr &&  nodePtr->word != delWord){
            preNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        preNode->next = nodePtr->next;
        cout << "Word deleted : "<< delWord << endl;
        delete nodePtr;
    }
}

void LinkedDictionary:: displayList(){
    if (!head)
        return;
    Node *nodePtr;
    nodePtr = head;
    cout << "[ ";
    while(nodePtr->next){
        cout<<"{ Word : "<<nodePtr->word;
        cout<<", Meaning : "<<nodePtr->meaning<< " }, \n";
        nodePtr = nodePtr->next;
    }
    cout<<"{ Word : "<<nodePtr->word;
    cout<<", Meaning : "<<nodePtr->meaning<< " } ]\n";
}

void LinkedDictionary:: countList() {
    Node *nodePtr;
    int count = 0;
    nodePtr = head;
    if (!head)
        cout << " The number of words in dictionary are 0" << endl;
    else {
        nodePtr = head;
        while (nodePtr) {
            count++;
            nodePtr = nodePtr->next;
        }
        cout << " The number of words in dictionary " << count << endl;
    }
}

string LinkedDictionary::search(const string &word) {
    Node *nodePtr;
    // If the list is empty, do nothing.
    if(!head){
        return "";
    }
    nodePtr = head;
    while(nodePtr != nullptr &&  nodePtr->word != word)
        nodePtr = nodePtr->next;

    return nodePtr ? nodePtr->meaning : "";
}
