#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int cost[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cost[i][j] = 0;
            else cost[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; i++) {///input edge
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
        cost[v][u] = w;
    }

    int source;
    cin >> source;

    int dist[n];
    bool visited[n];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int k = 0; k < n - 1; k++) {//relaxation loop
        int u = -1;//no node selected
        int mn = INT_MAX;//minimum

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < mn) {
                mn = dist[i];
                u = i;
            }
        }

        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != INT_MAX) {
                if (dist[u] + cost[u][v] < dist[v]) {
                    dist[v] = dist[u] + cost[u][v];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF ";
        else
            cout << dist[i] << " ";
    }

    return 0;
}

