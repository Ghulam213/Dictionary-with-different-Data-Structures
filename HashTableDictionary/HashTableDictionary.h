//
// Created by GM on 06/01/2021.
//

#ifndef PROJECT_HASHTABLEDICTIONARY_H
#define PROJECT_HASHTABLEDICTIONARY_H

#include <string>
#include "../LinkedListBasedDic/LinkedDictionary.h"
#include "../interface/DictionaryInterface.h"

using namespace std;

class HashTableDictionary: public DictionaryInterface {
    private:
        LinkedDictionary* ld[26]{};
    public:
        HashTableDictionary();
        void insert(const string& word, const string& meaning) override;
        int hash(const string& word);
        string search(const string& word) override;
};


#endif //PROJECT_HASHTABLEDICTIONARY_H
