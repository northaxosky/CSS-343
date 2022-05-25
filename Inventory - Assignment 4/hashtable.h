#ifndef HASHTABLE_ASS_4
#define HASHTABLE_ASS_4
#include <vector>
#include "movie.h"
#include"node.h"

using namespace std;

template <typename Key, typename Data>
class HashTable {
public:
    HashTable();
    HashTable(const Key &key, const Data &data);
    ~HashTable();

    void insert(const Key& key, const Val& val);
    void retrieve(const Key& key);

private:
    vector<Node<Key, Data>*> table;
};
#endif