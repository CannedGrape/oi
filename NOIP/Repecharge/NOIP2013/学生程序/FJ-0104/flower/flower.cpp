#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,a[100002],b[100002];
long long ans=1;
bool s,j;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)   scanf("%d",&a[i]);
    if(a[2]>a[1])   
    s=true;
    else 
    s=false;
    j=s;
    for(i=3;i<=n;i++)
    {         
        if(a[i]>a[i-1])  s=true;
       else   s=false;
             if(j!=s){
             ans++;
                     if(i==n){     ans++;}
             }
       j=s;
    }
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
