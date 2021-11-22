//
// Created by Pepega on 09.11.2021.
//

#include "Hashtable.h"
#include <stdexcept>
#include <iostream>

int Hashtable::hash(const string &key) const {
    int sum{0};

    for (auto ch: key)
        sum += ch;
    return sum % mSize;
}

void Hashtable::insert(const string &key, syntaxToken *value) {
    int h = hash(key);
    int pos = h;

    do {
        if (!mArr[pos] || mArr[pos]->isDel) {
            // insert
            mArr[pos] = new Pair(key, value);
            return;
        } else {
            // found same element
            if (mArr[pos]->mKey == key)
                return;
        }
        pos = (pos + 1) % mSize;

    } while (pos != h);

    throw std::runtime_error("Hashtable is full!");
}

void Hashtable::remove(std::string key) {

}

void Hashtable::print() {
    int index = 1;
    const int len = 20;
    std::string buf;
    buf = "\n---------------------";
    for (int j = 0; j < len; j++)
        buf += "-";
    buf += "\n";

    for (int i = 0; i < mSize; i++)
    {
        if (!mArr[i] || mArr[i]->isDel)
            continue;

        buf += "| " + std::to_string(i) + "\t| " + mArr[i]->mKey;
        index++;
        for (int j = len - mArr[i]->mKey.length(); j > 0; j--)
            buf += " ";
        buf += "| " + std::string(syntaxKindToString(mArr[i]->mValue->mKind)) + "\t|\n";
    }
    buf += "---------------------";
    for (int j = 0; j < len; j++)
        buf += "-";
    buf += "\n";
    std::cout << buf;
}

syntaxToken *Hashtable::find(const std::string &key) {

    int h = hash(key);
    int pos = h;

    do {
        if (!mArr[pos])
            return nullptr;
        else if (!mArr[pos]->isDel) {
            if (mArr[pos]->mKey == key) {
                return mArr[pos]->mValue;
            }
        }
        pos = (pos + 1) % mSize;
    } while (pos != h);

    return nullptr;
}

Hashtable::Hashtable() {
    mSize = 1024;
    mArr = new Pair*[mSize]();
}

Hashtable::Hashtable(std::size_t size) {
    mSize = size;
    mArr = new Pair*[mSize]();
}



