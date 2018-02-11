#include<cstdio>
#include<iostream>
#include<cstring>
int n,m,z,tmp,q,a[10001][10001],i,j,k,s,x1,x2,x,y;
using namespace std;
int truck(int x,int y)
{ 
   cin>>x>>y;
   x1=x;
   x2=y;
   for(j=0;j<n;j++) 
      for(k=j+1;k<n;k++)
        if(a[x][y]<a[x][k]&&a[x][y]<a[k][y])
           {
               if (a[x][k]>a[k][y]) a[x][y]=a[k][y];
               if (a[x][k]<a[k][y]) a[x][y]=a[x][k];
           }
}
int main()
{ 
   freopen("truck.in","r",stdin);
   freopen("truck.out","w",stdout);
   memset(a,0,sizeof(a));
   cin>>n>>m;
   for(i=1;i<=m;i++)
       {
         cin>>x>>y>>z;
             if(z>a[x][y])
                {
                          a[x][y]=z;
                          a[y][x]=z;
                }
           
       }
   cin>>q;
   for(i=1;i<=q;i++) 
     {
       truck(x,y);
       if(a[x1][x2]==0) cout<<"-1"<<endl;
       else cout<<a[x1][x2]<<endl;
     }
   return 0;
}
