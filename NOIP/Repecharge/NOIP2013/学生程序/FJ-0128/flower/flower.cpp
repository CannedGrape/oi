#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
int n;
int h[100001]={};
int h1[100001]={};
using namespace std;
int main()
{
   freopen("flower.in","r",stdin); 
   freopen("flower.out","w",stdout); 
    int i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {scanf("%d",&h[i]);h1[i]=h[i];}
    b=0;a=0;
    for(i=2;i<=n;i++)
    if((i+a)%2==1)
    {if(h1[i]>=h1[i-1])
    {h1[i-1]=h1[i];
    a++;
    }}
    else
    if(h1[i]<=h1[i-1])
    {a++;h1[i]=h1[i-1];
    } 
    for(i=1;i<=n;i++)
    if((i+b)%2==1)
    {if(h[i]<=h[i-1])
    {h[i-1]=h[i];
    b++;
    }}
    else
    if(h[i]>=h[i-1])
    {b++;
    }
    if(b>a)
    cout<<n-a;
    else
    cout<<n-b;
    fclose(stdin);
    fclose(stdout);
    //system("pause");
   return 0; 
    }
