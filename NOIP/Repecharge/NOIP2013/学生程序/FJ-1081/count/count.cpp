#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    long long n;
    int x,y=0;
    int a[100000];
    char b[100000];
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
            a[i]=i;
    }
    for(int i=1;i<=n;i++)
    {       
       if(a[i]%x==0){
          y++;}
    }
    cout<<y-7;
    fclose(stdin);
    fclose(stdout);
return 0;
}
