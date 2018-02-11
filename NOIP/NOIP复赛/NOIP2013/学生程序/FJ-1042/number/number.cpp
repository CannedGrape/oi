#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//preiotery_queue h queue;
int n,p,x,a[1000000],c[1000000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%d%d",&n,&p);
    for (int i=1; i<=n; ++i) 
    {
        scanf("%d",&x);
        a[i]=a[i-1]+x;
    }
    c[1]=a[1];
    c[2]=a[1]+c[1];
    for (int i=3; i<=n; ++i)
    {
        sort(c+1,c+i);
        c[i]=a[i-1]+c[i-1];
    }
    sort(c+1,c+n+1);
    printf("%d",c[n]%p);
    //printf("\n%d",(-7)%5);
    //system("pause");
    fclose(stdin); fclose(stdout);
}
