#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
struct data{
       int num,v;
       }a[100001],b[100001];
int gz(const data &a,const data &b)
{
    if(a.v>b.v)return 0;
    else return 1;
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int n;
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) {cin>>a[i].v;a[i].num=i;}
    for(int i=1;i<=n;i++) {cin>>b[i].v;b[i].num=i;}
    sort(a,a+n+1,gz);
    sort(b,b+n+1,gz);
    for(int i=n;i>0;i--)
    {
            if(a[i].num>b[i].num){
                                  ans+=a[i].num-b[i].num;
                                  ans%=99999997;
                                  for(int j=1;j<=n;j++)
                                  if(a[j].num<=a[i].num&&a[j].num>=b[i].num)a[j].num++;
            }
            else {
                 ans-=a[i].num-b[i].num;
                 ans%=99999997;
                 for(int j=1;j<=n;j++)
                 if(a[j].num>=a[i].num&&a[j].num<=b[i].num)a[j].num--;
                 }
            }
    cout<<ans;
    return 0;
}
