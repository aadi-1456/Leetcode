#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCycle(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = 1;
        queue<pair<int, int>> q;
        q.push({node, -1});

        while (!q.empty()) {
            int current = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto neighbor : adj[current]) {
                if (visited[neighbor]!=1) {
                    visited[neighbor] = 1;
                    q.push({neighbor, current});
                }
                else if (neighbor != parent) {
                    return true; // cycle found
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        // Convert edge list to adjacency list
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detectCycle(i, adj, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
