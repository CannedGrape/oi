#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[1001],b[1001];
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    int n,m,x,y,t=0;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; ++i){
    scanf("%d",&y);
    for (int i=1; i<=y; ++i)
    {
        scanf("%d",&x);
        ++a[x];
    }
    }
    for(int i=1; i<=n; ++i) b[a[i]]=1;
    for (int i=1; i<=1000; ++i) 
      if (b[i]) ++t;
    printf("%d",t);
    fclose(stdin); fclose(stdout);
}
