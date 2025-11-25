#include<bits/stdc++.h>
using namespace std;

int main()
{
    char str1[100], str2[100];
    cout << "Enter first string" << endl;
    cin >> str1;
    cout << "Enter second string" << endl;
    cin.ignore();              // buffer clear
    cin.getline(str2, 100);

    int n = strlen(str1);
    int m = strlen(str2);

    int dp[105][105];

    // Initialize dp table
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }

    // Fill dp
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << "LCS Length = " << dp[n][m] << endl;

    return 0;
}
