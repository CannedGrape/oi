#include<cstdio>
#include<iostream>
long long n,m,k,x,z=n,p;
using namespace std;
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    p=x;
    if(k>2)k=k%2+2;int tmp=10;
    while(k>1)
    {
        tmp=tmp*10;
        k--;
    }k=tmp;    
    if(n%m==0)z=n/m;else z=n;k=k%z;
    for(int i=1;i<=k;i++){
        x+=m;x=x%n;}    
    cout<<x%n<<endl;
    return 0;
}
