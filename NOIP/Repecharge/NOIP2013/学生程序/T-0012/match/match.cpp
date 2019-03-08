#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;
long long i,j,k,x,y,n,a[100001],b[100001],f[100001],fs[100001],fx[100001];
long long                                sf[100001],ss[100001],sx[100001],p1,p2,p3;
long long s(long long x,long long y)
{return (((x-y)%99999997)*((x-y)%99999997))%99999997;
}
int main()
{freopen("match.in","r",stdin);
 freopen("match.out","w",stdout);
 scanf("%d",&n);
 for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
 for(i=1;i<=n;i++)
    scanf("%d",&b[i]);
 for(i=1;i<=n;i++)
    {sf[i]=ss[i]=sx[i]=f[i]=fs[i]=fx[i]=2147483647;}f[1]=s(a[1],b[1]);sf[1]=0;
 a[0]=b[0]=-2147483647;
 for(i=2;i<=n;i++)
    {p1=0;p2=0;p3=0;
      if(fx[i-1]+s(a[i],b[i-2])<fs[i]||(fx[i-1]+s(a[i],b[i-2])==fs[i]&&sx[i-1]+1<ss[i]))
        {fs[i]=fx[i-1]+s(a[i],b[i-2]);ss[i]=sx[i-1]+1;}
      if(f[i-2]+s(a[i],b[i-1])<fs[i]||(f[i-2]+s(a[i],b[i-1])==fs[i]&&sf[i-2]+1<ss[i]))
        {fs[i]=f[i-2]+s(a[i],b[i-1]);ss[i]=sf[i-2]+1;}
      
      if(fs[i-1]+s(a[i-2],b[i])<fx[i]||(fs[i-1]+s(a[i-2],b[i])==fx[i]&&ss[i-1]+1<sx[i]))
        {fx[i]=fs[i-1]+s(a[i-2],b[i]);sx[i]=ss[i-1]+1;}
      if(f[i-2]+s(a[i-1],b[i])<fx[i]||(f[i-2]+s(a[i-1],b[i])==fx[i]&&sf[i-2]+1<sx[i]))
        {fx[i]=f[i-2]+s(a[i-1],b[i]);sx[i]=sf[i-2]+1;}
        
      if(f[i-2]+s(a[i],b[i-1])+s(a[i-1],b[i])<f[i]||(f[i-2]+s(a[i],b[i-1])+s(a[i-1],b[i])==f[i]&&sf[i-2]+1<sf[i]))
        {f[i]=f[i-2]+s(a[i],b[i-1])+s(a[i-1],b[i]);sf[i]=sf[i-2]+1;}
      //fx[i]=min(fx[i],fs[i-1]+s(a[i-2],b[i]));
      //fx[i]=min(fx[i],f[i-2]+s(a[i-1],b[i]));
      //f[i]=min(f[i],f[i-2]+s(a[i],b[i-1])+s(a[i-1],b[i]));
    if(f[i]>f[i-1]+s(a[i],b[i])||(f[i]==f[i-1]+s(a[i],b[i])&&sf[i]>sf[i-1])){f[i]=f[i-1]+s(a[i],b[i]);sf[i]=sf[i-1];}
    if(f[i]>fx[i]+s(a[i],b[i-1])||(f[i]==fx[i]+s(a[i],b[i-1])&&sf[i]>sx[i])){f[i]=fx[i]+s(a[i],b[i-1]);sf[i]=sx[i];}
    if(f[i]>fs[i]+s(a[i-1],b[i])||(f[i]==fs[i]+s(a[i-1],b[i])&&sf[i]>ss[i])){f[i]=fs[i]+s(a[i-1],b[i]);sf[i]=ss[i];}
    f[i]%=99999997;
    fx[i]%=99999997;
    fs[i]%=99999997;
    }
 printf("%d\n",sf[n]);
 //system("pause");
 fclose(stdin);
 fclose(stdout);
 return 0;
}
