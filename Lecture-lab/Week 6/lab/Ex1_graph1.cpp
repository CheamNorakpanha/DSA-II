#include <iostream>
#include <vector>
using namespace std;
// Data structure to store a graph edge
struct Edge
{
    int v, w;
};

class Graph
{
public:
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
    // Graph Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        // resize the vector to hold 'n' elements of type vector<int>
        adjList.resize(n);
        // add edges to the directed graph for (auto &edge : edges)
        for (auto &edge : edges)
        {
            // insert at the end
            adjList[edge.v].push_back(edge.w);
            // uncomment the following code for undirected graph / adjList[edge.w].push_back(edge.v);
            // adjList[edge.w].push_back(edge.v);
        }
    }
};

// Function to print adjacency list representation of a graph
void printGraph(Graph const &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        // print the current vertex number cout «‹ i «‹ " -> ";
        // print all neighboring vertices of a vertex 'i' for (int v : graph.adjList[i])
        {
            cout << i << " -> ";
            // print all neighboring vertices of a vertex 1`
            for (int v : graph.adjList[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
}

//  Graph Implementation usign STL

int main()
{ 
    // vector of graph edges as per the above diagram.
// Please note that the initialization vector in the below format will
// I work fine in C++11, C++14, C++17 but will fail in C++98.
    vector <Edge> edge = 
    {
        {0,1}, {0,2}, {0,3}, {1,3}, {1,4}, {2,3}, {3,4}
    };
    // total number of nodes in the graph (labelled form 0 to 5)

    int n = 5;
    // construct graph
    Graph graph (edge, n);
    // print adjacency list representation of a graph
    printGraph(graph, n);

    return 0;
}