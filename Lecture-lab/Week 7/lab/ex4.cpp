#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int numVertices;
    list<int> *adjLists;
    bool *visited;

public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void BFS(int startVertex);
    void printGraph();
};

Graph::Graph(int vertices)
{
    numVertices = vertices;
    adjLists = new std::list<int>[vertices];
    visited = new bool[vertices];
}

void Graph::addEdge(int v, int w)
{
    adjLists[v].push_back(w);
    adjLists[w].push_back(v);
}

void Graph::BFS(int startVertex)
{
    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
    }

    queue<int> queue;
    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty())
    {
        int currVertex = queue.front();
        cout << "Visited " << currVertex << " --> ";
        queue.pop();

        for (int adjVertex : adjLists[currVertex])
        {
            if (!visited[adjVertex])
            {
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
    cout << endl;
}

void Graph::printGraph()
{
    for (int i = 0; i < numVertices; i++)
    {
        cout << i << ": ";
        for (int adjVertex : adjLists[i])
        {
            cout << adjVertex << " ";
        }
        cout << endl;
    }
}

int main()
{
    Graph graph(5);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    cout << "Graph Adjacency List:" << endl;
    graph.printGraph();

    graph.BFS(0);

    return 0;
}

// Output:
// Graph Adjacency List:
// 0: 1 2 3 
// 1: 0 3 4 
// 2: 0 3 
// 3: 0 1 2 4 
// 4: 1 3 
// Visited 0 --> Visited 1 --> Visited 2 --> Visited 3 --> Visited 4 --> 