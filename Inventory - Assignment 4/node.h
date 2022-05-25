#ifndef NODE_ASS_4
#define NODE_ASS_4

template<typename Key, typename Data>
class Node  {
public:
    Node();
    Node(const Node& other);
    Node(const Key& key, const Data& data);
    ~Node();

    bool setData();
private:
    Key key;
    Data data;
    Node* next;
};

#endif