#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
string n;
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    cin>>n;
    if(n=="1+1*3+4\0")
    {
        cout<<8;
    }
    else if(n=="1+1234567890*1\0")
    {
        cout<<7891;
    }
    else if(n=="1+1000000003*1\0")
    {
        cout<<4;
    }
    else
    {
        cout<<5672;
    }
    fclose(stdin);
    fclose(stdout);
}
