#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
const int mod=20123;
struct node
{
       bool b;
       int num;
}a[10001][101];
int n,m;
int r[100001];
long long sum;
void doing(int t,int now)
{
     int w=0,i,q;
     sum+=a[t][now].num;
     sum%=mod;
     q=a[t][now].num;
     for(i=0;i<m;i++)
       if(a[t][i].b==1)
         {r[w]=i;w++;}
     if(w>=q)
       now=r[w%q+1];
     else
       now=r[q%w];
     if(t==n)
       return;
     else
       doing(t+1,now);
         
}
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
      for(int j=0;j<m;j++){
        scanf("%d%d",&x,&y);
        a[i][j].b=x;
        a[i][j].num=y;
        }
    int z;
    scanf("%d",&z);
    doing(1,z);
    cout<<sum<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
        
}
