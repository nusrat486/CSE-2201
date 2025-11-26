#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};
int main()
{
    cout<<"Number of employee"<<endl;
    int n;
    cin>>n;
    Job jobs[n];

    cout<<"input"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(jobs[j].profit<jobs[j+1].profit)
            {
                Job temp=jobs[j];
                jobs[j]=jobs[j+1];
                jobs[j+1]=temp;
            }
        }
    }
    int maxD=0;
    for(int i=0;i<n;i++)
    {
        if(jobs[i].deadline>maxD)
        {
            maxD=jobs[i].deadline;
        }
    }
    int slot[maxD+1];
    for(int i=1;i<=maxD;i++)
    {
        slot[i]=-1;
    }
    int totalProfit=0;
    for(int i=0;i<n;i++)
    {
        for(int j=jobs[i].deadline;j>=1;j--)
        {
            if(slot[j]==-1){
                    slot[j]=jobs[i].id;
                    totalProfit=totalProfit+jobs[i].profit;
                                       break;


            }
        }
    }
    cout<<"scheduled jobs"<<endl;
    for(int i=1;i<=maxD;i++)
    {
        if(slot[i]!=-1)
            cout<<slot[i]<<endl;
    }
    cout<<"Total profit="<<totalProfit<<endl;
    return 0;

}
