#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
int n;
int h[10001];
int b1=0;
using namespace std;
int xiao(int x,int y)
{int i,j,s=0,b=0;
for(i=x;i<=y;i++)
if(h[i]!=0)
{b=1;break;}
if(b==0)
return 0;
for(j=1;j<=10001;j++)
{if(b1==n)
break;            
for(i=x;i<=y;i++)
{if(h[i]>0)
 h[i]--;
  else
  if(i==x)
  {b1++;return s+xiao(x+1,y);}
  else
 {s++;b1++;
 return xiao(x,i-1)+xiao(i+1,y)+s;}
}   
s++;}
return 0;}
int main()
{
   freopen("block.in","r",stdin); 
   freopen("block.out","w",stdout); 
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d",&h[i]);
    cout<<xiao(1,n);
    fclose(stdin);
    fclose(stdout);
    //system("pause");
   return 0; 
    }
