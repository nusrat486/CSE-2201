#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<<"Enter number of nodes and edges"<<endl;
    int n,m;
    cin>>n >> m;
    int adj[n+1][n+1]={0};
    cout<<"enter edges"<<endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>> u >> v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    int start;
    cout<<"Enetr starting node"<<endl;
    cin>>start;
    bool visited[n+1]={0};
    queue<int>q;
    visited[start]=true;
    q.push[start];
    cout<<"BFS traversal"<<endl;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<" ";

        for(int i=1;i<=n;i++)
        {
            if (adj[node][i]&&!visited[i]) {
                visited[i]=true;
                q.push(i);
            }
        }
    }
    return 0;
        }



