#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,m,x,k;
int remain[1000001];
int tot;
long long place;
bool check()
{
    int i;
    bool back=true;
    if(tot/2==0)
     return false;
    for(i=1;i<=tot/2;i++)
      if(remain[i]!=remain[i+tot/2])
        back=false;
    return back;
}
int main()
{
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    long long round=10;
    memset(remain,0,sizeof(remain));
    long long i;
    bool finished=false;
    cin>>n>>m>>k>>x;
    long long temp=0;
    tot=0;
    place=0;
    while(!finished)
    {
       tot++;
       temp=temp+m;
       if(temp>=n)
       {
         temp=temp%n;
       }
       remain[tot]=temp;
       if(check()==true)
         finished=true;
    }
    /*for(i=1;i<=tot/2;i++)
      cout<<remain[i]<<" "<<endl;*/
    for(i=1;i<=k-1;i++)
    {
      round=round*10;
      if(round>=tot)
        round=round%tot;
    }
    for(i=1;i<=round;i++)
    {
           place+=m;
           if(place>=n)
           place=place%n;
    }
    long long ans=0;
    ans=place+x;
    if(ans>=n)
      ans=ans%n;
    cout<<ans<<endl;
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
