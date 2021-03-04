//
// Created by GM on 06/01/2021.
//

#ifndef PROJECT_TEMPLATEBASEDVECTORDICTIONARY_H
#define PROJECT_TEMPLATEBASEDVECTORDICTIONARY_H

#include <string>
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <vector>

template <typename T, typename U>
class TemplateBasedVectorDictionary{
    private:
        std::vector<T> words;
        std::vector<U> meanings;
    public:
        TemplateBasedVectorDictionary();
        TemplateBasedVectorDictionary(std::initializer_list<std::pair<T,U>>);
        bool has(T) const;
        void insert(T, U);
        T* begin();
        T* end();
        U operator[](T);
        U search(T);
};


#endif //PROJECT_TEMPLATEBASEDVECTORDICTIONARY_H
