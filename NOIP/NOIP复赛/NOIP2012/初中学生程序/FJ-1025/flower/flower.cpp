#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
int n,m;
long int a[1001];
long int ans;
long int pl[10001];
void tryy(int now)
{
     int i;
     for(i=1;i<=n;i++)
     {
        if((a[i]!=0)&&(i>=pl[now-1]))
        {
            a[i]--;
            pl[now]=i;
            if(now==m)
            {
              ans++;
              if(ans>1000007)
                ans-=1000007;
            }
            else
              tryy(now+1);
            a[i]++;
            pl[now]=0;
        }
     }
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    ans=0;
    memset(a,0,sizeof(a));
    memset(pl,0,sizeof(pl));
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
      cin>>a[i];
    tryy(1);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
