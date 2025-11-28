#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int dist[100][100];
    cout<<"2D array:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>dist[i][j];
        }
    }
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    cout<<"All pair shortest path matrix:"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]>=9999)
            {
                cout<<"INF"<<endl;
            }
            else
                cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;


}
