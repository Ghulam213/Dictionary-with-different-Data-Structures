//
// Created by GM on 06/01/2021.
//

#include "TemplateBasedVectorDictionary.h"

template<typename T, typename U>
TemplateBasedVectorDictionary<T, U>::TemplateBasedVectorDictionary() = default;

template <typename T, typename U>
T* TemplateBasedVectorDictionary<T,U>::begin(){
    return &(words[0]);
}

template <typename T, typename U>
T* TemplateBasedVectorDictionary<T,U>::end(){
    return &(words[words.size() - 1]) + 1;
}

template <typename T, typename U>
TemplateBasedVectorDictionary<T,U>::TemplateBasedVectorDictionary (std::initializer_list<std::pair<T,U>> store){
    for (std::pair<T,U> object : store){
        words.push_back(object.first);
        meanings.push_back(object.second);
    }
}

template <typename T, typename U>
bool TemplateBasedVectorDictionary<T,U>::has(T targetKey) const{
    for (T currentKey : words){
        if (currentKey == targetKey){
            return true;
        }
    }
    return false;
}

template <typename T, typename U>
void TemplateBasedVectorDictionary<T,U>::insert (T key, U value){
    words.push_back(key);
    meanings.push_back(value);
}

template <typename T, typename U>
U TemplateBasedVectorDictionary<T,U>::operator[] (T key){
    unsigned int pos = std::find(words.begin(), words.end(), key) - words.begin();
    return meanings[pos];
}

template<typename T, typename U>
U TemplateBasedVectorDictionary<T, U>::search(T key) {
    return (*this)[key];
}