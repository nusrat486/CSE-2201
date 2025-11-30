#include <bits/stdc++.h>
using namespace std;

bool visited[100];       // visited nodes track করার জন্য
int adj[100][100];       // adjacency matrix
int n, m;                // n = number of nodes, m = number of edges

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 1; i <= n; i++) {   // node 1 থেকে n পর্যন্ত check
        if (adj[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    cin >> n >> m;  // nodes and edges
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;   // undirected graph
    }

    dfs(1);  // start DFS from node 1
}
