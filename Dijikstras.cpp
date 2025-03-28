#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

const int inf = INT_MAX;

// Dijikstras Algorithm Using A MinHeap

vector<int> dijkstra(vector<vector<pair<int, int>>> adjList, int src) {
int n = adjList.size();

// What I want to store in my priority queue (aka a min heap)
// how I want to store it
// the greater function to make this a min heap

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
// a distance vector that we initialize to a rather large number, inf
vector<int> dist(n, inf);

minHeap.push(make_pair(0, src));
dist[src] = 0;

while (! minHeap.empty())
{
    int u = minHeap.top().second; // compares vertex u with the smallest distance
    minHeap.pop();

    // Iterate over all neighbors of vertex u
    for (auto neighbor : adjList[u]) {

        int v = neighbor.first;
        int weight = neighbor.second;

        if (dist[u] + weight < dist[v])
        {
            dist[v] = dist[u] + weight;
            minHeap.push(make_pair(dist[v], v));
        }
    }
}
return dist;
}

// Convert an adjacency matrix to an adjacency list

vector<vector<pair<int, int>>> convertToAdjacencyList(vector<vector<int>> adjMatrix)
{
    int n = adjMatrix.size(); // Find my total number of vertices

    vector<vector<pair<int, int>>> adjList(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // we find a connection if != 0
            if (adjMatrix[i][j] != 0) {
                adjList[i].emplace_back(make_pair(j, adjMatrix[i][j]));

            }
        }
    }
    return adjList;
}

int main() {

    // Our graph from Prim's slides (nice graph for this purpose)
    vector<vector<int>> adjMatrix = {
            {0,4,0,0,0,0,0,8,0},
            {4,0,8,0,0,0,0,11,0},
            {0,8,0,7,0,4,0,0,2},
            {0,0,7,0,9,14,0,0,0},
            {0,0,0,9,0,10,0,0,0},
            {0,0,4,14,10,0,2,0,0},
            {0,0,0,0,0,2,0,1,6},
            {8,11,0,0,0,0,1,0,7},
            {0,0,2,0,0,0,6,7,0}
    };

    // Converts to an adjacency list
    vector<vector<pair<int, int>>> adjList = convertToAdjacencyList(adjMatrix);
    vector<int> distances = dijkstra(adjList, 0);

    cout << "Vertex distance from source" << endl;
    for (int i = 0; i < distances.size(); i++)
    {
        cout << i << "\t\t" << distances[i] << endl;
    }

}
