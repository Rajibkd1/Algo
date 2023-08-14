#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compare(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

int findParent(vector<int>& parent, int vertex) {
    if (parent[vertex] != vertex) {
        parent[vertex] = findParent(parent, parent[vertex]);
    }
    return parent[vertex];
}

void unionSets(vector<int>& parent, int src, int dest) {
    parent[src] = dest;
}

vector<Edge> kruskalMST(int V, int E, vector<Edge>& edges) {
    vector<Edge> result;
    vector<int> parent(V);

    // Initialize parent array
    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), compare);

    int edgeCount = 0;
    int i = 0;

    while (edgeCount < V - 1 && i < E) {
        Edge nextEdge = edges[i++];

        int srcParent = findParent(parent, nextEdge.src);
        int destParent = findParent(parent, nextEdge.dest);

        // Add edge to MST if it doesn't create a cycle
        if (srcParent != destParent) {
            result.push_back(nextEdge);
            unionSets(parent, srcParent, destParent);
            edgeCount++;
        }
    }

    return result;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter the edges (src dest weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    vector<Edge> mst = kruskalMST(V, E, edges);

    cout << "Edges in the Minimum Spanning Tree (MST):" << endl;
    for (const Edge& edge : mst) {
        cout << edge.src << " " << edge.dest << " " << edge.weight << endl;
    }

    return 0;
}
