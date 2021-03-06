// Kuzey Gok
// CSS 343
// Hash Table Class Header
// This HashTable class is an implementation of open hashing using
// nodes stored in a vector.
#ifndef HASHTABLE_ASS_4
#define HASHTABLE_ASS_4
#include <vector>
#include <string>
#include "movie.h"
#include"node.h"

using namespace std;

template <typename Key, typename Data, typename Function = Hash<Key>>
class HashTable {
public:
    // Constructors and Destructor
    HashTable() {
        for (unsigned int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }

    ~HashTable()    {
        for (unsigned int i = 0; i < SIZE; i++) {
            Node<Key, Data>* curr = table[i];
            while (curr)    {
                Node<Key, Data>* temp = curr;
                curr = curr->next;
                delete temp;
            }
            table[i] = nullptr;
        }
    }

    // Constant time insert and retrieval
    void insert(const Key& key, const Data& data)   {
        int idx = func(key);
        Node<Key, Data>* prev = nullptr;
        Node<Key, Data>* curr = table[idx];

        while (curr)    {
            if (curr->key == key)   {
                curr->data = data;
                break;
            }
            
            prev = curr;
            curr = curr->next;
        }

        if (!curr)  {
            curr = new Node<Key, Data>(key, data);

            if (!prev)
                table[idx] = curr;
            else
                prev->next = curr;
        }
    }

    bool retrieve(const Key& key, Data& data)   {
        int idx = func(key);
        Node<Key, Data>* curr = table[idx];

        while (curr)    {
            if (curr->key == key)   {
                data = curr->data;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // Remove item from table
    void remove(const Key& key) {
        int idx = func(key);
        Node<Key, Data>* prev = nullptr;
        Node<Key, Data>* curr = table[idx];

        while (curr)    {
            if (curr->key == key)   {
                if (!prev)  
                    table[idx] = curr->next;
                else
                    prev->next = curr->next;
                delete curr;
            }
        }
    }

private:
    // Hash function for insertion
    Function func;
    
    // vector of nodes table used for open hashing
    vector<Node<Key, Data>*> table;
};

// struct for hashing movies
struct MovieHash    {
    int operator()(const string& key) const {
        return hash<string>()(key) % SIZE;
    }
};

#endif