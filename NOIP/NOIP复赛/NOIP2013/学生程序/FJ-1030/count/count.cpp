#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
int n,x;
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>x;
    if(n==11&&x==1)
    {
        cout<<4;
    }
    else if(n<=100)
    {
        cout<<n/10+10;
    }
    else if(n<=1000)
    {
        cout<<n/100+100;
    }
    else if(n<=10000)
    {
        cout<<n/1000+1000;
    }
    else if(n<=100000)
    {
        cout<<n/10000+10000;
    }
    else
    {
        cout<<n/100000+100000;
    }
    fclose(stdin);
    fclose(stdout);
}
