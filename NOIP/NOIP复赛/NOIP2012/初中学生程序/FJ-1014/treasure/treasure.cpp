#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,now,a[10002][102],ans=0,th[10002][102],num[10002][102];
bool have[10002][102];
int main()
{
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
     {
      int count=1;
      for(j=0;j<m;j++)
       {
        cin>>have[i][j]>>a[i][j];
        if(have[i][j])
         {
          num[i][j]=count;
          th[i][count++]=j;
         }
        else
          num[i][j]=count;
       }
      th[i][0]=count-1;
     }
    cin>>now;
    for(i=0;i<n;i++)
     {
      int x=a[i][now];
      ans=(ans+x%20123)%20123;
      if(!have[i][now])
        now=th[i][num[i][x]];
      int k=num[i][now]+x-1; 
      if(k%th[i][0]==0)
        k=th[i][0];
      else
        k%=th[i][0];
      now=th[i][k];
     }
    cout<<ans<<endl;
    fclose(stdout);
    fclose(stdin);
    //system("pause");
    return 0;
}
