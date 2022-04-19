#include "bintree.h"

// Overloaded Accessor << operator
ostream& operator<<(ostream& out, const BinTree &tree) {}

// Constructors and Destructor
BinTree::BinTree()  {}

BinTree::BinTree(const BinTree &tree)   {}

BinTree::~BinTree() {}

// Overloaded Operators
BinTree& BinTree::operator=(const BinTree& tree)    {}

bool BinTree::operator==(const BinTree& tree) const {}

bool BinTree::operator!=(const BinTree& tree) const {}

// Other Necessary Functions
bool BinTree::retrieve(const NodeData &data, NodeData* &ptr)    {}

int BinTree::getHeight(const NodeData &data) const  {}

void bstreeToArray(NodeData* arr[]) {}

void arrayToBSTree(NodeData* arr[]) {}



