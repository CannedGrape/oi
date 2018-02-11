#include<iostream>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    long int n;
    cin>>n;
    unsigned long long A,B,C,d,total,flag,FLAG,TOTAL; 
    flag=0;
    total=0;
    TOTAL=0; 
    long long int hc1[n];
    long long int hc2[n];
    for(A=1;A<=n;A++)
    cin>>hc1[A];
    for(A=1;A<=n;A++)
    cin>>hc2[A];
    for(d=0;d<=n-1;d++)
    total=total+(hc1[d]-hc2[d])*(hc1[d]-hc2[d]);
    //两个数组都交换 
    for(B=0;B<=n-2;B++)
{
    flag++;            
    swap(hc1[B],hc1[B+1]);
    for(int C=0;C<=n-2;C++)
    {
    swap(hc2[C],hc2[C+1]);
    for(d=0;d<=n-1;d++)
    {
    TOTAL=TOTAL+(hc1[d]-hc2[d])*(hc1[d]-hc2[d]);
    }
    if(TOTAL<total)
    {
    FLAG=flag+C;
    total=TOTAL;
    }
}
}
    cout<<FLAG;
    return 0;
}
