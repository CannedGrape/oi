#include<cmath>
#include<cstdio>
#include<iostream>
using namespace std;
int a[3000000];
int num;
int Pow(int x)
{
    if(x==0)return 1;
    int tem=(Pow(x/2)*Pow(x/2))%num;
    if(x%2==1)
    tem=(tem*10)%num;
    return tem;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    int n,m,k,x,x1;
    cin>>n>>m>>k>>x1;
    x=x1;
    int i=2;
    a[1]=x;
    for(;;++i)
    {
        x=(x+m)%n;
        if(x==x1)break;
        else a[i]=x;
    }
    num=i-1;
    cout<<a[Pow(k)+1];
    fclose(stdin);fclose(stdout);
}
