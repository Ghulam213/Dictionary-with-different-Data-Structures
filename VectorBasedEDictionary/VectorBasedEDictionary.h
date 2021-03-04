//
// Created by GM on 12/01/2021.
//

#ifndef PROJECT_VECTORBASEDEDICTIONARY_H
#define PROJECT_VECTORBASEDEDICTIONARY_H

#include <vector>
#include <string>
#include "../interface/DictionaryInterface.h"

using namespace std;


class VectorBasedEDictionary : public DictionaryInterface{
    private:
        std::vector<string> words;
        std::vector<string> meanings;
    public:
        VectorBasedEDictionary();
        VectorBasedEDictionary(std::initializer_list<std::pair<string,string>>);
        bool has(string) const;
        void insert(const string& word, const string& meaning) override;
        string* begin();
        string* end();
        string operator[](string);
        string search(const string& word) override;
};


#endif //PROJECT_VECTORBASEDEDICTIONARY_H
