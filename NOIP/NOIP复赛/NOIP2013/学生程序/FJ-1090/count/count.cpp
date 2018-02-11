#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
long long i,n,a[100000001]={},b=0,c=10,t,p=0,j,sum[100000001]={},s=1,l=1,k=0,x;
inline void make()
{
    for(p=1;p<=n;p++)
    {c=10;b=0;
    for(i=1;i<=100001;i++) a[i]=0;
    for(i=1;i<=100001;i++)
       {if(i==1){a[i]=p%c;c*=10;}
        else 
          if(c<=p)
          {a[i]=(p%c-a[i-1])/(c/10);
           c*=10;
           }
          else
          {t=i;break;}
        }
    c=1;
    for(i=1;i<=t;i++)
       {b+=a[i]*c;
        c*=10;        
        }
    c/=10;
    if(p>=10) a[t]=(p-b)/c;
    else t--;    
    for(j=s;j<=s+t;j++) 
      {sum[j]=a[l];
       l++;}
    s+=t;
    l=1; }
}
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>x;
    make();
    for(i=1;i<=s-1;i++)   
      if(x==sum[i]) k++;
    cout<<k<<endl;
    return 0;
    fclose(stdin);
    fclose(stdout);
}
