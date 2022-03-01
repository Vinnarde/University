//
// Created by Pepega on 27.01.2022.
//

#ifndef LAB_3_HASHMAP_H
#define LAB_3_HASHMAP_H

#include <iostream>
#include "Tokenizer.h"

using namespace simpleparser;

template <class K, class V>
class HashNode {
public:
    V value;
    K key;

    HashNode() = default;

    HashNode(K key, V value)
    {
        this->value = value;
        this->key = key;
    }
};

template <class K, class V>
class HashMap {
    HashNode<K, V>** arr;
    int capacity;
    int size;
    HashNode<K, V>* dummy;

public:
    HashMap()
    {
        capacity = 1024;
        size = 0;
        arr = new HashNode<K, V>*[capacity];

        for (int i = 0; i < capacity; i++)
            arr[i] = nullptr;

        dummy = new HashNode<K, V>();
    }
    int hashCode(K key)
    {
        return key % capacity;
    }

    void insert(K key, V value)
    {
        auto* temp = new HashNode<K, V>(key, value);

        int hashIndex = hashCode(key);

        while (arr[hashIndex] != nullptr
               && arr[hashIndex]->key != key
               && arr[hashIndex]->key != -1) {
            hashIndex++;
            hashIndex %= capacity;
        }

        if (arr[hashIndex] == NULL
            || arr[hashIndex]->key == -1)
            size++;
        arr[hashIndex] = temp;
    }

    V deleteNode(K key)
    {
        int hashIndex = hashCode(key);

        while (arr[hashIndex] != NULL) {
            if (arr[hashIndex]->key == key) {
                HashNode<K, V>* temp = arr[hashIndex];

                arr[hashIndex] = dummy;

                size--;
                return temp->value;
            }
            hashIndex++;
            hashIndex %= capacity;
        }

        return nullptr;
    }

    V get(K key)
    {
        int hashIndex = hashCode(key);
        int counter = 0;

        while (arr[hashIndex] != nullptr) {

            if (counter++ > capacity)
                return nullptr;

            if (arr[hashIndex]->key == key)
                return arr[hashIndex]->value;
            hashIndex++;
            hashIndex %= capacity;
        }

        return nullptr;
    }

    int sizeofMap()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void display()
    {
        for (int i = 0; i < capacity; i++) {
            if (arr[i] != NULL && arr[i]->key != -1)
                std::cout << "key = " << arr[i]->key
                     << "  value = "
                     << arr[i]->value << std::endl;
        }
    }
};


#endif //LAB_3_HASHMAP_H
