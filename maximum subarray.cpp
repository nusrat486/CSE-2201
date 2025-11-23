#include<bits/stdc++.h>
using namespace std;
int CrossSum(int a[],int left,int mid,int right)
{
    int s=0;
    int leftmax=INT_MIN;
    for(int i=mid;i>=left;i--)
    {
        s=s+a[i];
        leftmax=max(leftmax,s);
    }
    s=0;
    int rightmax=INT_MIN;
    for(int i=mid+1;i<=right;i++)
    {
        s=s+a[i];
        rightmax=max(rightmax,s);
    }
    return leftmax+rightmax;
}
int maximumSubArray(int a[],int left,int right)
{
     if(left==right)
        return a[left];
     int mid=(left+right)/2;
     int leftAns=maximumSubArray(a,left,mid);
     int rightAns=maximumSubArray(a,mid+1,right);
     int crossAns=CrossSum(a,left,mid,right);
     return max({leftAns,rightAns,crossAns});
}

int main(){
    int a[]={-2,-5,6,-2,-6,1,5,-6};
    int n=sizeof(a[0]);
    int ans=maximumSubArray(a,0,n-1);
    cout<<"Maximum subarray="<<ans<<endl;
}
