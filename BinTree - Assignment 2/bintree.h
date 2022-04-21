#ifndef BINTREE_H
#define BINTREE_H
#include <string>
#include <iostream>
#include <fstream>
#include <nodedata.h>

using namespace std;

class BinTree   {
    friend ostream& operator<<(ostream& out, const BinTree& tree);

public:
    // Constructors and Destructors
    BinTree();
    BinTree(const BinTree& tree);
    ~BinTree();

    // Overloaded Operators
    BinTree& operator=(const BinTree& tree);
    bool operator==(const BinTree& tree) const;
    bool operator!=(const BinTree& tree) const;

    // Other Functions
    bool retrieve(const NodeData &data, NodeData* &ptr);
    int getHeight(const NodeData &data) const;
    void bstreeToArray(NodeData* arr[]);
    void arrayToBSTree(NodeData* arr[]);
    void displaySideways() const;
    void makeEmpty();
    bool insert(NodeData* data);

private:
    // Node Structure for data
    struct Node {
        NodeData* data;
        Node* left;
        Node* right;
    };

    // Root Node
    Node* root;

    // Private Helper Functions
    void printHelper(const Node* node) const;
    void destructorHelper(Node* node);
    void copyHelper(Node* left, Node* right);
    bool equalityHelper(Node* left, Node* right) const;  
    void retrieveHelper(Node* node, const NodeData &data, NodeData* &ptr);
    int heightHelper(Node* node, const NodeData &data) const;
    void sideways(Node* node, int level) const;
};

#endif