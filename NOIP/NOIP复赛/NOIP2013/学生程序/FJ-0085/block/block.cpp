#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int n;
int h[100010]={};
long long ans,t;

void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
       scanf("%d",&h[i]);
}

void work()
{
     for(int i=1;i<=n;i++)
       ans+=max(0,h[i]-h[i-1]);
}

void print()
{
     cout<<ans<<endl;
}

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    init();
    work();
    print();
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
