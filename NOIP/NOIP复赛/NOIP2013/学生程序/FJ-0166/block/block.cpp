#include<iostream>
#include<cstring>
#include<cmath>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int a,flag,b,c,d,e,f,g;
    int n;
    cin>>n;
    int gd[n];
    for(a=1;a<=n;a++)
    {
    cin>>gd[a];
    }
    f=gd[1];
    d=gd[2];
    e=gd[n-1];
    g=gd[n];
    if(abs(d-f)>abs(e-g))
    flag=abs(d-f);
    else
    flag=abs(e-g);
    for(b=1;b<=n;b++)
    {
    for(c=1;c<=n;c++)
    if(gd[c]<gd[c+1])
    swap(gd[c],gd[c+1]);
    }
    flag=gd[1]+flag;
    cout<<flag;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
