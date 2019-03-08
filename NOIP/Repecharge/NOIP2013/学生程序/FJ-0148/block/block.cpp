#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int h[100001],n,i,j,k,s=0;
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    cin>>n;
    for(i=1;i<=n;i++)   cin>>h[i];
    for(i=1;i<=n;i++)
        {
        j=i;
        while(h[j]>=1)
             j++;
        for(k=i;k<j;k++)
             {  
               h[k]=h[k]-1;
               if (k==j-1) s++;
             }  
        if(h[i]!=0) i--;
        }
    cout<<s<<endl;
    return 0;
}  
