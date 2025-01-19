#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

void print(vector<int>& v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed graph

        // create an edge from u to v
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

void bfs(unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited, vector<int>& ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // store front node in ans
        ans.push_back(frontNode);

        // traverse all neighbours of node
        for (auto i : adj[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>>& edges) {
    unordered_map<int, list<int>> adj;
    vector<int> ans;
    unordered_map<int, bool> visited;

    // Create adjacency list from edges
    for (auto edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first); // For undirected graph
    }

    // Traverse all components of the graph
    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfs(adj, visited, ans, i);
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of nodes: " << endl;
    cin >> n;

    int m;
    cout << "Enter the number of edges: " << endl;
    cin >> m;

    graph g;
    vector<pair<int, int>> edges;

    cout << "Enter the edges (u v): " << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        g.addEdge(u, v, 0);
    }

    // Printing graph
    cout << "Printing adjacency list:" << endl;
    g.printAdjList();

    // Perform BFS
    vector<int> ans = BFS(n, edges);

    // Print BFS result
    cout << "BFS Traversal: ";
    print(ans);

    return 0;
}
