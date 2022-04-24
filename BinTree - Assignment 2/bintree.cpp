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
    root = nullptr;
    copyHelper(tree.root);
}

BinTree::~BinTree() {
    destructorHelper(root);
}

// Overloaded Operators
BinTree& BinTree::operator=(const BinTree& tree)    {
    if (*this != tree)  {
        this->makeEmpty();
        root = nullptr;
        copyHelper(tree.root);
    }   
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
    Node* temp = retrieveHelper(this->root, data, ptr);
    return temp != nullptr;
}

int BinTree::getHeight(const NodeData &data) {
    NodeData* dummy;
    Node* temp = retrieveHelper(root, data, dummy);
    return heightHelper(temp);
}

void BinTree::bstreeToArray(NodeData* arr[]) {
    int i = 0;
    bstreeToArrayHelper(root, arr, i);
    destructorHelper(root);
}

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

void BinTree::displaySideways() const   {
    sideways(root, 0);
}

void BinTree::makeEmpty()   {
    destructorHelper(root);
}

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

// Private Helper Functions

void BinTree::printHelper(const Node* node) const   {
    if (node != nullptr)    {
        printHelper(node->left);
        cout << *node->data << " ";
        printHelper(node->right);
    }
}

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

void BinTree::copyHelper(Node* right)   {
    if (right)  {
        NodeData* data = new NodeData(*right->data);
        insert(data);
        copyHelper(right->left);
        copyHelper(right->right);
    }
}

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

int BinTree::heightHelper(Node* node) const   {
    if (!node)
        return 0;
    return 1 + max(heightHelper(node->left), heightHelper(node->right));
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

void BinTree::bstreeToArrayHelper(Node* node, NodeData* arr[], int &i)  {
    if (node)   {
        bstreeToArrayHelper(node->left, arr, i);
        arr[i] = node->data;
        node->data = nullptr;
        i++;
        bstreeToArrayHelper(node->right, arr, i);
    }
}

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