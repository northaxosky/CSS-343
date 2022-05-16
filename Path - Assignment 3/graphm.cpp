#include <climits>
#include <string>
#include "graphm.h"


//---------------------- Default Constructor ---------------------------------
GraphM::GraphM() {
    size = 0;
    for (int i = 0; i < MAXNODES; ++i)
    {
        for (int j = 0; j < MAXNODES; ++j)
        {
            C[i][j] = INT_MAX;         
            T[i][j].visited = false;    
            T[i][j].dist = INT_MAX;    
            T[i][j].path = 0;          
        } 
    } 
}

//---------------------- buildGraph() ----------------------------------------
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

//---------------------- insertEdge() ----------------------------------------
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

//---------------------- removeEdge() ----------------------------------------

bool GraphM::removeEdge(int from, int to)   {
    if (to > size || to < 1 ||
        from > size || from < 1)
            return false;

    C[from][to] = INT_MAX;
    findShortestPath();
    return true;
}

//---------------------- findShortestPath() ----------------------------------

void GraphM::findShortestPath(void) {
    int num, v;
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            T[i][j].dist = INT_MAX;
            T[i][j].path = 0;
            T[i][j].visited = false;
        } 
    } 

    for (int source = 1; source <= size; ++source)  {
        num = 0;
        T[source][source].dist = 0;

        while(num < size) {
            v = visit(source);
            T[source][v].visited = true;
            ++num;
            path(source, v);
        } 
    } 
} 

//---------------------- visit() -----------------------------------------
int GraphM::visit(int source)   {
    int v = 0;

    for (int i = 1; i <= size; ++i) {
        if (!T[source][i].visited)  {
            if (T[source][i].dist < T[source][v].dist)  {
                v = i;
            } 
        } 
    } 
    return v;
}

//---------------------- path --- ------------------------------------------
// Sets the current shortest path information on all nodes adjacent to the
// visited node.
void GraphM::path(int source, int v)
{
    for (int w = 1; w <= size; ++w) {
        if (!T[source][w].visited && C[v][w] < INT_MAX &&
             T[source][v].dist < INT_MAX)   {
            if (T[source][w].dist > (T[source][v].dist + C[v][w]))  {
                T[source][w].dist = T[source][v].dist + C[v][w];
                T[source][w].path = v;
            } 
        } 
    } 
}

//---------------------- displayAll() ----------------------------------------

void GraphM::displayAll()
{
    findShortestPath();
    cout.width(26);
    cout << left << "Description";
    cout.width(11);
    cout << "From node";
    cout.width(9);
    cout << "To node";
    cout.width(12);
    cout << "Dijkstra's";
    cout.width();
    cout << "Path" << endl;

    for (int source = 1; source <= size; ++source)  {
        displayFrom(source);
    }

    cout << endl;
}

//---------------------- displayFrom() ---------------------------------------
void GraphM::displayFrom(int from)    {
    cout.width(32);
    cout << left << data[from] << endl;

    for (int to = 1; to <= size; ++to)    {
        if (to != from) {
            cout.width(35);
            cout << right << from;
            cout.width(5);
            cout << to;
            cout.width(14);

            if (T[from][to].dist == INT_MAX){
                cout << "----" << endl;
            }
            else{
                cout << T[from][to].dist;
                cout.width();
                cout << "    ";
                displayPath(from, to);
                cout << to << endl;
            } 
        } 
    }
} 

//---------------------- displayPath() ---------------------------------------
void GraphM::displayPath(int from, int to)  {
    findShortestPath();
    if (T[from][to].path != 0)  {
        displayPath(from, T[from][to].path);
        cout << T[from][to].path << ' ';
    }
}

//---------------------- display() 0------------------------------------------

void GraphM::display(int source, int dest)  {
        if (T[source][dest].dist < INT_MAX){
            cout.width(4);
            cout << right << source;
            cout.width(8);
            cout << dest;
            cout.width(8);
            cout << T[source][dest].dist;
            cout << "        ";
            displayPath(source, dest);
            cout << source << endl << data[dest] << endl;
            descending(source, dest);
        }
        else{
            cout << "No path from " << source << " to " << dest << '.' << endl;
        } 

    cout << endl;
} 

//---------------------- pathDesc() ------------------------------------------

void GraphM::descending(int from, int to)   {
    if (T[from][to].path != 0)  {
        descending(from, T[from][to].path);
        cout << data[to] << endl;
    } 
}