#include<iostream>
using namespace std;
int k[10000][100],ok[10000][100];
int main()
{
    int a,b,fj,maxx,startt,endd,floodd,n,m,cz,aaaa,j,chy,goon;
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    cin>>n>>m;
    endd=n+1;
    for(a=1;a<=n;a++)
      for(b=0;b<=m-1;b++)
       {cin>>ok[a][b];
        cin>>k[a][b];
       }
    maxx=0;
    cin>>startt;
    floodd=1;
    while(floodd<endd)
     {cz=0;
      aaaa=startt;
      j=k[floodd][startt];
      maxx=k[floodd][startt]+maxx;
      while(cz==0)
       {if(ok[floodd][aaaa]==1)
         {cz=1;
          startt=aaaa-1;
         }
        if(ok[floodd][aaaa]==0)
         aaaa++;
        if(aaaa>m)
         aaaa=0;
       }
      while(j>0)
       {if(ok[floodd][startt]==1)
         {j--;
          if(j==0)
            startt--;
         }
        startt++;
        if(startt>m)
          startt=0;
       }
      floodd++;
     }
    cout<<maxx<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
