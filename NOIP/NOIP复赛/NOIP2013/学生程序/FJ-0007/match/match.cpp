#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
//int A[100000];
//int B[100000];
using namespace std;
struct note{
       int old;
       int data;
       }A[100000],B[100000];
bool cmp(note a,note b)
{
     return a.data<b.data;
}
int main()
{
   freopen("match.in","r",stdin);
   freopen("match.out","w",stdout);
   int n,i,j;
   scanf("%d",&n);
   for(i=0;i<n;i++)
     scanf("%d",&A[i].data),A[i].old=i;
   for(i=0;i<n;i++)
     scanf("%d",&B[i].data),B[i].old=i;
   sort(A,A+n,cmp);
   sort(B,B+n,cmp);
   int ans=0;
   for(int i=0;i<n;i++)
       { if(A[i].old!=i)ans++;}
     //for(int i=0;i<n;i++)
    //   {cout<<A[A[i].old].data;}
   //cout<<ans<<" ";
   int true_ans=0;
   while(ans>0)
      {
        for(int i=0;i<n;i++)
          {
             if(A[i].old!=i)
             {true_ans+=abs(A[i].old-B[i].old),true_ans%=99999997,ans--;}
          // if(B[i].old!=i)swap(B[i],B[B[i].old]),true_ans++,true_ans%=99999997,ans--
                                // swap(A[A[i].old],A[B[i].old]);
                           // cout<<"\n";
                           // for(int j=0;i<n;i++)
                             //         {cout<<A[A[i].old].data;}             
          }
      }
   cout<<(true_ans/2)<<"\n";
   //system("pause");
   //ans=abs(i-A[i].old)+abs(i-B[i].old);
   //sort(A,A+n);
   //sort(B,B+n);
   fclose(stdin);
   fclose(stdout);
   return 0;
}
