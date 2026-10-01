
#include <iostream>
#include <vector>

using namespace std;

// Function to perform DFS traversal from a given node
void dfsRecursive(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    // Mark the current node as visited and print it
    visited[node] = true;
    cout << node << " ";

    // Recur for all the vertices adjacent to this vertex
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, adj, visited);
        }
    }
}

int main() {
    int nodes = 5; // Number of vertices in the graph
    vector<vector<int>> adj(nodes);

    // Initializing an adjacency list for an undirected graph
    // Edges: (0-1), (0-2), (1-3), (1-4)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    // Vector to keep track of visited nodes
    vector<bool> visited(nodes, false);

    cout << "DFS Traversal starting from node 0: ";
    dfsRecursive(0, adj, visited);
    cout << endl;

    return 0;
}
