#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<string.h>
#include<cmath>
#include<stdlib.h>
using namespace std;
int a[10002][102]={},s[10002]={};
bool b[10002][102]={};
int st,n,m;
long long ans;
void work()
{
     int p,q,k;
     p=st;
     ans=0;
    // cout<<endl;
     for(int i=1;i<=n;++i)
       {//k=a[i][p]-a[i][p]/s[i];
        k=a[i][p]%s[i];
        //cout<<a[i][p]<<"   "<<a[i][p]/s[i]<<"   "<<a[i][p]/s[i]*s[i]<<endl;
        ans+=a[i][p];
        ans=ans%20123;
        q=p;

        if(k==0) k=s[i];

        while(k!=0) 
          {
           if(q==m+1) q=1;
           if(b[i][q]==true) --k;
           ++q;

          }
        --q;

        p=q;
       }
}
void input()
{
     scanf("%d %d",&n,&m);
     for(int i=1;i<=n;++i)
       for(int j=1;j<=m;++j)
         {scanf("%d %d",&b[i][j],&a[i][j]);
          if(b[i][j]==true) s[i]++;}
     scanf("%d",&st);
     st++;
}
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    input();
    work();
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);

return 0;
}
