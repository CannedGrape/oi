#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

long long n,d[5][100],maxx,sz[100][3],best=1000000000;
bool s[100],r[100],pp;

int pd(void)
{
     for(int i=1;i<=n;i++)
       if(r[i]==0 || s[i]==0)
         pp=1;
     if(pp==1)
       return 0;
     else
       return 1;
     
}

void swap(int &a,int &b)
{
     int c;
     c=a;
     a=b;
     b=c;
}

void px(int l,int r)
{
     int i,j,mid;
     i=l;
     j=r;
     mid=sz[(i+j)/2][2];
     while(i<=j)
       {while(sz[i][2]<mid)
          i++;
        while(sz[j][2]>mid)
          j--;
        if(i<=j)
          {swap(sz[i][2],sz[j][2]);
           swap(sz[i][1],sz[j][1]);
           i++;
           j--; 
          }    
       }
     if(l<j) px(l,j);
     if(i<r) px(i,r);
}

void js(void)
{
     maxx=0;
     for(int i=1;i<=n;i++)
       if(d[4][i]>maxx)
         maxx=d[4][i];
     if(maxx<best)
       best=maxx;
     //cout<<best<<" ";
}

void sx(int k)//第几位置 
{
     if(k==n+1)
       {js();
       }
     else
       for(int i=1;i<=n;i++)//第几个人 
         if(s[k]==0 && r[i]==0)
           {d[0][k]=i;
            d[1][k]=sz[i][1];
            d[2][k]=sz[i][2];
            d[3][k]=d[3][k-1]*d[1][k];
            d[4][k]=d[3][k-1]/d[2][k];
            s[k]=1;
            r[i]=1;
            if(d[4][k]>=best)
              {
               r[i]=0;
               s[k]=0;
               d[4][k]=0;
               d[3][k]=0;
               d[2][k]=0;
               d[1][k]=0;
               d[0][k]=0;
               return;
              }   
            else
              {sx(k+1);
               r[i]=0;
               s[k]=0;
               d[4][k]=0;
               d[3][k]=0;
               d[2][k]=0;
               d[1][k]=0;
               d[0][k]=0;
              }  
           }
         
     
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=0;i<=n;i++)
      cin>>sz[i][1]>>sz[i][2];
    px(1,n);
    d[3][0]=sz[0][1];
    sx(1);
    cout<<best;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
/*

10
1 1 
1 1
1 1
1 1
1 1
1 1
1 1
1 1
1 1
2 2
1 1
2 2
2 2
2 2
2 2
2 2
*/
