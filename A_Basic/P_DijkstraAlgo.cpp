#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <list>
#include <climits>
using namespace std;

class graph {
public:
    unordered_map<int, list<pair<int, int>>> adj;

    void addEdge(int u, int v, int weight) {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }

    void printAdj() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << "(" << j.first << " ," << j.second << "), ";
            }
            cout << endl;
        }
    }
};

int main() {
    graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(1, 0, 5);
    g.addEdge(1, 2, 9);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 0, 8);
    g.addEdge(2, 3, 6);
    g.addEdge(3, 1, 2);
    g.addEdge(3, 2, 6);

    g.printAdj();

    // Get the number of nodes dynamically
    int n = 0;
    for (auto i : g.adj) {
        n = max(n, i.first);
        for (auto j : i.second) {
            n = max(n, j.first);
        }
    }
    n += 1; // Adjust for 0-based indexing

    int src = 0;
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> st; // {distance, node}

    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        // Fetch top record
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        // Remove top record
        st.erase(st.begin());

        // Traverse on neighbors
        for (auto neighbour : g.adj[topNode]) {
            if (nodeDistance + neighbour.second < dist[neighbour.first]) {
                auto record = st.find({dist[neighbour.first], neighbour.first});
                // If record found then erase it
                if (record != st.end()) {
                    st.erase(record);
                }

                // Distance update
                dist[neighbour.first] = nodeDistance + neighbour.second;
                // Record push in set
                st.insert({dist[neighbour.first], neighbour.first});
            }
        }
    }

    // Print distances
    cout << "Shortest distances from node " << src << " are:\n";
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) {
            cout << "Node " << i << " is unreachable\n";
        } else {
            cout << "Node " << i << " : " << dist[i] << endl;
        }
    }

    return 0;
}
