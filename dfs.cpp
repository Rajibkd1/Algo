#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform Depth-First Search
void DFS(vector<vector<int>>& graph, int startVertex) {
    int numVertices = graph.size();

    // Create a boolean array to track visited vertices
    vector<bool> visited(numVertices, false);

    // Create a stack for DFS
    stack<int> dfsStack;

    // Mark the current vertex as visited and push it onto the stack
    visited[startVertex] = true;
    dfsStack.push(startVertex);

    cout << "DFS Traversal: ";

    while (!dfsStack.empty()) {
        // Pop a vertex from the stack and print it
        int currentVertex = dfsStack.top();
        dfsStack.pop();
        cout << currentVertex << " ";

        // Get all adjacent vertices of the popped vertex
        // If an adjacent vertex has not been visited, mark it
        // as visited and push it onto the stack
        for (int i = 0; i < numVertices; ++i) {
            if (graph[currentVertex][i] && !visited[i]) {
                visited[i] = true;
                dfsStack.push(i);
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

    DFS(graph, startVertex);

    return 0;
}
