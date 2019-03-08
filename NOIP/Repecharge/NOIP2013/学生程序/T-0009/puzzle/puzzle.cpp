#include<cstdio>
#include<cstring>
using namespace std;
int xx[4]={0,0,1,-1},yy[4]={1,-1,0,0};
//注：x与n同向，y与m同向； 
bool f[31][31],b[31][31];
int n,m,p;
int ex,ey,sx,sy,tx,ty;
int t,w;
int duilie[1001][5]; 
int ans;
int guangsou()
{
    t=0;w=1;
    duilie[w][0]=ex;duilie[w][1]=ey;duilie[w][2]=0;
    duilie[w][3]=sx;duilie[w][4]=sy;
    while (t<w)
    {
      ++t;
      b[duilie[t][0]][duilie[t][1]]=true;
      for (int i=0;i<4;++i)
      {
        int x=duilie[t][0]+xx[i],y=duilie[t][1]+yy[i];
        if (x>0&&x<=n&&y>0&&y<=m)
        {
           if (f[x][y]&&b[x][y])
           {
             ++w;
             b[x][y]=false;
             duilie[w][0]=x;
             duilie[w][1]=y;
             duilie[w][2]=duilie[t][2]+1;
             duilie[w][3]=duilie[t][3];
             duilie[w][4]=duilie[t][4];
             if (duilie[w][0]=duilie[w][3])
               if (duilie[w][1]=duilie[w][4])
                  {duilie[w][3]=duilie[t][0];duilie[w][4]=duilie[t][1];}   
             if (duilie[w][3]==tx&&duilie[w][4]==ty)
             {
                 ans=duilie[w][2];
                 return 1;                                   
             }                
           }                      
        }
      }    
    }
}
int main()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&p);
    for (int i=1;i<=n;++i)
      for (int j=1;j<=m;++j)
        scanf("%d",&f[i][j]);
    for (int i=1;i<=p;++i)
    {
      scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
      memset(b,true,sizeof(b));
      ans=-1;
      guangsou();
      printf("%d\n",ans);
    }
    scanf("%d",&n);
    fclose(stdin);fclose(stdout);
}
