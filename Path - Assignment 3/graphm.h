#ifndef GRAPHM_H
#define GRAPHM_H
#include "nodedata.h"
#include <iostream>
#include <fstream>
using namespace std;

const int MAXNODES = 100;

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
    NodeData data[MAXNODES];
    int C[MAXNODES][MAXNODES];
    int size;
    TableType T[MAXNODES][MAXNODES];
};

#endif