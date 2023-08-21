#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<vector<pair<int, int>>>& adj, int u, int v, int wt)
{
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

void printGraphList(const vector<vector<pair<int, int>>>& adj)
{
    for (int u = 1; u < adj.size(); ++u)
    {
        cout << "Vertex " << u << " -> ";
        for (const auto& neighbor : adj[u])
        {
            cout << neighbor.first << " (Weight: " << neighbor.second << ") ";
        }
        cout << endl;
    }
}

int main()
{
    int V = 5;  // Number of vertices
    vector<vector<pair<int, int>>> adj(V);

    addEdge(adj, 1, 2, 5);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 3, 4, 2);

    printGraphList(adj);

    return 0;
}

// Output:
// Vertex 1 -> 2 (Weight: 5) 3 (Weight: 6) 
// Vertex 2 -> 1 (Weight: 5) 3 (Weight: 3) 
// Vertex 3 -> 1 (Weight: 6) 2 (Weight: 3) 4 (Weight: 2)    
// Vertex 4 -> 3 (Weight: 2) 