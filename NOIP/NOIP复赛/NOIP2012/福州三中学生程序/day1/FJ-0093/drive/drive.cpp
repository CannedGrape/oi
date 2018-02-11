#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int n,h[1001];
int j,ren,f[1001][1001][2];
int m,s,cf,x;
double bz,mbz;
struct qweq{
int a,b,amax,bmax;
}g[1001];
int main()
{
  freopen("drive.in","r",stdin);
  freopen("drive.out","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
	  scanf("%d",&h[i]);
  for(int i=1;i<n;i++)
	 for(int j=i+1;j<=n;j++)
	   {if(abs(h[i]-h[j])<g[i].amax||g[i].amax==0||(abs(h[i]-h[j])==g[i].amax&&h[j]<h[g[i].a]))
		   {g[i].a=j;g[i].amax=abs(h[i]-h[j]);}
		 else
		   {if(abs(h[i]-h[j])<g[i].bmax||g[i].bmax==0||(abs(h[i]-h[j])==g[i].bmax&&h[j]<h[g[i].b]))
			   {g[i].b=j;g[i].bmax=abs(h[i]-h[j]);}
		   }
		}
  scanf("%d",&x);
  for(int i=1;i<=n;i++)
    {ren=0;
	  while(g[j].a!=0&&(g[j].b!=0||ren==0))
	    {if(ren==0) {
			f[i][g[j].a][0]=f[i][j][0]+g[j].amax;
			f[i][g[j].a][1]=f[i][j][1];
	        j=g[j].a;ren=1;	
			}
		 else
		   {f[i][g[j].b][1]=f[i][j][1]+g[j].bmax;
			 f[i][g[j].b][0]=f[i][j][0];
	         j=g[j].b;ren=0;	
			}
		 if(f[i][j][0]+f[i][j][1]<x&&f[i][j][1]!=0)
            bz=(double)f[i][j][0]/(double)f[i][j][1];
		}
	  if((bz<mbz||mbz==0))
	    {mbz=bz;cf=i;}
	}
  printf("%d\n",cf);
  scanf("%d",&m);
  for(int i=1;i<=m;i++)
    {scanf("%d%d",&x,&s);
	  while(f[s][j][0]+f[s][j][1]<x&&g[j].a!=0&&(g[j].b!=0||ren==0))
	    {if(ren==0){ren=1;j=g[j].a;}
		  else {ren=0;j=g[j].b;}
		}
	  printf("%d %d\n",f[s][j][0],f[s][j][1]);
	}
  fclose(stdin);
  fclose(stdout);
  return 0;	
}
