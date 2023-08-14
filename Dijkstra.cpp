#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;
vector<pair<int, int>> g[N];

void dijkstra(int source) {
    vector<int> dist(N, INF);
    vector<bool> vis(N, false);
    dist[source] = 0;

    // Create a min heap using priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (vis[u]) continue;
        vis[u] = true;

        for (auto edge : g[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!vis[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the shortest distances from the source vertex
    cout << "Shortest distances from source vertex " << source << ":\n";
    for (int i = 1; i < N; ++i) {
        if (dist[i] != INF) {
            cout << "Vertex " << i << ": " << dist[i] << "\n";
        } else {
            cout << "Vertex " << i << ": Not reachable\n";
            break; // Break the loop if a vertex is not reachable
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
        g[y].push_back({x, wt}); // Assuming an undirected graph
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    dijkstra(source);

    return 0;
}
