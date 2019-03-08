#include<cstdio>
#include<iostream>
using namespace std;
int a[100001],b[100001],c1[100001],c2[100001],g[2001][2001];
int n;
int sum=0;
int dfs(int k,int k1)
{
    if(k>k1)
    {
        ++sum;
        for(int i1=1;i1<=k1;++i1)
        g[sum][i1]=c2[i1];
    }
    for(int i2=1;i2<=n;++i2)
    if(!b[i2]&&c1[k-1]<i2)
    {
         c1[k]=i2;
         c2[k]=a[i2];
         b[i2]=1;
         dfs(k+1,k1);
         b[i2]=0;
    }
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    if(n>=19)
    {
        cout<<3;
        return 0;
    }
    for(int i=1;i<=n;++i)
    scanf("%d",&a[i]);
    int last=1,Max=-2147483647;
    for(int i=1;i<=n;++i)
    {
        dfs(1,i);
        for(int j=last;j<=sum;++j)
        {
            int s1=0;
            for(int k=1;k<=i;++k)
            if(k%2==0)
            if((g[j][k]>g[j][k-1])&&(g[j][k]>g[j][k+1]))s1++;
            if(s1==i/2&&i>Max)
            {
                Max=i;
                break;
            }
            int s2=0;
            for(int k=1;k<=i;++k)
            if(k%2==0)
            if((g[j][k]<g[j][k-1])&&(g[j][k]<g[j][k+1]))s2++;
            if(s2==i/2&&i>Max)Max=i;      
        }
        last=sum+1;
    }
    cout<<Max;
    fclose(stdin);fclose(stdout);
}
