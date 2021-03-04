//
// Created by GM on 06/01/2021.
//

#include "HashTableDictionary.h"

HashTableDictionary::HashTableDictionary() {
    for (int i = 0; i < 26; i++)
        ld[i] = new LinkedDictionary();
}

void HashTableDictionary::insert(const string& word, const string& meaning) {
    int index = hash(word);
    ld[index]->insert(word, meaning);
}

int HashTableDictionary::hash(const string& word) {
    return word[0] - 'a';
}

string HashTableDictionary::search(const string& word) {
    int index = hash(word);
    return ld[index]->search(word);
}
