#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Breadth-First Search traversal from a given source node
void bfs(int startNode, const vector<vector<int>>& adjList) {
    // Vector to track visited nodes, initialized to false
    vector<bool> visited(adjList.size(), false);
    
    // Queue to manage the order of node exploration (FIFO)
    queue<int> q;

    // Mark the starting node as visited and push it into the queue
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal starting from node " << startNode << ": ";

    while (!q.empty()) {
        // Dequeue the front node and print it
        int currentNode = q.front();
        q.pop();
        cout << currentNode << " ";

        // Explore all adjacent neighbors of the current node
        for (int neighbor : adjList[currentNode]) {
            // If a neighbor hasn't been visited yet, mark it visited and enqueue it
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

int main() {
    // Define the total number of nodes in the graph
    int numNodes = 6;
    
    // Initialize an adjacency list for 6 nodes (0 to 5)
    vector<vector<int>> adjList(numNodes);

    // Add edges to create an undirected graph
    // Node 0 connections
    adjList[0].push_back(1);
    adjList[0].push_back(2);
    
    // Node 1 connections
    adjList[1].push_back(0);
    adjList[1].push_back(3);
    adjList[1].push_back(4);
    
    // Node 2 connections
    adjList[2].push_back(0);
    adjList[2].push_back(4);
    
    // Node 3 connections
    adjList[3].push_back(1);
    adjList[3].push_back(5);
    
    // Node 4 connections
    adjList[4].push_back(1);
    adjList[4].push_back(2);
    adjList[4].push_back(5);
    
    // Node 5 connections
    adjList[5].push_back(3);
    adjList[5].push_back(4);

    // Run BFS starting from Node 0
    bfs(0, adjList);

    return 0;
}
