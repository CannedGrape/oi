#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,k;
int m=0;
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    cin>>n;
    for(k=2;k<=n;k++)
    {if(n%k==0)
     n=n/k;
     if(k>m)
     m=k;
    }
	cout<<m;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
