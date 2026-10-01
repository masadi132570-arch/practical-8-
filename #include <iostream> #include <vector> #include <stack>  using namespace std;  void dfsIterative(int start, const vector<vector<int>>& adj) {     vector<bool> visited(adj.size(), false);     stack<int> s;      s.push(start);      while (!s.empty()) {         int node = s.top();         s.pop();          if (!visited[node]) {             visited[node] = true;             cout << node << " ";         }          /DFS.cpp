#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfsIterative(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!visited[node]) {
            visited[node] = true;
            cout << node << " ";
        }

        // Push neighbors to stack in reverse order to match recursive traversal order
        for (auto it = adj[node].rbegin(); it != adj[node].rend(); ++it) {
            if (!visited[*it]) {
                s.push(*it);
            }
        }
    }
}
