#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];

void bellmanFord(int source, int V, int E) {
    vector<int> dist(V + 1, INF);
    dist[source] = 0;

    // Relax edges V-1 times
    for (int i = 1; i <= V - 1; ++i) {
        for (int u = 1; u <= V; ++u) {
            for (auto edge : g[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 1; u <= V; ++u) {
        for (auto edge : g[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                cout << "Graph contains a negative-weight cycle\n";
                return;
            }
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 1; i <= V; ++i) {
        if (dist[i] != INF) {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        } else {
            cout << "Vertex " << i << ": Not reachable\n";
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    cout << "Enter the starting vertex, ending vertex, and weight of each edge:\n";
    for (int i = 0; i < E; ++i) {
        int x, y, wt;
        cin >> x >> y >> wt;
        g[x].push_back({y, wt});
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(source, V, E);

    return 0;
}
