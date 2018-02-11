#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int n;
struct add 
{
      long long zhi;
      int wz; 
}a[100050],b[100050];

int cmp(add a,add b)
{
    if (a.zhi<b.zhi) return -1;
    else return 0;
}

int c[100050]={0},ans=0;
int temp[100050]={0};

void doing ()
{
     for (int i=1;i<=n;i++)
         {
          memset(temp,0,n);               
          int head=1,tail=2;
          for (int j=i;j<=c[i];j++)
              {
               if (c[j]<c[i]) 
                  {
                   temp[tail]=c[j];
                   tail++;
                   ans++;
                   for(int k=head;k<=tail;k++)
                      if (temp[k]>c[j]) ans++;
                  }
              }
         }
}

int main ()
{
    freopen ("match.in","r",stdin);
    freopen ("match.out","w",stdout);
    cin>>n;
    
    for (int i=1;i<=n;i++)
         {scanf("%lld",&a[i].zhi);a[i].wz=i;}
    for (int i=1;i<=n;i++)
         {scanf("%lld",&b[i].zhi);b[i].wz=i;}
    
    sort(a+1,a+n+1,cmp);
    sort(b+1,b+n+1,cmp);
    
    for (int i=1;i<=n;i++)
         c[a[i].wz]=b[i].wz;
    
    doing ();

    cout<<ans<<endl;
    return 0;
}
