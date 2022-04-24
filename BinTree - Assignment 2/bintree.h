// BinTree.h
// By Kuzey Gok
// Simple class for a Binary Search Tree that sores NodeData as data
//
// Description of Class BinTree
// =========================================================================
// Has two constructors, one which takes another tree, and a destructor
// Can display the tree sideways or inorder by using the << operator
// Can retrieve a node and its data, get Height of a node, convert to and
// from an array, be emptied, and insert new nodes.
//
// Properties of Class BinTree
// =========================================================================
// Has a Node Struct that is used to store and traverse the tree which only
// the tree can create.
// Has only one private field which is the root of the node 
// Overloaded operators include: =, ==, !=
// Has multiple private helper functions to recursively implement the
// functionality from above.

#ifndef BINTREE_H
#define BINTREE_H

#include "nodedata.h"
#include <string>
#include <iostream>
#include <fstream>

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
    int getHeight(const NodeData &data);
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
    void copyHelper(Node* right);
    bool equalityHelper(Node* left, Node* right) const;  
    Node* retrieveHelper(Node* node, const NodeData &data, NodeData* &ptr);
    int heightHelper(Node* node) const;
    void sideways(Node* node, int level) const;
    Node* insertHelper(Node* node, NodeData* data, bool &exists);
    void bstreeToArrayHelper(Node* node, NodeData* arr[], int &i);
    void arrayToBSTreeHelper(Node* node, NodeData* arr[], int start, int end);
};

#endif