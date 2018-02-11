#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int n,ans;
int a[100001],b[100001];

int main()
{

    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    scanf("%d",&n);
    for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for(int i=1; i<=n; ++i) scanf("%d",&b[i]);  
    for(int i=1; i<n; ++i)
    {
            if(a[i]!=b[i])
            for(int j=i+1; j<=n; ++j)
                    if(a[i]==b[j] && i!=j) 
                    {
                                  ++ans;
                                  ans=ans%99999997;
                                  break;
                                  }
                                  }
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
