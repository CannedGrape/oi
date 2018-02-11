#include<cstdio>
#include<iostream>
using namespace std;
int n,m,k,x,tot,ans;
int a[100001];
int main()
{
   freopen("circle.in","r",stdin);
   freopen("circle.out","w",stdout);
   scanf("%d%d%d%d",&n,&m,&k,&x);
   if (n%m==0)tot=n/m;
   else 
   {
     int s=1; 
     for (int i=m/2;i>=2;--i)
       if (m%i==0)     
         if (n%i==0)
           {s=i;break;}
     tot=n/s;
   }
   a[0]=x;
   for (int i=1;i<tot;++i)a[i]=(a[i-1]+m)%n;
   ans=10%tot;
   int paster=ans;
   for (int i=2;i<=k;++i){ans=ans*10%tot;if (paster==ans)break;else paster=ans;}
   printf("%d\n",a[ans]);
   fclose(stdin);fclose(stdout);
}
