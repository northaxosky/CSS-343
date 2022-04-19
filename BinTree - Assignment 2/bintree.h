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
};

#endif