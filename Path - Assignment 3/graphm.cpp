// ====================== GraphM.cpp ======================
// Kuzey Gok
// CSS 343
// Description:
// Read data from file and find the shortest path to each node
// using Dijkstra's shortest path algorithm.
// ========================================================
#include "graphm.h"
#include <iomanip>

// Constructor for GraphM
//=========================================================
GraphM::GraphM()    {
    size = 0;
    for (int i = 1; i < MAXNODES; i++)  {
        for (int j = 1; j < MAXNODES; j++)  {
            C[i][j] = INT_MAX;
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
    for (int source = 1; source <= size; source++)  {
        T[source][source].dist = 0;
        for (int i = 1; i <= size; i++) {
            int step = 0;
            int path = INT_MAX;
            for (int j = 1; j <= size; j++) {
                if (T[source][j].dist < path && !T[source][j].visited)  {
                    path = T[source][j].dist;
                    step = j;
                    T[source][step].visited = true;
                }
            }

            if (step == 0)
                break;

            for (int j = 1; j <= size; j++) {
                if (C[step][j] != INT_MAX  &&
                    T[source][j].dist > T[source][step].dist + C[step][j]) {
                        T[source][j].dist = T[source][step].dist + C[step][j];
                        T[source][j].path = step;
                }
            }
        }
    }
    // for (int source = 1; source <= size; source++)  {
    //     T[source][source].dist = 0;
    //     T[source][source].visited = true;

    //     for (int j = 1; j <= size; j++) {
    //         if (C[source][j] != INT_MAX)   {
    //             T[source][j].dist = C[source][j];
    //             T[source][j].path = source;
    //         }
    //     }
    //     int min = -1;
    //     while (min != 0)    {
    //         min = dijkstras(source);
    //     }
    // }
}

// Helper function for findShortestPath
//=========================================================
int GraphM::dijkstras(int source)  {
    int min = findMinimum(source);
    if (min == 0)
        return min;

    T[source][min].visited = true;
    for (int i = 1; i <= size; ++i)  {
        if (T[source][i].visited ||
            C[min][i] == INT_MAX ||
            min == i)
                continue;

        if (T[source][i].dist > T[source][min].dist + C[min][i])    {
            T[source][i].dist = T[source][min].dist + C[min][i];
            T[source][i].path = min;
        }
    }

    return min;
}

// Helper function for findShortestPath
//=========================================================
int GraphM::findMinimum(int source)    {
    int min = INT_MAX;
    int idx = 0;

    for (int i = 1; i <= size; i++) {
        if (!T[source][i].visited && C[source][i] < min)    {
            min = C[source][i];
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
    findShortestPath();
    return true;
}

// Function to remove an edge given its start and end
//=========================================================
bool GraphM::removeEdge(int from, int to)   {
    if (to > size || to < 1 ||
        from > size || from < 1)
            return false;

    C[from][to] = INT_MAX;
    findShortestPath();
    return true;
}

// Function to display shortest distance from node to another
//=========================================================
void GraphM::display(int from, int to)  {
    if (from > size || from < 0 ||
        to > size || to < 0)    {
            cout << from << "         " <<
            to  << "      ----" << endl;
    }
    else    {
        cout << "       " << from << "       " << to;
        if (T[from][to].dist == INT_MAX)
            cout << "     ----" << endl;
        else    {
            cout << "         " << T[from][to].dist << "         ";
            path(from, to);
            cout << endl;
            info(from, to);
        }
    }
    cout << endl;
}

// Function to display shortest path of all nodes
//=========================================================
void GraphM::displayAll()   {
    cout << "Description:        " << "From Node:  " <<
    "To Node:  " << "Dijkstra's:    " << "Path" << endl;

    for (int i = 1; i <= size; i++) {
        cout << data[i] << "\n\n";

        for (int j = 1; j <= size; j++) {
            if (T[i][j].dist != 0)    {
                cout << "                        " << i
                << "         " << j;

                if (T[i][j].dist != INT_MAX)   {
                    cout << "        " << T[i][j].dist
                    << "            ";

                    path(i, j);
                    cout << endl;
                }
                else
                    cout << "        " << "----" << endl;
            }
        }
    }
}

// Helper function to print the shortest path from a node to another
//=========================================================
void GraphM::path(int from, int to) {
    if (from == to) 
        cout << to << " ";
    else    {
        int n = to;
        path(from, to = T[from][to].path);
        cout << n << " ";
    } 
}

void GraphM::info(int from, int to) {
    if (from == to)  {
        cout << data[to] << endl;
    }
    else    {
        int n = to;
        info(from, to = T[from][to].path);
        cout << data[n] << endl << endl;
    }
}