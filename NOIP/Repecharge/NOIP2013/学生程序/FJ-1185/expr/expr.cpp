#include <iostream>
#include <cstdio>
#include <cstring>
int s[100001][2]={0},d[5];
using namespace std;
int main()
{
freopen ("expr.in","r",stdin);
freopen ("expr.out","w",stdout);
string a; int b,p=1,o=1,i=0,m=0;;
cin >>a;
b=a.size(); 
for (int q=b-1;q>=0;q--)
{
if (a[q]>='0'&&a[q]<='9'&&p<=4){d[p]=a[q]-'0'; p++;}
if (a[q]=='+'){s[o][1]=d[4]*1000+d[3]*100+d[2]*10+d[1]; s[o][0]=1;o++;p=1;for (int u=1;u<=4;u++)d[u]=0;}
if (a[q]=='*'){s[o][1]=d[4]*1000+d[3]*100+d[2]*10+d[1]; s[o][0]=2;o++;p=1;for (int u=1;u<=4;u++)d[u]=0;}
}
s[o][1]=d[4]*1000+d[3]*100+d[2]*10+d[1]; s[o][0]=1; 
for (int y=o;y>=1;y--)
{
if (s[y][0]==2){s[y][1]*=s[y+1][1]; if (s[y][1]!=1000)s[y][1]-=s[y][1]/10000*10000; s[y+1][1]=0; s[y][0]=1;}	
}
for (int y=o;y>=1;y--)
{m+=s[y][1];}
printf ("%d\n",m);
return 0;
}


