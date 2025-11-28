#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin >> n >> m;
    int u[m],v[m],w[m];
    for (int i=0;i<m;i++)
    {
        cin >> u[i] >> v[i]>>w[i];
         }
         int source;
         cin>>source;
         int dist[n];
         for(int i=0;i<n;i++)
         {
             dist[i]=INT_MAX;
         }
         dist[source]=0;
         for(int i=0;i<n-1;i++)
         {
             for(int j=0;j<m;j++)
             {
                 if(dist[u[j]]!=INT_MAX &&dist[u[j]]+w[j]<dist[v[j]])
                   dist[v[j]] = dist[u[j]]+w[j];
             }
         }
         for (int j=0; j<m;j++) {
        if (dist[u[j]]!=INT_MAX &&dist[u[j]] + w[j]<dist[v[j]]) {
            cout <<"Negative cycle!"<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++)
    {
        if(dist[i]==INT_MAX)
            cout<<"INF"<<endl;
        else
            cout<<dist[i]<<" ";
    }

}
