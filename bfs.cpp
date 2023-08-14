#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Breadth-First Search
void BFS(vector<vector<int>>& graph, int startVertex) {
    int numVertices = graph.size();

    // Create a boolean array to track visited vertices
    vector<bool> visited(numVertices, false);

    // Create a queue for BFS
    queue<int> bfsQueue;

    // Mark the current vertex as visited and enqueue it
    visited[startVertex] = true;
    bfsQueue.push(startVertex);

    cout << "BFS Traversal: ";

    while (!bfsQueue.empty()) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = bfsQueue.front();
        bfsQueue.pop();
        cout << currentVertex << " ";

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it
        // as visited and enqueue it
        for (int i = 0; i < numVertices; ++i) {
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                bfsQueue.push(i);
            }
        }
    }

    cout << endl;
}

int main() {
    int numVertices, startVertex;

    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    vector<vector<int>> graph(numVertices, vector<int>(numVertices, 0));

    cout << "Enter the adjacency matrix: " << endl;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter the starting vertex: ";
    cin >> startVertex;

    BFS(graph, startVertex);

    return 0;
}
