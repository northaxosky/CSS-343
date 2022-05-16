#include "graphl.h"

GraphL::GraphL()    {
    size = 0;
    for (int i = 1; i < MAXNODES; i++)  {
        nodes[i].visited = false;
        nodes[i].edgeHead = nullptr;
        nodes[i].data = nullptr;
    }
}

GraphL::~GraphL()   {
    for (int i = 0; i <= size; i++) {
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

void GraphL::buildGraph(ifstream& file) {
    int from, to;
    file >> size;
    string str;
    getline(file, str);

    for (int i = 1; i <= size; i++) {
        getline(file, str);
        NodeData* data = new NodeData(str);
        nodes[i].data = data;
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
        else    
            nodes[from].edgeHead = node; 
    }
}