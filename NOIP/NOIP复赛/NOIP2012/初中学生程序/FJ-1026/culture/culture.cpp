#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
#include<string.h>
#include<cmath>
#include<stdlib.h>
using namespace std;
int n,k,m,s,t,l;
long long maxx=2000000000;
int a[103]={},pc[103][103]={},le[103]={};
long long f[103]={},d[103][103]={};
bool b[103]={};
void input()
{
     int x,y,z;
     scanf("%d %d %d %d %d",&n,&k,&m,&s,&t);
     for(int i=1;i<=n;++i)
       scanf("%d",&a[i]);
     for(int i=1;i<=k;++i)
       for(int j=1;j<=k;++j)
         scanf("%d",&pc[i][j]);
     for(int i=1;i<=n;++i)
       for(int j=1;j<=n;++j)
         d[i][j]=maxx;
     for(int i=1;i<=m;++i)
       {scanf("%d %d %d",&x,&y,&z);
        if(pc[a[x]][a[y]]==false) d[y][x]=z;
        if(pc[a[y]][a[x]]==false) d[x][y]=z;
       }
}
void work()
{
     long long minn;
     int minn2;
     bool o,o2,o3,u;
     for(int i=1;i<=n;++i)
       f[i]=d[s][i];
     f[s]=0;
     b[s]=true;
     l=1;
     le[1]=a[s];
     for(int i=1;i<=n;++i)
       {minn=maxx;
        minn2=200000000;
        o2=false;
//        o3=false;
        for(int j=1;j<=n;++j)
          if(b[j]==false && f[j]<minn)
            {u=false;o=false;
             for(int k=1;k<=l && u==false;++k)
               {if(pc[a[j]][le[k]]==true) 
                  u=true;
              //  cout<<"pc  "<<a[j]<<"  "<<le[k]<<"  "<<pc[a[j]][le[k]]<<endl;
                if(le[k]!=a[j]) o=true;
               }
             if(u==false) 
               {minn=f[j];
                minn2=j;
                o2=true;
                o3=o;
               }
            }
        if(o2==false) break;
        b[minn2]=true;
        if(o3==true) {++l;le[l]=a[minn2];}
        for(int j=1;j<=n;++j)
          if(b[j]==false && f[minn2]+d[minn2][j]<f[j]) f[j]=f[minn2]+d[minn2][j];
       }
       if(f[t]!=maxx) printf("%lld\n",f[t]);
       else printf("-1\n");
}
int main()
{
    freopen("culture.in","r",stdin);
    freopen("culture.out","w",stdout);
    input();
    work();
    fclose(stdin);
    fclose(stdout);

return 0;
}
