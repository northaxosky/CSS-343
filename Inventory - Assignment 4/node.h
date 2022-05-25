// Kuzey Gok
// CSS 343
// Node Class Header
// The node class is a simple implementation of a node with a 
// next node that will be used as data storage in the Hash Table.
#ifndef NODE_ASS_4
#define NODE_ASS_4

template<typename Key, typename Data>
class Node  {
public:
    // Constructors and destructor
    Node();
    Node(const Node& other);
    Node(const Key& key, const Data& data);
    ~Node();

    // change the data of the obj
    bool setData(Data& data);
private:
    // private fields
    Key key;
    Data data;
    Node* next;
};

#endif