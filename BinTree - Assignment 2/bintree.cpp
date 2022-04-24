// BinTree.cpp
// By Kuzey Gok
// Simple class for a Binary Search Tree that sores NodeData as data
// Description in .h file



#include "bintree.h"


// Overloaded Accessor << operator
ostream& operator<<(ostream& out, const BinTree &tree) {
    tree.printHelper(tree.root);
    return out << endl;
}

// ========== Constructors and Destructor ========== 
// No parameter constructor
// Initializes the root as nullptr
BinTree::BinTree()  {
    this->root = nullptr;
}

// Copy Constructor
// Takes in another BinTree and makes a deep copy of all of it
BinTree::BinTree(const BinTree &tree)   {
    root = nullptr;
    copyHelper(tree.root);
}

// Destructor
// Deletes all the nodes and the data within the nodes of the tree
BinTree::~BinTree() {
    destructorHelper(root);
}

// ========== Overloaded Operators ==========
// Assignment Operator
// Creates a copy of the right tree and makes it the left tree after clearing the left tree 
BinTree& BinTree::operator=(const BinTree& tree)    {
    if (*this != tree)  {
        this->makeEmpty();
        root = nullptr;
        copyHelper(tree.root);
    }   
    return *this;
}

// Equality Operator
// Checks to see if two trees are equal
bool BinTree::operator==(const BinTree& tree) const {
    if (this->root == nullptr && tree.root == nullptr)  {
        return true;
    }
    return equalityHelper(this->root, tree.root);
}

// Inequality operator
// returns the opposite of the equality operator
bool BinTree::operator!=(const BinTree& tree) const {
    return !(*this == tree);
}

// ========== Other Necessary Functions ==========
// Retrieve Function
// Finds the node with the data given as a parameter and sets the other parameter to the data 
bool BinTree::retrieve(const NodeData &data, NodeData* &ptr)    {
    Node* temp = retrieveHelper(this->root, data, ptr);
    return temp != nullptr;
}

// Height Function
// returns the height of a node from the bottom-most node of the tree
int BinTree::getHeight(const NodeData &data) {
    NodeData* dummy;
    Node* temp = retrieveHelper(root, data, dummy);
    return heightHelper(temp);
}

// BSTree to Array Function
// Converts the Binary Search Tree to an array and deletes the tree
void BinTree::bstreeToArray(NodeData* arr[]) {
    int i = 0;
    bstreeToArrayHelper(root, arr, i);
    destructorHelper(root);
}

// Array to BSTree Function
// Converts the array to a binary search tree
void BinTree::arrayToBSTree(NodeData* arr[]) {
    destructorHelper(root);

    int size = 0;
    for (int i = 0; i < 100; i++)   {
        if (arr[i] != nullptr)  {
            size++;
        }
        else    {
            break;
        }
    }
    size--;

    arrayToBSTreeHelper(root, arr, 0, size);
}

// Display Tree Sideways Function
// Supplied by professor
void BinTree::displaySideways() const   {
    sideways(root, 0);
}

// Make Tree Empty Function
// A method used to delete the tree
void BinTree::makeEmpty()   {
    destructorHelper(root);
}

// Insert Function
// Inserts the parameter NodeData into the correct position in the tree
bool BinTree::insert(NodeData* data)    {
    if (root == nullptr)    {
        root = new Node;
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        data = nullptr;
        return true;
    }
    bool exists = false;

    insertHelper(this->root, data, exists);
    return !exists;
}

// ========== Private Helper Functions ==========  
// Print Helper
// Prints the tree inorder by recursively traversing
void BinTree::printHelper(const Node* node) const   {
    if (node != nullptr)    {
        printHelper(node->left);
        cout << *node->data << " ";
        printHelper(node->right);
    }
}

// Destructor Helper
// Deletes all the node and nodeData in the tree by recursively traversing from the bottom up
void BinTree::destructorHelper(Node* node) {
    if (node != nullptr)    {
        destructorHelper(node->left);
        destructorHelper(node->right);

        if (node->data) {
            delete node->data;
            node->data = nullptr;
        }
        delete node;
        node = nullptr;      
    }

    root = nullptr;
}

// Copy Helper
// Creates a copy by recursively inserting all the nodes of the tree to copy
void BinTree::copyHelper(Node* right)   {
    if (right)  {
        NodeData* data = new NodeData(*right->data);
        insert(data);
        copyHelper(right->left);
        copyHelper(right->right);
    }
}

// Equality Helper
// Checks for equality by recursively checking all nodes data values and if they are leaves
bool BinTree::equalityHelper(Node* left, Node* right) const {
    if (!left && !right)    
        return true;
    if (left && right)  {
        return(
            *left->data == *right->data &&
            equalityHelper(left->left, right->left) &&
            equalityHelper(left->right, right->right)
        );
    }
    return false; 
}

// Retrieve Helper
// Retrieves the node and sets the ptr to the data by recursively traversing the tree
BinTree::Node* BinTree::retrieveHelper(Node* node, const NodeData &data, NodeData* &ptr)  {
    if (node == nullptr)    {
        ptr = nullptr;
        return nullptr;
    }
    else if (*node->data == data)   {
        ptr = node->data;
        return node;
    }
    else if (*node->data < data)    return retrieveHelper(node->right, data, ptr);
    else    return retrieveHelper(node->left, data, ptr);
}

// Height Helper
// returns the number from the node to the deepest leaf by finding the max amount of recursive calls
int BinTree::heightHelper(Node* node) const   {
    if (!node)
        return 0;
    return 1 + max(heightHelper(node->left), heightHelper(node->right));
}

// Sideways Helper (Provided by Professor)
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

// Insert Helper
// inserts a new node by comparing and traversing the tree recursively
BinTree::Node* BinTree::insertHelper(Node* node, NodeData* data, bool &exists)    {
    if (node == nullptr)    {
        auto* temp = new Node;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->data = data;
        data = nullptr;
        node = temp;
        return node;
    }
    if (*data < *node->data) 
        node->left = insertHelper(node->left, data, exists);
    else if (*data == *node->data)  {
        exists = true;
        return node;
    }
    else
        node->right = insertHelper(node->right, data, exists);
    
    return node;
}

// BSTree to Array Helper
// Stores the tree in the array in order byu traversing the tree recursively
void BinTree::bstreeToArrayHelper(Node* node, NodeData* arr[], int &i)  {
    if (node)   {
        bstreeToArrayHelper(node->left, arr, i);
        arr[i] = node->data;
        node->data = nullptr;
        i++;
        bstreeToArrayHelper(node->right, arr, i);
    }
}

// Array to BSTree Helper
// Inserts the data from the array by using a Binary Search on the array
void BinTree::arrayToBSTreeHelper(Node* node, NodeData* arr[], int start, int end)   {
    if (start > end)    {
        node = nullptr;
        return;
    }
    int midpoint = (start + end) / 2;
    NodeData* data = arr[midpoint];
    arr[midpoint] = nullptr;
    insert(data);
    arrayToBSTreeHelper(node, arr, start, (midpoint - 1));
    arrayToBSTreeHelper(node, arr, (midpoint + 1), end);
}