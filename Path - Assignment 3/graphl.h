#ifndef GRAPHL_H
#define GRAPHL_H
#include "nodedata.h"
#include <iostream>
#include <fstream>
using namespace std;

const int MAXNODES = 100;

struct EdgeNode {
    int adjGraphNode;
    EdgeNode* nextEdge;
};

struct GraphNode    {
    EdgeNode* edgeHead;
    NodeData* data;
    bool visited;
};

class GraphL    {
public:
    GraphL();
    ~GraphL();

    void buildGraph(ifstream& file);
    void depthFirstSearch();
    void displayGraph();

    // Helper Functions
    void DFSHelper(int idx);

private:
    int size;
    GraphNode nodes[MAXNODES];

    void empty();
    void DFSHelper(int n);
};

#endif