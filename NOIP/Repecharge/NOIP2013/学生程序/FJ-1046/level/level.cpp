#include<cstdio>
int n,m,tot;
int f[1001];
bool b[1001],d;
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    scanf("%d%d",&n,&m); 
    for (int i=1;i<=m;++i)
    {
      int s,x,x1,x2;
      scanf("%d",&s);
      scanf("%d",&x1);
      b[x1]=true;
      for (int j=2;j<s;++j){scanf("%d",&x);b[x]=true;}
      scanf("%d",&x2);
      b[x2]=true;  
      x=0;
      d=false;
      for (int j=x1;j<=x2;++j)
        if (!b[j])
          {
          if (f[j]>x)x=f[j];
          d=true;
          }
      if (d)++x;
      int z=f[x1]<f[x2]?f[x1]:f[x2];
      if (x<z)x=z;
      for (int j=x1;j<=x2;++j)
        if (b[j])
        {
          b[j]=false;
          if (f[j]<x)f[j]=x; 
        }   
      tot=tot>x?tot:x;     
    }
    printf("%d",tot+1);
    fclose(stdin);fclose(stdout);
    return 0;
}
