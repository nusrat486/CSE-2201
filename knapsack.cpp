#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int weight[n];
    int value[n];
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    int w;
    cin>>w;
    double ratio[n];
    for(int i=0;i<n;i++)
    {
        ratio[i]=(double)value[i]/weight[i];
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ratio[j]>ratio[i])
            {
                swap(ratio[i],ratio[j]);
                swap(weight[i],weight[j]);
                swap(value[i],value[j]);

            }
        }
    }
    double total=0.0;
    for(int i=0;i<n;i++)
    {
        if(w==0)
            break;
        if(weight[i]<=w){
                total=total+value[i];
        w=w-weight[i];

        }

        else{
                double f=(double)w/weight[i];
        total=total+value[i]*f;
        w=0;

        }

    }
    cout<<total;
}
