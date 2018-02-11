#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,sj[2000000]={};
long long p,tz[2000000]={},fs[2000000]={},max1=0,max2=(-100)*1000000-1,maxx=(-300)*1000000-1;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int i,j;
    cin>>n>>p;
    for(i=1;i<=n;i++)
      cin>>sj[i];
    for(i=1;i<=n;i++)
      {max1=0;max2=-1000000001;
       for(j=1;j<=i;j++)
         {if(sj[j]>0) max1=max1+sj[j];
          if(sj[j]>max2) max2=sj[j];}
       if(max2<=0) tz[i]=max2;
       else tz[i]=max1;
       }
    fs[1]=tz[1];
    maxx=fs[1];
    max1=(-300)*1000000-1;
    for(i=2;i<=n;i++)
      {max1=(-300)*1000000-1;
       for(j=1;j<i;j++)
         if((fs[j]+tz[j])>max1) max1=fs[j]+tz[j];
       fs[i]=max1;
       if(fs[i]>maxx) maxx=fs[i];
       }
    cout<<maxx%p<<endl;
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
