#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;

int n,h[100010];
int lind[100010];
int sz=0;
int cnt=0;
int ans=0;

int mymin (int a,int b)
{
    if (a<b)  return a;
    return b;
}

void init ()
{
     int i;
     cin>>n;
     sz++;
     lind[1]=0;
     sz++;
     lind[2]=n+1;
     h[0]=0;
     h[n+1]=0;
     for (i=1;i<=n;i++)
     {
       scanf ("%d",&h[i]);
       if (!h[i]){
         lind[++sz]=i;
         cnt++;
       }
     }
}

void doing ()
{
     int i,j;
     int temp;
     while (cnt!=n)
     {
       sort (lind+1,lind+1+sz);
       for (j=1;j<=sz-1;j++)
       {
         temp=0;
         for (i=lind[j];i<=lind[j+1];i++)
         {
           if (h[i]!=0)
           {
             h[i]--;
             temp++;
             if (h[i]==0)
             {
               cnt++;
               lind[++sz]=i;
             }
           }
         }
         if (temp!=0)ans++;
       }
     }
     cout<<ans<<endl;
}

int main ()
{
    freopen ("block.in","r",stdin);
    freopen ("block.out","w",stdout);
    
    init ();
    doing ();
    
    //system ("pause");
    return 0;
}
