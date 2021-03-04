//
// Created by GM on 12/01/2021.
//

#include <algorithm>
#include <utility>
#include "VectorBasedEDictionary.h"

VectorBasedEDictionary::VectorBasedEDictionary() = default;

string* VectorBasedEDictionary::begin(){
    return &(words[0]);
}

string* VectorBasedEDictionary::end(){
    return &(words[words.size() - 1]) + 1;
}


VectorBasedEDictionary::VectorBasedEDictionary(std::initializer_list<std::pair<string, string>> store) {
    for (std::pair<string,string> object : store){
        words.push_back(object.first);
        meanings.push_back(object.second);
    }
}

bool VectorBasedEDictionary::has(string targetKey) const{
    for (string currentKey : words){
        if (currentKey == targetKey){
            return true;
        }
    }
    return false;
}


void VectorBasedEDictionary::insert (const string& word, const string& meaning){
    words.push_back(word);
    meanings.push_back(meaning);
}


string VectorBasedEDictionary::operator[] (string key){
    unsigned int pos = std::find(words.begin(), words.end(), key) - words.begin();
    return meanings[pos];
}


string VectorBasedEDictionary::search(const string& word) {
    return (*this)[std::move(word)];
}