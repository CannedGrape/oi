#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
int main ()
{
freopen("count.in","r",stdin);
freopen("count.out","w",stdout);

int x,a[101],n,i,j,num=0,c=0;
cin>>n;
cin>>x;
for(i=0;i<=100;i++)
a[i]=0;
for(i=1;i<=n;i++)
{a[1]++;
for(j=1;j<=100;j++)
if(a[j]==10)
{a[j+1]++;
a[j]=0;
if(c<=j)
c=j;}
for(j=1;j<=c;j++)
if(a[j]==x)
num++;
}
cout<<num;
//freclose("count.in");
//freclose("count.out");
return 0;
}
