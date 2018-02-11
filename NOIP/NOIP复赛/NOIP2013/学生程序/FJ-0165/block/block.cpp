#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,s=0;
short int a[100002]={};
void bd(int f,int e)
{ int i;
  for(i=f;i<=e;i++)
 {if(a[i]!=0)
  a[i]--;
  if(a[i]==0)
  {if(f!=i)
   { bd(f,i);
    s++;}
   else
   f++;}}

 }
int main()
{int i;
 short int min=10001;
 freopen("block.in","r",stdin);
 freopen("block.out","w",stdout);
 cin>>n;
 for(i=1;i<=n;i++)
 {cin>>a[i];
  if(a[i]<min)
  min=a[i];}
 for(i=1;i<=n;i++)
 a[i]-=min-1;
 s+=min-1;
 a[n+1]=0;
 bd(1,n+1);
 cout<<s+1;
 fclose(stdin);
 fclose(stdout);
 return 0;
    }

