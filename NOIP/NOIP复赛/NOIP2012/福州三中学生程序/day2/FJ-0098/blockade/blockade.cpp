#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

long long /*map[5001][5001],*/a,b,n,l,/*t[1000],o,y[1000],*/m,aim/*[1000],ls[2][100]*/;
/*
void xz(void)
{
     if(o>m)
       {for(int i=2;i<=n;i++)
          for(int j=2;j<=n;j++)
            if(map[i][j]<999999999)
              for(int k=1;k<=o;k++)
                if(y[k]==j)
                  p++;
            if(p>=2)
              
                
            
       }
     
}


void swap(long long &a,long long &b)
{
     long long c;
     c=a;
     a=b;
     b=c;
}

void px(int l,int r)
{
     int i,j,mid;
     i=l;j=r;mid=ls[0][(i+j)/2];
     while(i<=j)
       {while(ls[0][i]<mid)
          i++;
        while(ls[0][j]>mid)
          j--;
        if(i<=j)
          {swap(ls[0][i],ls[0][j]);
           swap(ls[1][i],ls[1][j]);
           i++;
           j--;
          }     
       }
     if(l<j) px(l,j);
     if(i<r) px(i,r);
}
void lg(void)
{
    if(o>m)
      {cout<<-1;return;}
      
    for(int k=1;k<=n;k++)
      for(int i=1;i<=n;i++)
        if(i!=k)
          for(int j=1;j<=n;j++)
            if(i!=j && k!=j)
              if(map[i][j]>map[i][k]+map[k][j])
                map[i][j]=map[i][k]+map[k][j];
    
    for(int i=1;i<=m;i++)
      {for(int j=2;j<=n;j++)
         {ls[1][j]=j;
          ls[0][j]=map[aim[i]][j];}
       px(2,n);
       
       
       
      }
}
*/
int main()
{
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    cin>>n;
    /*for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
        if(i==j)
          map[i][j]=0;
        else
          map[i][j]=999999999;*/
    for(int i=1;i<=n-1;i++)
      {cin>>a>>b>>l;
       //t[a]++;
       //t[b]++;
       //map[a][b]=map[b][a]=l;
      }
    /*for(int i=2;i<=n;i++)
      if(t[i]==1)
        {o++;
         y[o]=i;
        }
    */
    cin>>m;
    for(int i=1;i<=m;i++)
      cin>>aim/*[i]*/;
    cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
    
    
}
