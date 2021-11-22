//
// Created by Pepega on 09.11.2021.
//

#ifndef LAB_3_HASHTABLE_H
#define LAB_3_HASHTABLE_H

#include "Tokenizer.h"

using namespace simpleparser;

struct Pair{
    bool isDel{false};
    std::string mKey;
    syntaxToken* mValue;
    Pair(std::string key, syntaxToken* val)
    {
        mKey = key;
        mValue = val;
    }
};

class Hashtable {
private:
    std::size_t mSize;
    Pair** mArr;
public:
    int hash(const std::string &key) const;
    Hashtable();
    explicit Hashtable(std::size_t size);
    syntaxToken* find(const std::string &key);
    void insert(const std::string &key, syntaxToken *value);
    void remove(std::string key);
    void print();
};


#endif //LAB_3_HASHTABLE_H
