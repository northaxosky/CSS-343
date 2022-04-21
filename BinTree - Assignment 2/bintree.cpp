#include "bintree.h"

// Overloaded Accessor << operator
ostream& operator<<(ostream& out, const BinTree &tree) {
    tree.printHelper(tree.root);
    return out << endl;
}

// Constructors and Destructor
BinTree::BinTree()  {
    this->root = nullptr;
}

BinTree::BinTree(const BinTree &tree)   {
    this->root = tree.root;
}

BinTree::~BinTree() {
    destructorHelper(root);
}

// Overloaded Operators
BinTree& BinTree::operator=(const BinTree& tree)    {
    if (*this == tree)  {
        return *this;
    }
    if (tree.root == nullptr)    {
        this->root = nullptr;
        return *this;
    }

    destructorHelper(root);
    copyHelper(this->root, tree.root);
    return *this;
}

bool BinTree::operator==(const BinTree& tree) const {
    if (this->root == nullptr && tree.root == nullptr)  {
        return true;
    }
    return equalityHelper(this->root, tree.root);
}

bool BinTree::operator!=(const BinTree& tree) const {
    return !(*this == tree);
}

// Other Necessary Functions
bool BinTree::retrieve(const NodeData &data, NodeData* &ptr)    {
    retrieveHelper(this->root, data, ptr);

    return ptr != nullptr;
}

int BinTree::getHeight(const NodeData &data) const  {
    return heightHelper(this->root, data);
}

void bstreeToArray(NodeData* arr[]) {}

void arrayToBSTree(NodeData* arr[]) {}

// Private Helper Functions

void BinTree::printHelper(const Node* node) const   {
    if (node != nullptr)    {
        printHelper(node->left);
        cout << node->data << " ";
        printHelper(node->right);
    }
}

void BinTree::destructorHelper(Node* node) {
    if (node != nullptr)    {
        destructorHelper(node->left);
        destructorHelper(node->right);

        if (node->data != nullptr)  {
            delete node->data;
        }

        delete node;
        node = nullptr;      
    }
}

void BinTree::copyHelper(Node* left, Node* right)   {
    if (right != nullptr)   {
        left = new Node;
        NodeData* data = new NodeData(*right->data);
        left->data = data;

        copyHelper(left->left, right->left);
        copyHelper(left->right, right->left);
    }
}

bool BinTree::equalityHelper(Node* left, Node* right) const {
    if (left == nullptr && right == nullptr)    return true;
    if (left == nullptr || right == nullptr)    return false;
    if (left->data != right->data) return false;
    
    return (left->data == right->data &&
            equalityHelper(left->left, right->left) &&
            equalityHelper(left->right, right->right));
}

void BinTree::retrieveHelper(Node* node, const NodeData &data, NodeData* &ptr)  {
    if (node == nullptr)    ptr = nullptr;
    else if (*node->data == data) ptr = node->data;
    else if (*node->data < data)    retrieveHelper(node->right, data, ptr);
    else    retrieveHelper(node->left, data, ptr);
}

int BinTree::heightHelper(Node* node, const NodeData &data) const   {

}