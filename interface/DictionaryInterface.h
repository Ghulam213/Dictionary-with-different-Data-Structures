//
// Created by GM on 06/01/2021.
//

#ifndef PROJECT_DICTIONARYINTERFACE_H
#define PROJECT_DICTIONARYINTERFACE_H

#include <string>

using namespace std;

class DictionaryInterface {
    public:
        virtual void insert(const string& word, const string& meaning) = 0;
        virtual string search(const string& word) = 0;
};

#endif //PROJECT_DICTIONARYINTERFACE_H
