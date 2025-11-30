
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int edges[200][2];  // max 200 edges (quite enough)
    for(int i = 0; i < n-1; i++)
        cin >> edges[i][0] >> edges[i][1];

    int v;          // which vertex to split
    cin >> v;

    int k;          // how many neighbors to move
    cin >> k;

    int moveList[100];
    for(int i = 0; i < k; i++)
        cin >> moveList[i];

    int newNode = n + 1;   // v' (new vertex)

    // নতুন edges অ্যারে তৈরি
    int newEdges[300][2];
    int idx = 0;

    // আগের edges copy করব কিন্তু যেগুলো v → movedNeighbor সেগুলো বাদ
    for(int i = 0; i < n-1; i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];

        bool removeEdge = false;

        // check if this edge connects v with any moved neighbor
        for(int j = 0; j < k; j++)
        {
            if( (a == v && b == moveList[j]) ||
                (b == v && a == moveList[j]) )
            {
                removeEdge = true;
                break;
            }
        }

        if(!removeEdge)
        {
            newEdges[idx][0] = a;
            newEdges[idx][1] = b;
            idx++;
        }
    }

    // নতুন node newNode = v' এর সাথে moved neighbors connect করব
    for(int j = 0; j < k; j++)
    {
        newEdges[idx][0] = newNode;
        newEdges[idx][1] = moveList[j];
        idx++;
    }

    // নতুন node count = n+1
    cout << n+1 << "\n";

    // সব নতুন edge print
    for(int i = 0; i < idx; i++)
        cout << newEdges[i][0] << " " << newEdges[i][1] << "\n";

    return 0;
}
