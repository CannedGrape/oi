#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<stdio.h>
using namespace std;
long long n,m,k,x;
long long jilu;
long long mi,bianhao;
long long sm(int a,long long b)
{
    long long i;
    for(i=1;i<=b;i++)
      {
      a=a*a;
      }
    return a;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    long long i=0,mo,bianhua;
    scanf("%lld%lld%lld%lld", &n, &m, &k, &x);
    bianhao=x;
    bianhao+=m;
    if(bianhao>=n)
      {
      bianhao=bianhao%n;
      }
    bianhua=bianhao-x;
    bianhao=x;
    while(true)
      {
      i++;
      bianhao+=m;
      if(bianhao>=n)
        {
        bianhao=bianhao%n;
        }
      if(bianhao==x)
        {
        break;
        }
      }
    mi=sm(10,k-1);
    mo=mi%i;
    bianhao=bianhao+mo*bianhua;
    if(bianhao>=n)
        {
        bianhao=bianhao%n;
        }
    printf("%lld", bianhao);
    cout<<'\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}
