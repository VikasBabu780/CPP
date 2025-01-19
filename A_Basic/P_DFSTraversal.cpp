#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <list>
using namespace std;

void print2Dvector(const vector<vector<int>>& v) {
    for (const auto& component : v) {
        for (int node : component) {
            cout << node << " ";
        }
        cout << endl;
    }
}

class Graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        // Create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

void dfs(int node, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj, vector<int>& component) {
    component.push_back(node);
    visited[node] = true;

    for (auto i : adj[node]) {
        if (!visited[i]) {
            dfs(i, visited, adj, component);
        }
    }
}

vector<vector<int>> DFS(int v, unordered_map<int, list<int>>& adj) {
    vector<vector<int>> ans;
    unordered_map<int, bool> visited;

    for (auto i : adj) {
        if (!visited[i.first]) {
            vector<int> component;
            dfs(i.first, visited, adj, component);
            ans.push_back(component);
        }
    }
    return ans;
}

int main() {
    int n, m;
    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> m;

    Graph g;
    cout << "Enter the edges (u v):" << endl;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // Undirected graph
    }

    // Print adjacency list
    cout << "Printing adjacency list:" << endl;
    g.printAdjList();

    // Perform DFS
    vector<vector<int>> ans = DFS(n, g.adj);

    // Print DFS result
    cout << "DFS Traversal (Connected Components):" << endl;
    print2Dvector(ans);

    return 0;
}
