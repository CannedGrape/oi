#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
int n,x,s=0;
freopen("count.in","r",stdin);
freopen("count.out","w",stdout);
cin>>n;
cin>>x;
for(int i=1;i<=n;i++)
{
	if(i<10&&i==x) s++;
    if(i>=10&&i<=99&&i/10==x) s++;
    if(i>=10&&i<=99&&i%10==x) s++;
    if(i>=100&&i<=999&&i/10/10==x) s++;
    if(i>=100&&i<=999&&i%10==x) s++;
    if(i>=1000&&i<=9999&&i/10/10/10==x) s++;
    if(i>=1000&&i<=9999&&i%10==x) s++;
    if(i>=10000&&i<=99999&&i/10/10/10/10==x) s++;
    if(i>=10000&&i<=99999&&i%10==x) s++;
    if(i>=100000&&i<=999999&&i/10/10/10/10/10==x) s++;
    if(i>=100000&&i<=999999&&i%10==x) s++;
    if(i>=1000000&&i<=9999999&&i/10/10/10/10/10/10==x) s++;
    if(i>=1000000&&i<=9999999&&i%10==x) s++;
}
cout<<s;
fclose(stdin);
fclose(stdout);
}
