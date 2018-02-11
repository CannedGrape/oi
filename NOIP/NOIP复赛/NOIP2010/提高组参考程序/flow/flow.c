#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int s[502][502];
int n,m;
int f[502][502];
int x[502][502],y[502][502];
int p[502][502];
int q[502];
int maxn(int a,int b)
{
if(a>b) return a;
   else return b;
}
int minn(int a,int b)
{
if(a>b) return b;
   else return a;
}
void dfs(int a,int b)
{
if(f[a][b]) return ;
f[a][b]=1;
if(a==n)
{
   x[a][b]=b;
   y[a][b]=b;
   }
if(s[a+1][b]<s[a][b])
{
   dfs(a+1,b);
   x[a][b]=minn(x[a+1][b],x[a][b]);
   y[a][b]=maxn(y[a+1][b],y[a][b]);
   }
if(s[a][b+1]<s[a][b])
{
   dfs(a,b+1);
   x[a][b]=minn(x[a][b+1],x[a][b]);
   y[a][b]=maxn(y[a][b+1],y[a][b]);
   }
if(s[a-1][b]<s[a][b])
{
   dfs(a-1,b);
   x[a][b]=minn(x[a-1][b],x[a][b]);
   y[a][b]=maxn(y[a-1][b],y[a][b]);
   }
if(s[a][b-1]<s[a][b])
{
   dfs(a,b-1);
   x[a][b]=minn(x[a][b-1],x[a][b]);
   y[a][b]=maxn(y[a][b-1],y[a][b]);
   }
/*FILE *fp=fopen("flow.ans","a");
fprintf(fp,"%d %d   %d %d \n",a,b,x[a][b],y[a][b]);
   fclose(fp);*/
return ;
}
int main()
{
FILE *fq=fopen("flow.in","r"),*fp=fopen("flow.ans","w");
fscanf(fq,"%d%d",&n,&m);
int i,j,k,z;
memset(f,1,sizeof(f));
memset(y,0,sizeof(y));
for(i=0;i<502;i++) for(j=0;j<502;j++) {s[i][j]=0x7fffffff;x[i][j]=1000;p[i][j]=1000;}

for(i=1;i<=n;i++)
   for(j=1;j<=m;j++)
   {
    fscanf(fq,"%d",&s[i][j]);
    f[i][j]=0;
    }
for(i=1;i<=m;i++)
{
   dfs(1,i);
   }
int t=0;
for(i=1;i<=m;i++)
{
   //fprintf(fp,"%d %d %d\n",i,x[1][i],y[1][i]);
   q[x[1][i]]=1;
   q[y[1][i]]=1;
  
   p[x[1][i]][y[1][i]]=1;
   if(f[n][i]==0) {t++;}
   }
if(t)
{
   fprintf(fp,"0\n%d\n",t);
   fclose(fq);
   fclose(fp);
     return 0;
   }
for(i=2;i<=(m-1);i++)
{
  
    for(j=1;(j+i)<=m;j++)
   {
    if(!q[i+j]) continue;
    if(!q[j]) continue;
    for(k=j+1;k<i+j;k++)
    {
     for(z=j+1;z<=(k+1);z++)
     {
      p[j][i+j]=minn(p[j][i+j],p[j][k]+p[z][i+j]);
      }
     }
     //fprintf(fp,"%d %d %d\n",j,j+i,p[j][i+j]);
    }
   }
fprintf(fp,"1\n%d\n",p[1][m]);
fclose(fq);
fclose(fp);
return 0;
}
