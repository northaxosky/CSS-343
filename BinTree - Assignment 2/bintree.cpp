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

    Node* node = insertHelper(this->root, data);
    return (node != nullptr);
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
    return 0;
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

BinTree::Node* BinTree::insertHelper(Node* node, NodeData* data)    {
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
        node->left = insertHelper(node->left, data);
    else if (*data == *node->data)
        return nullptr;
    else
        node->right = insertHelper(node->right, data);
    
    return node;
}

void BinTree::bstreeToArrayHelper(Node* node, NodeData* arr[], int &i)  {
    if (node == nullptr)    {
        return;
    }

    if (node->left != nullptr)  {
        bstreeToArrayHelper(node->left, arr, i);
    }

    arr[i] = node->data;
    i++;

    if (node->right != nullptr) {
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