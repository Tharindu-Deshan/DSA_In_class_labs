#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define V 6

int minKey(const vector<int>& key, const vector<bool>& mstSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; ++v) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

void printMST(const vector<int>& parent, const vector<vector<int>>& graph) {
    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < V; ++i) {
        cout << "Edge: " << parent[i] << " - " << i << ", Cost: " << graph[i][parent[i]] << endl;
    }
}

void primMST(const vector<vector<int>>& graph) {
    vector<int> parent(V); // Store MST
    vector<int> key(V, INT_MAX); // Key values used to pick the minimum weight edge
    vector<bool> mstSet(V, false); // To track vertices included in MST

    key[0] = 0; // Start with the first node
    parent[0] = -1;

    for (int count = 0; count < V - 1; ++count) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    vector<vector<int>> graph = {
            {0, 3, 0, 0, 0, 1},
            {3, 0, 2, 1, 10, 0},
            {0, 2, 0, 3, 0, 5},
            {0, 1, 3, 0, 5, 0},
            {0, 10, 0, 5, 0, 4},
            {1, 0, 5, 0, 4, 0}
    };

    primMST(graph);

    return 0;
}
