// ====================== GraphM.cpp ======================
// Kuzey Gok
// CSS 343
// Description:
// Read data from file and find the shortest path to each node
// using Dijkstra's shortest path algorithm.
// ========================================================
#include "graphm.h"

// Constructor for GraphM
//=========================================================
GraphM::GraphM()    {
    size = 0;
    for (int i = 1; i < MAXNODES; i++)  {
        for (int j = 1; j < MAXNODES; j++)  {
            T[i][j].dist = INT_MAX;
            T[i][j].path = 0;
            T[i][j].visited = false;
        }
    }
}

// BuildGraph function to read from a file and build a graph
//=========================================================
void GraphM::buildGraph(ifstream& file) {
    int from, to, dist;
    file >> size;
    string name;
    getline(file, name);

    for (int i = 1; i <= size; i++) {
        data[i].setData(file);
    }

    while(file >> from >> to >> dist)   {
        if (from == 0 && to == 0 && dist == 0)
            break;
        
        C[from][to] = dist;
    } 
}

//=========================================================
void GraphM::findShortestPath() {

}

//=========================================================
bool GraphM::insertEdge(int from, int to, int dist) {
    if (dist < 0 ||
       (dist != 0 && from == to) ||
       from > size || to > size ||
       from < 1 || to < 1)
        return false;
    
    C[from][to] = dist;
    return true;
}

//=========================================================
bool GraphM::removeEdge(int from, int to)   {
    if (to > size || to < 1 ||
        from > size || from < 1)
            return false;
    
    C[from][to] = INT_MAX;
    return true;
}

//=========================================================
void GraphM::display(int from, int to)  {

}

//=========================================================
void GraphM::displayAll()   {

}