// Kuzey Gok
// CSS 343
// Node Class Header
// The node class is a simple implementation of a node with a 
// next node that will be used as data storage in the Hash Table.
#ifndef NODE_ASS_4
#define NODE_ASS_4

const int SIZE = 100;

template<typename Key, typename Data>
class Node  {
public:
    // Constructors and destructor
    Node()  {
        key = NULL;
        data = NULL;
        next= nullptr;
    }

    Node(const Node& other) {
        key = other.key;
        data = other.data;
        next = other.next;
    }

    Node(const Key& key, const Data& data)  {
        this->key = key;
        this->data = data;
        this->next = nullptr;
    }

    // change the data of the obj
    bool setData(Data& data)    {
        this->data = data;
        return true;
    }

    Key getKey() const { return key; }
    Key getData() const { return data; }
    void setData(Data d) { data = d; }

    // private fields
    Key key;
    Data data;
    Node* next;
};

// struct for hashing
template <typename Key>
struct Hash  {
    int operator()(const Key& key) const  {
        return reinterpret_cast<int>(key) % SIZE;
    }
};

#endif