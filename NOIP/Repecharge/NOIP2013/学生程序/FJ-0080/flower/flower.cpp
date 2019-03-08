#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int d[100001][2],d1[100001][2];
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int n,h[100001];
    cin>>n;
    for(int i=1;i<=n;i++)
    scanf("%d",&h[i]);
    d[1][1]=1;
    d[1][0]=0;
    for(int i=2;i<=n;i++)
    {
            for(int j=1;j<i;j++)
            {
                    if(h[j]<h[i]&&d[j][1]%2==1)
                    d[i][1]=max(d[j][1]+1,d[i][1]);
                    if(h[j]>h[i]&&d[j][1]%2==0)
                    d[i][1]=max(d[j][1]+1,d[i][1]);
                    d[i][0]=max(max(d[j][1],d[j][0]),d[i][0]);
            }
    }
    d1[1][1]=1;
    for(int i=2;i<=n;i++)
    {
            for(int j=1;j<i;j++)
            {
                    if(h[j]>h[i]&&d1[j][1]%2==1)
                    d1[i][1]=max(d1[j][1]+1,d1[i][1]);
                    if(h[j]<h[i]&&d1[j][1]%2==0)
                    d1[i][1]=max(d1[j][1]+1,d1[i][1]);
                    d1[i][0]=max(max(d1[j][1],d1[j][0]),d1[i][0]);
            }
    }
    int ans1=max(d[n][1],d[n][0]),ans2=max(d1[n][1],d[n][2]);
    cout<<max(ans1,ans2);
    //system("pause");
}
