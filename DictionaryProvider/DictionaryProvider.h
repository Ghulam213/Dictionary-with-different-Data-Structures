//
// Created by GM on 15/01/2021.
//

#ifndef PROJECT_DICTIONARYPROVIDER_H
#define PROJECT_DICTIONARYPROVIDER_H


#include "../interface/DictionaryInterface.h"
#include <string>

using namespace std;

class DictionaryProvider {
    private:
        DictionaryInterface* populate(DictionaryInterface* dict);

    public:
        DictionaryInterface* getDict(DictionaryInterface* dictPtr, string dictType);
        void insertToFile(const string &word, const string &partOfSpeech, const string &meaning);

};


#endif //PROJECT_DICTIONARYPROVIDER_H
