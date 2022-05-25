// Kuzey Gok
// CSS 343
// Hash Table Class Header
// This HashTable class is an implementation of open hashing using
// nodes stored in a vector.
#ifndef HASHTABLE_ASS_4
#define HASHTABLE_ASS_4
#include <vector>
#include "movie.h"
#include"node.h"

using namespace std;

template <typename Key, typename Data>
class HashTable {
public:
    // Constructors and Destructor
    HashTable();
    HashTable(const Key &key, const Data &data);
    ~HashTable();

    // Constant time insert and retrieval
    void insert(const Key& key, const Data& data);
    void retrieve(const Key& key);
private:
    // Hash function for insertion
    int hash(const Key& key, const Data &data);
    // vector of nodes table used for open hashing
    vector<Node<Key, Data>*> table;
};
#endif