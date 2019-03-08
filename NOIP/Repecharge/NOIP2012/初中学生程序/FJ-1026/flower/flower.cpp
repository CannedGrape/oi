#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<string.h>
#include<cmath>
#include<stdlib.h>
using namespace std;
int n,m,ans=0;
int a[103]={},b[103]={},s[103]={};
void input()
{
     scanf("%d %d",&n,&m);
     for(int i=1;i<=n;++i)
       scanf("%d",&a[i]);
     for(int i=n;i>=1;--i)
       s[i]=s[i+1]+a[i];
}
void work(int t)
{
//     cout<<t<<"  "<<be<<endl;
     for(int i=1;i<=n;++i)
       if(a[i]>0 && i>=b[t-1] && t+a[i]-1>=s[i+1])
         {--a[i];
          b[t]=i;
       /*   for(int j=1;j<=m;++j) cout<<b[j]<<"  ";
            cout<<endl;*/
//          cout<<t<<"  "<<i<<endl;
          if(t==m) {++ans;ans=ans%1000007;}
          else
            work(t+1);
          b[t]=0;
          ++a[i];
         }
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    input();
    work(1);
    printf("%d\n",ans);
    fclose(stdin);
    fclose(stdout);

return 0;
}
