#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
map <string ,int >b;
string h[2501],s,ch;
int n,m,q,ex,ey,sx,sy,tx,ty;
int c[4]={0,0,1,-1},d[4]={1,-1,0,0},a[50][50],h1[2501];
int change(int x,int y)
{
    return (x-1)*m+y-1;
}
int kp()
{
    freopen("puzzle.in","r",stdin);
    freopen("puzzle.out","w",stdout);
    string s1;
    int t=0,w=1,pos;
    h[1]=ch; h1[1]=0;
    do{
          ch=h[++t];
         // cout<<ch<<endl;
          pos=ch.find('3',0)+1;
          int x,y;
          if (pos%m==0) x=pos/m,y=m;
            else x=pos/m+1,y=pos%m;
          //printf("%d %d\n",x,y);
          for (int i=0; i<4; ++i)
          {
              if (x+c[i]>0 && x+c[i]<=n && y+d[i]>0 && y+d[i]<=m)
              {
              int z=change(x+c[i],y+d[i]);
              if (ch[z]=='1' || ch[z]=='2')
              {
                  //printf("A");
                  s1=ch;
                  s1[change(x,y)]=s1[z];
                  s1[z]='3';           
                  if (!b[s1])
                  {
                      b[s1]=1;
                      h[++w]=s1; h1[w]=h1[t]+1;
                      if (x+c[i]==tx && y+d[i]==ty && s1[change(x,y)]=='2') {
                          printf("%d\n",h1[w]);
                          return 0;
                      }          
                  }          
              }
              }
          }
    }while(t<w);
    printf("-1");
    return 0;
}
int main()
{
    scanf("%d%d%d",&n,&m,&q);
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
        scanf("%d",&a[i][j]);
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=m; ++j)
        s=s+char(a[i][j]+48);
    
    for (int i=1; i<=q; ++i)
    {
        scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
        ch=s;
        ch[(sx-1)*m+sy-1]='2'; ch[(ex-1)*m+ey-1]='3';
       // memset(b*,0, sizeof(b));
        kp();
    } 
    fclose(stdin); fclose(stdout);
}
