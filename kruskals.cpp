#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

// Sort by weight
bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

int parent[1000];

// Find parent
int findParent(int x) {
    if (parent[x] == x) return x;
    return findParent(parent[x]);
}

// Union
void unionSet(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    parent[b] = a;
}

int main() {
    int n, m;
    cin >> n >> m;

    Edge edges[10000];

    // Input edges
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // parent init
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // sort edges by weight
    sort(edges, edges + m, cmp);

    int mstWeight = 0;
    int picked = 0;

    cout << "MST Edges:\n";

    // pick edges
    for (int i = 0; i < m; i++) {
        int a = findParent(edges[i].u);
        int b = findParent(edges[i].v);

        if (a != b) {
            cout << edges[i].u << " "
                 << edges[i].v << " "
                 << edges[i].w << "\n";

            mstWeight += edges[i].w;
            unionSet(a, b);
            picked++;

            if (picked == n - 1) break;
        }
    }

    cout << "Total MST weight = " << mstWeight << "\n";

    return 0;
}

