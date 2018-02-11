#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <cstring>
using namespace std;
int maxx=0xfffffff;
int n,m,q=1;
int ri[100010];
int di[100010],si[100010],ti[100010];
int lc[800010];
int xz[800010];
int ans=0;

void init()
{
     int i,j;
     cin>>n>>m;
     for(i=1;i<=n;i++)
       scanf("%d",&ri[i]);
     for(i=1;i<=m;i++)
       scanf("%d%d%d",&di[i],&si[i],&ti[i]);
}

void work()
{
     bool q;
     int i,j;
     for(i=1;i<=n;i++){
     q=0;
     for(j=si[i];j<=ti[i];j++)
       if(ri[j]<di[i]) {ans++;q=1;break;}
     if(q==1) continue;
     else
     for(j=si[i];j<=ti[i];j++)
       ri[j]-=di[i];
     }
}

void print()
{
     if(ans!=0) cout<<-1<<endl;
     cout<<ans<<endl;
}

int main()
{
    freopen("classroom.in","r",stdin);
    freopen("classroom.out","w",stdout);
    
    init();
    work();
    print();
    
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
