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

// findShortestPath function to find the shortest path from
// a node to every node using Djikstra's Shortest Path Algo
//=========================================================
void GraphM::findShortestPath() {
    for (int source = 1; source <= size; source++) {
        T[source][source].dist = 0;
        T[source][source].visited = true;
        
        for (int i = 0; i <= size; i++) {
            if (C[source][i] != INT_MAX)    {
                T[source][i].dist = C[source][i];
                T[source][i].path = source;
            }
        }
        dijkstras(source);
    }

        // finds the shortest distance from source to all other nodes
        // for (int i = 1; i<= size; i++) {
        //     find v //not visited, shortest distance at this point
        //     mark v visited  
        //     for each w adjacent to v
        //     if (w is not visited)
        //         T[source][w].dist=min(T[source][w].dist, T[source][v].dist+C[V][W]) 
        // }
}

// Helper function for findShortestPath
//=========================================================
void GraphM::dijkstras(int source)  {
    int min = findMinimum(source);
    if (min == 0)
        return;
    
    T[source][min].visited = true;
    for (int i = 1; i <= size; i++)  {
        if (T[source][i].visited ||
            C[min][i] == INT_MAX ||
            min == i)
                continue;

        int compare = T[source][min].dist + C[min][i];
        if (T[source][i].dist > compare)    {
            T[source][i].dist = compare;
            T[source][i].path = min;
        }    
    }
}

// Helper function for findShortestPath
//=========================================================
int GraphM::findMinimum(int source)    {
    int min = INT_MAX;
    int idx = 0;

    for (int i = 1; i <= size; i++) {
        if (!T[source][i].visited && T[source][i].dist <= min)  {
            min = T[source][i].dist;
            idx = i;
        }
    }
    return idx;
}

// Function to insert edge given its vertices and val
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