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

void BinTree::bstreeToArray(NodeData* arr[]) {

    destructorHelper(root);
}

void BinTree::arrayToBSTree(NodeData* arr[]) {
    destructorHelper(root);


}

void BinTree::displaySideways() const   {
    sideways(root, 0);
}

void BinTree::makeEmpty()   {
    destructorHelper(root);
}

bool BinTree::insert(NodeData* data)    {
    return insertHelper(root, data);
}

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
    if (node == nullptr)    return 0;
    if (*node->data == data)    return 1 + max(heightHelper(node->left, data), heightHelper(node->right, data));
 

}

void BinTree::sideways(Node* node, int level) const  {
    if (node != NULL) {
		level++;
		sideways(node->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *node->data << endl;        // display information of object
		sideways(node->left, level);
	}
}

bool BinTree::insertHelper(Node* node, NodeData* data)  {
    if (node == nullptr)    {
        node = new Node;
        node->data = data;
        node->left = nullptr;
        node->right = nullptr;
        return true;
    }
    if (*data < *node->data) return insertHelper(node->left, data);
    if (*data > *node->data) return insertHelper(node->right, data);
    if (*data == *node->data) return false;
}