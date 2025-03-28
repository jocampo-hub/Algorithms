#include  <iostream>
#include <vector>
#include <unordered_set>
#include <climits>
using namespace std;

// Minimum spanning tree function
int printMST(vector<int> parent, vector<vector<int>> graph)
{
    cout << "Edge Weight" << endl;
    int totalWeight = 0; // Sum of all the edge weights
    for (int i = 1; i < parent.size(); i++)
    {
        cout << parent[i] << " <-> " << i << "  " << graph[i][parent[i]] << endl;
        totalWeight  += graph[i][parent[i]];

    }
    return totalWeight;
}

// Find the vertex with the minimum value from the set of vertices we have yet to include in our solution.

// inSolution is what has already been accounted for.
int findMinimalVertex(vector<int> key, unordered_set<int> inSolution, int numVertices)
{
    int min = INT_MAX; // ideally we pick a number larger than any edge in our graph, and max is
                        // bigger than any edge in our map
      int min_index = -1;

      for (int v = 0; v < numVertices; v++)
      {
          // need to check if something is a member of a set or not.
          // First part of conditional logic is check to see if the vertex is already present.
         if (inSolution.find(v) == inSolution.end() && key[v] < min)
         {
             min = key[v];
             min_index = v;
         }
      }

      return min_index;
}

void primMST(vector<vector<int>> graph)
{
    int numberVertices = graph.size();
    vector<int> parent(numberVertices); // Vector to store my MST
    vector<int> key(numberVertices, INT_MAX); // picking my minimum weight edge
    unordered_set<int> inSolution; // Vertices I have already seen and are accounted for

    // be lazy and start with the first vertex
    key[0] = 0;
    parent[0] = -1;


    // Loop should run v-1 times, since we have v-1 edges in our solution for v vertices

    for (int count = 0; count < numberVertices-1; count++)
    {
        int u = findMinimalVertex(key, inSolution, numberVertices);
        // I need to update my sett to include u as a vertex
        inSolution.insert(u);
        // Update key value and parent index of adj vertices of this picked vertex

        for (int v = 0; v < numberVertices; v++)
        {
            if (graph[u][v] != 0 && inSolution.find(v) == inSolution.end() && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    // Print out the constructed MST
    int totalWeight = printMST(parent, graph);
    cout << "Total weight of MST is: " << totalWeight << endl;
}

int main()
{

            vector<vector<int>> graph = {
                {0, 4,  0, 0,  0,  0,  0,  8, 0},
                {4, 0,  8, 0,  0,  0,  11, 0},
                {0, 8,  0, 7,  0,  4,  0,  0, 2},
                {0, 0,  7, 0,  9,  14, 0,  0, 0},
                {8, 0,  0, 9,  0,  10, 0,  0, 0},
                {0, 0,  4, 14, 10, 0,  2,  0, 0},
                {0, 0,  0, 0,  0,  2,  0,  1, 6},
                {8, 11, 0, 0,  0,  0,  1,  0, 7},
                {0, 0,  2, 0,  0,  0,  6,  7, 0}
            };

    primMST(graph);
}


