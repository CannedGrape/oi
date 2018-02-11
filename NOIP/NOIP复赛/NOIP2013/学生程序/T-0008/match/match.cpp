#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;
int a[100000],b[100000];
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int n,f=0;
    scanf("%d",&n);
    for (int i=1; i<=n; ++i) scanf("%d",&a[i]);
    for (int i=1; i<=n; ++i) {
        scanf("%d",&b[i]);
        if (a[i]!=b[i]) f=1;
    }
    if (f==0) printf("0");
    else printf("1");  
    fclose(stdin); fclose(stdout); 
}
