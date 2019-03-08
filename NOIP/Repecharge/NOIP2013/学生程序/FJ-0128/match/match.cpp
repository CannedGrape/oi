#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<string>
#include<cstdio>
using namespace std;
int m=99999997;
int n;
int a[100001][2];
bool a1[100001][2]={};
int b[100001][2];
int d[100001]={};
int h=1;
int c[100001];
int main()
{freopen("match.in","r",stdin);
freopen("match.out","w",stdout);
int i,j,m1=0,m2=0,k1,k2,s=0,k3=0,k4=0;
scanf("%d",&n);
for(i=1;i<=n;i++)
scanf("%d",&a[i][0]);
for(i=1;i<=n;i++)
scanf("%d",&a[i][1]);
for(i=1;i<=n;i++)
{for(j=1;j<=n;j++)
{if(a[j][0]>m1 && a1[j][0]==0)
   {m1=a[j][0];k1=j;}
  if(a[j][1]>m2 && a1[j][1]==0)
  {m2=a[j][1]; k2=j;}               
}

b[i][0]=m1;
b[i][1]=k2;
m1=0;
m2=0;
a1[k1][0]=1;
a1[k2][1]=1;
c[k1]=i;
}

for(i=1;i<=n;i++)
{if(i!=b[c[i]][1])
{
for(j=n;j>=i;j--)
{if(k3==1)
{a[j+1][1]=a[j][1];d[a[j][1]]++;}
else
if(b[c[i]][1]+d[b[c[i]][1]]==j)
{s=(s+j-i+d[a[j][1]])%m;
k3=1;
}}}
k3=0;          
}
cout<<s;
 fclose(stdin);
fclose(stdout);   
//system("pause");
    return 0;
    }
