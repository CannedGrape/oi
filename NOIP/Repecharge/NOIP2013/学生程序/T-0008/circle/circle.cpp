#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int n,m,k,x,a,b,c,d,s;
long long ans;
int sqr(int x){ return x*x%d; }
int dg(int k)
{
    if (k==1) return 10;
    else if (k%2==0) return sqr(dg(k/2))%d;
    else return sqr(dg(k/2))*10%d;
} 
int main()
{
   // freopen("circle.in","r",stdin);
    //freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&n,&m,&k,&x);
    m=n-m;
    a=n; b=n-m; c=1;
    while(c)
    {
            c=a%b;  a=b; b=c;
    }
    d=n/a;                         //最大公倍数 
    ans=dg(k);
    ans=ans*m%n;
    //printf("%d\n",ans);
    s=x-ans;
    if (s<0) s=n+s;
    printf("%d",s);
    fclose(stdin); fclose(stdout); 
   // system("pause");
}
