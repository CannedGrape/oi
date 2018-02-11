#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<string>
#include<string.h>
using namespace std;
bool s[30001];
int ss[30000];
int ssl=0;
int n,q=0;
void qss()
{
     int i,j;
     long long t;
     for(i=2;i<=30000;i++)
       s[i]=true;
     for(i=2;i<=30000;i++)
       {
        if(s[i])
          {ssl++;
           ss[ssl]=i;}
        for(j=1;j<=ssl;j++)
          {t=i*ss[j];
           if(t<=30000) s[t]=false;}
        }
}
int main()
{
    freopen("prime.in","r",stdin);
    freopen("prime.out","w",stdout);
    int i;
    cin>>n;
    qss();
    for(i=1;i<=ssl;i++)
      if(n%ss[i]==0)
        if(s[n/ss[i]])
          q=max(q,max(i,n/ss[i]));
    cout<<q;
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
