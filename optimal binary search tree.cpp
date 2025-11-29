#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int f[n],k[n];
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>k[i];
    }
    int cost[n][n];
    for(int i=0;i<n;i++)
    {
        cost[i][i]=f[i];
    }
    for(int l=2;l<=n;l++)
    {
        for(int i=0;i<=n-l;i++)
        {
            int j=i+l-1;
            cost[i][j]=INT_MAX;
            int sum=0;
            for(int s=i;s<=j;s++)
                sum=sum+f[s];
            for(int r=i;r<=j;r++)
            {
                int left_cost=0;
                int right_cost=0;
                if(r>i)
                {
                    left_cost=cost[i][r-1];
                }
                if(r<j)
                {
                    right_cost=cost[r+1][j];
                }
                int total_cost=left_cost+right_cost+sum;
                if(total_cost<cost[i][j])
                {
                    cost[i][j]=total_cost;
                }

            }
        }
    }
    cout<<cost[0][n-1]<<endl;

    return 0;

}
