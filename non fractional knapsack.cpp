#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], value[n];
    cout << "Enter weights of items:\n";
    for(int i = 0; i < n; i++)
        cin >> weight[i];

    cout << "Enter values of items:\n";
    for(int i = 0; i < n; i++)
        cin >> value[i];

    int W;
    cout << "Enter maximum capacity of knapsack: ";
    cin >> W;

    int dp[n+1][W+1];

    // Fill the DP table
    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0) {
                dp[i][w] = 0;  // first row and column = 0
            } else if(weight[i-1] <= w) {
                dp[i][w] = dp[i-1][w - weight[i-1]] + value[i-1]; // include item
                if(dp[i-1][w] > dp[i][w]) dp[i][w] = dp[i-1][w];  // skip item if better
            } else {
                dp[i][w] = dp[i-1][w];  // cannot include, just copy
            }
        }
    }

    cout << "Maximum value in knapsack: " << dp[n][W] << endl;

    return 0;
}

