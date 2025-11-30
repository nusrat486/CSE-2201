#include <bits/stdc++.h>
using namespace std;

const int MAX = 12;
const long long INF = 1e9;

int n;
long long cost[MAX][MAX];
long long dp[1<<MAX][MAX];

int main() {
    cin >> n;

    // cost matrix input
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> cost[i][j];

    int totalStates = 1 << n;  // 2^n possible visited states

    // initialize dp with INF
    for(int mask=0; mask<totalStates; mask++)
        for(int city=0; city<n; city++)
            dp[mask][city] = INF;

    dp[1][0] = 0; // start at city 0, only city 0 visited

    // fill DP table
    for(int mask=1; mask<totalStates; mask++){
        for(int last=0; last<n; last++){
            if(!(mask & (1<<last))) continue; // last city not in mask
            if(dp[mask][last] == INF) continue;

            for(int nxt=0; nxt<n; nxt++){
                if(mask & (1<<nxt)) continue; // next already visited

                int newMask = mask | (1<<nxt);
                dp[newMask][nxt] = min(dp[newMask][nxt], dp[mask][last] + cost[last][nxt]);
            }
        }
    }

    // close the tour: return to city 0
    long long ans = INF;
    int finalMask = totalStates - 1;
    for(int last=1; last<n; last++){
        ans = min(ans, dp[finalMask][last] + cost[last][0]);
    }

    cout << "Minimum cost = " << ans << endl;
}

