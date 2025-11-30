#include <iostream>
using namespace std;

#define MAX 100  // maximum number of nodes

int adj[MAX][MAX]; // adjacency matrix
bool visited[MAX];
int order[MAX];
int top = -1;

int n, m;

// DFS function
void topologicalDFS(int node) {
    visited[node] = true;
    for (int i = 1; i <= n; i++) {
        if (adj[node][i] && !visited[i]) {
            topologicalDFS(i);
        }
    }
    order[++top] = node; // push node to order array
}

int main() {
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    cout << "Enter edges (u v) where u -> v:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    for (int i = 1; i <= n; i++) visited[i] = false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            topologicalDFS(i);
        }
    }

    cout << "Topological Sort: ";
    for (int i = top; i >= 0; i--) {
        cout << order[i] << " ";
    }
    cout << endl;

    return 0;
}

