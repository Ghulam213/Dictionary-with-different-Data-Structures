//
// Created by GM on 15/01/2021.
//

#include <fstream>
#include <algorithm>

#include "DictionaryProvider.h"
#include "../TST/TST.h"
#include "../Trie/Trie.h"
#include "../HashTableDictionary/HashTableDictionary.h"
#include "../LinkedListBasedDic/LinkedDictionary.h"
#include "../VectorBasedEDictionary/VectorBasedEDictionary.h"

DictionaryInterface *DictionaryProvider::populate(DictionaryInterface *dict) {
    string line;
    ifstream dict_file("./Dictionary.txt");

    while (getline(dict_file, line)) {
        if (line == "")
            continue;
        for_each(line.begin(), line.end(), [](char& c) { c = tolower(c); });
        dict->insert(line.substr(0, line.find(',')),
                     line.substr(line.find(',') + 1, line.length() - 1));
    }

    dict_file.close();
    return dict;
}

DictionaryInterface *DictionaryProvider::getDict(DictionaryInterface *dictPtr, string dictType) {
    if (dictType == "Ternary Search Tree")
        dictPtr = new TST();
    else if (dictType == "Trie")
        dictPtr = new Trie();
    else if (dictType == "Hash Table")
        dictPtr = new HashTableDictionary();
    else if (dictType == "Linked List")
        dictPtr = new LinkedDictionary();
    else if (dictType == "Vectors")
        dictPtr = new VectorBasedEDictionary();
    else
        return nullptr;

    dictPtr = populate(dictPtr);
    return dictPtr;
}

void DictionaryProvider::insertToFile(const string &word, const string &partOfSpeech, const string &meaning) {
    ofstream outfile;
    outfile.open("./Dictionary.txt", ios_base::app); // append instead of overwrite
    outfile << "\n" + word + ", " + partOfSpeech + ". " + meaning;
}
