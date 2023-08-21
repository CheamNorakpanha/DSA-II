#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjMatrix;
int count = 0;

void displayMatrix(int v)
{
    for (int i = 0; i < v; ++i)
    {
        for (int j = 0; j < v; ++j)
        {
            cout << adjMatrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void add_edge(int u, int v)
{
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1;
}

void removeEdge(int u, int v)
{
    adjMatrix[u][v] = 0;
    adjMatrix[v][u] = 0;
}

int main()
{
    int v = 4; // Number of vertices

    // Initialize the adjacency matrix with zeros
    adjMatrix.resize(v, vector<int>(v, 0));

    cout << "Original Edge:" << endl;
    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(0, 3);
    add_edge(1, 0);
    add_edge(1, 2);
    add_edge(2, 0);
    add_edge(2, 1);
    add_edge(3, 0);

    displayMatrix(v);
    cout << endl;

    cout << "Unoriginal Edge:" << endl;
    removeEdge(1, 2);

    displayMatrix(v);
    cout << endl;

    return 0;
}

// Output:
// Original Edge:
// 0       1       1       1
// 1       0       1       0
// 1       1       0       0
// 1       0       0       0

// Unoriginal Edge:
// 0       1       1       1
// 1       0       0       0
// 1       0       0       0
// 1       0       0       0