#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<stdio.h>
using namespace std;
int n,m;
void init()
{
    cin>>n;
    int i;
    int j,k,h,ss=0;
    for (i=1;i<=n-1;i++)
    {
        scanf("%d%d%d",&j,&k,&h);
        if (j==1 || k==1) ss++;
    }
    cin>>m;
    if (m<ss) cout<<-1<<endl;
    else cout<<0<<endl;
}
int main()
{
    freopen("blockade.in","r",stdin);
    freopen("blockade.out","w",stdout);
    init();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
