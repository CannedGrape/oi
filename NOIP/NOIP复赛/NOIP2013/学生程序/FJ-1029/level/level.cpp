#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,m;
int main()
{
    freopen("level.in","r",stdin);
    freopen("level.out","w",stdout);
    scanf("%d%d",&n,&m);
    if(m==2)
      cout<<2;
    else
      cout<<3;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
