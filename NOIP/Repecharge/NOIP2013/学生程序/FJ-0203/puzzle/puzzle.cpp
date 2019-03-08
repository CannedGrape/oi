#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <cctype>
#include <ctime>
#include <cmath>
#include <math.h>

using namespace std;

bool c[51][51],h[31][31][31][31];
int q[450001][5];

void read(int &s)
{
	char c;
	s=0;
	c=getchar();
	while ((c<'0')||(c>'9')) c=getchar();
	while ((c>='0')&&(c<='9')) {s=s*10+c-'0'; c=getchar();}
}

int main()
{
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	int n,m,ask,i,j,ex,ey,sx,sy,tx,ty,head,tail,step;
	char chr;
	read(n);
	read(m);
	read(ask);
	for (i=1;i<=n;i++)
	  for (j=1;j<=m;j++)
	    {
			chr=getchar();
			while ((chr!='0')&&(chr!='1')) chr=getchar();
			if (chr=='1') c[i][j]=true; else c[i][j]=false;
		}
	for (i=1;i<=ask;i++)
	  {
		  read(ex); read(ey);
		  read(sx); read(sy);
		  read(tx); read(ty);
		  head=1;
		  tail=1;
		  memset(h,0,sizeof(h));
		  q[tail][0]=ex; 
		  q[tail][1]=ey;
		  q[tail][2]=sx; 
		  q[tail][3]=sy;
		  q[tail][4]=0;
		  h[ex][ey][sx][sy]=true;
		  while (head<=tail)
		    {
				ex=q[head][0];
				ey=q[head][1];
				sx=q[head][2];
				sy=q[head][3];
				step=q[head][4];
				head++;
				if ((sx==tx)&&(sy==ty)) {printf("%d\n",step); break;}
				
				if ((ex-1)&&(c[ex-1][ey]))
				  {
					if ((ey==sy)&&((ex-1)!=sx))
					  {
						if (!h[ex-1][ey][sx][sy]) 
						  {
							 tail++;
					         q[tail][0]=ex-1; 
		                     q[tail][1]=ey; 
		                     q[tail][3]=sy;
		                     q[tail][4]=step+1;
		  					 q[tail][2]=sx;
		  					 h[ex-1][ey][sx][sy]=true;
						  }
					  }
				   else
				      {
						if (!h[ex-1][ey][sx+1][sy])
					      {
						  tail++;
					 	  q[tail][0]=ex-1; 
		            	  q[tail][1]=ey; 
		                  q[tail][3]=sy;
		                  q[tail][4]=step+1;
		  				  q[tail][2]=sx+1;
		  				  h[ex-1][ey][sx+1][sy]=true;
					      }
					  }
				  }
				
				if ((ex+1<=n)&&(c[ex+1][ey]))
				  {
					
					if ((ey==sy)&&((ex+1)!=sx))
					  {
						if (!h[ex+1][ey][sx][sy]) 
						  {
							 tail++;
					         q[tail][0]=ex+1; 
		                     q[tail][1]=ey;
		                     q[tail][3]=sy;
		                     q[tail][4]=step+1;
		  					 q[tail][2]=sx;
		  					 h[ex+1][ey][sx][sy]=true;
						  }
					  }
				   else
				      {
						if (!h[ex+1][ey][sx-1][sy])
					    {
						  tail++;
					      q[tail][0]=ex+1; 
		                  q[tail][1]=ey;
		                  q[tail][3]=sy;
		                  q[tail][4]=step+1;
		  				  q[tail][2]=sx-1;
		  				  h[ex+1][ey][sx-1][sy]=true;
					    }
					  }
				  }
				
				if ((ey-1)&&(c[ex][ey-1]))
				 {
					if ((ex==sx)&&((ey-1)!=sy))
					  {
						if (!h[ex][ey-1][sx][sy]) 
						  {
							 tail++;
					         q[tail][0]=ex; 
		                     q[tail][1]=ey-1; 
		                     q[tail][2]=sx;
		                     q[tail][4]=step+1;
		  					 q[tail][3]=sy;
		  					 h[ex][ey-1][sx][sy]=true;
						  }
					  }
				   else
				      {
						if (!h[ex][ey-1][sx][sy+1])
					      {
						    tail++;
					        q[tail][0]=ex; 
		                    q[tail][1]=ey-1; 
		                    q[tail][2]=sx;
		                    q[tail][4]=step+1;
		  				    q[tail][3]=sy+1;
		  				    h[ex][ey-1][sx][sy+1]=true;
					      }
					  }
				  }
				  
				if ((ey+1<=n)&&(c[ex][ey+1]))
				 {
					if ((ex==sx)&&((ey+1)!=sy))
					  {
						if (!h[ex][ey+1][sx][sy]) 
						  {
							 tail++;
					         q[tail][0]=ex; 
		                     q[tail][1]=ey+1; 
		                     q[tail][2]=sx;
		                     q[tail][4]=step+1;
		  					 q[tail][3]=sy;
		  					 h[ex][ey+1][sx][sy]=true;
						  }
					  }
				   else
				      {
						if (!h[ex][ey+1][sx][sy-1])
					      {
							tail++;
					        q[tail][0]=ex; 
		                    q[tail][1]=ey+1; 
		                    q[tail][2]=sx;
		                    q[tail][4]=step+1;
		  				    q[tail][3]=sy-1;
		  				    h[ex][ey+1][sx][sy-1]=true;
					      }
					  }
				  }
			}
		  if (head>tail) printf("-1\n");
	  }
	return 0;
} 
