#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,m,k,x,i,j,s,z=1;
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    cin>>n>>m>>k>>x;
    int a[n];
    for(i=0;i<n;i++)
        a[i]=i;
    for(i=1;i<=m;i++)
       {
         s=i*n;
         if(s%m==0) break;
       }
    s=s/m;
    for(i=1;i<=k;i++)
       {
         z=z*n;
         z=z%s;
       }
   for(i=1;i<=z;i++)
       for(j=0;j<n;j++)
          a[j]=a[j]+m;
   cout<<a[x]%n<<endl;
   return 0;    
}
