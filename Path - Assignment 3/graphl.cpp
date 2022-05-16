#include "graphl.h"

// Constructor
// ===================================================================
GraphL::GraphL()    {
    size = 0;
    for (int i = 1; i < MAXNODES; i++)  {
        nodes[i].visited = false;
        nodes[i].edgeHead = nullptr;
        nodes[i].data = nullptr;
    }
}

// Destructor
// ===================================================================
GraphL::~GraphL()   {
    for (int i = 1; i <= size; i++) {
        delete nodes[i].data;
        nodes[i].data = nullptr;
        nodes[i].visited = false;
        
        EdgeNode* ptr = nodes[i].edgeHead;
        while (ptr) {
            nodes[i].edgeHead = nodes[i].edgeHead->nextEdge;
            delete ptr;
            ptr = nodes[i].edgeHead;
        }
    }
}

// Function to build a graph using data from a file
// ===================================================================
void GraphL::buildGraph(ifstream& file) {
    int from, to;
    file >> size;
    string str;
    getline(file, str);

    for (int i = 1; i <= size; i++) {
        getline(file, str);
        NodeData* temp = new NodeData(str);
        nodes[i].data = temp;
    }

    while (file >> from >> to)  {
        if (from == 0 && to == 0)
            return;
        
        EdgeNode* node = new EdgeNode;
        node->adjGraphNode = to;

        if (nodes[from].edgeHead)   {
            node->nextEdge = nodes[from].edgeHead;
            nodes[from].edgeHead = node;
        }  
        else    {
            nodes[from].edgeHead = node; 
            nodes[from].edgeHead->nextEdge = nullptr;
        }
    }
}

// Function to do depthFirstSearh and display ordering
// ===================================================================
void GraphL::depthFirstSearch() {
    cout << "Depth-First Search Ordering: ";

    for (int i = 1; i <= size; i++) {
        if (!nodes[i].visited)
            DFSHelper(i);
    }
    cout << endl;
}

// Function to display the graph
// ===================================================================
void GraphL::displayGraph() {
    cout << "Graph: " << endl;

    for (int i = 1; i <= size; i++) {
        cout << "Node #" << i << "\t\t" << *nodes[i].data << "\n\n";

        EdgeNode* curr = nodes[i].edgeHead;
        while (curr)    {
            cout << "  " << "Edge  " << i << "  " << curr->adjGraphNode << endl;
            curr = curr->nextEdge;
        }
        cout << endl; 
    }
}


// Helper Function for depth first search
// ===================================================================
void GraphL::DFSHelper(int idx) {
    cout << "  " << idx;
    nodes[idx].visited = true;
    EdgeNode* curr = nodes[idx].edgeHead;

    while (curr)    {
        if (!nodes[curr->adjGraphNode].visited)
            DFSHelper(curr->adjGraphNode);
        
        curr = curr->nextEdge;
    }
}