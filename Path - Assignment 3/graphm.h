#ifndef GRAPHM_H
#define GRAPHM_H
#include "nodedata.h"
#include "graphl.h"
#include <iostream>
#include <fstream>
using namespace std;

struct TableType    {
    bool visited;
    int dist;
    int path;
};

class GraphM    {
public:
    // Constructor
    GraphM();

    void buildGraph(ifstream& file);
    void findShortestPath();
    bool insertEdge(int from, int to, int dist);
    bool removeEdge(int from, int to);
    void display(int from, int to);
    void displayAll();

    
private:
    NodeData data[MAXNODES];            // data for graph nodes
    int C[MAXNODES][MAXNODES];          // Cost array, the adjacency matrix
    int size;                           // number of nodes in the graph
    TableType T[MAXNODES][MAXNODES];    // stores visited, distance, path

    // Helper Functions
    int dijkstras(int source);
    int findMinimum(int source);
    void path(int from, int to);
    void info(int from, int to);
};

#endif