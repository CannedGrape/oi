#include<iostream>
#include<cstdio>
#include<cstdlib> 
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int map[10000][10000];
int n,m,q,x,y,maxd;

int find(int a,int b,int d)
{int t;
 for(b=1;b<=n;b++)
 { {if(map[a][b]!=-1) 
       {if(b==y) 
          {if(map[a][b]<d) 
	         {d=map[a][b];}
		   if(d>maxd)
           maxd=d;
          }
	   }
       else
         {if(map[a][b]<d) 
	        {d=map[a][b];}
  	      t=map[a][b];
	      map[a][b]=map[b][a]=-1;
	      find(b,1,d);
	      map[a][b]=map[b][a]=t;
	     }
  }
}
}

int main()
{int i,j,z;
 freopen("truck.in","r",stdin);
 freopen("truck.out","w",stdout);
 cin>>n>>m;
 for(i=1;i<=n;i++)
   for(j=1;j<=n;j++)
     {map[i][j]=-1;}
 for(i=1;i<=m;i++)
  {cin>>x>>y>>z;
   map[x][y]=map[y][x]=z;}
 cin>>q;
 for(i=1;i<=q;i++) 
   {cin>>x>>y;
    maxd=1000000;
    //find(x,1,maxd);
    if(maxd!=1000000)
      cout<<maxd<<endl;
    else cout<<"-1"<<endl;  
   }
 return 0;
}
