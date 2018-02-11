#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int n;
int f[100001];
int a[100001];
int f1[100001];
int ans1,ans2,ans;

int dfs(int k,int ans2)
{
    if(k>n) ans=max(ans2,ans);
    else
    {
        if(ans2%2==0)
        {
                     for(int i=k+1; i<=n; ++i) if(a[i]>a[ans2]) a[ans2+1]=a[i],dfs(i,ans2+1);
        }else  for(int i=k+1; i<=n; ++i) if(a[i]<a[ans2]) a[ans2+1]=a[i],dfs(i,ans2+1);
    }
}

int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    if(n<3)
    {
           printf("%d",n);
           fclose(stdin);
           fclose(stdout);
           return 0;
    } 
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]),f[i]=1;
    for(int i=n-1; i>=1; --i)
    {
            for(int j=i+1; j<=n; ++j)
            {
                    if(a[i]>a[j]) 
                    {
                                  f[i]=max(f[i],f[j]+1);
                                  ans1=max(ans1,f[i]);
                    }
            }
    }
    if(ans1%2==0) --ans1;
    dfs(1,0);
    ans=max(max(ans,ans1),1);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
