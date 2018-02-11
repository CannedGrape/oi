#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<string>
using namespace std;
int n;
unsigned long long ans=0;
int a[100001]={},s[100001]={};

void search(int l,int r)
{

 if (l>r) return;
 bool flag=1;
 int t=0,print=30000,k;
 for (int q=l;q<=r;q++) 
 { 
   t+=s[q]; 
   if (print>t) 
   { 
    print=t;
    k=q;
   }  
   if (t!=0) flag=0;
 }
 if (flag==1) return;
 ans+=print;
 s[l]-=print;
 search(l,k-1);
 search(k+1,r);
}

int main()
{
freopen("block.in","r",stdin); freopen("block.out","w",stdout);
scanf("%d",&n);
for (int q=0;q<n;q++) 
{
 scanf("%d",&a[q]);
 s[q]=a[q]-a[q-1];
}
int g=0;
for (int q=0;q<n;q++)
 if (a[q]==0)
  {
   search(g,q-1);
   g=q+1;
  }

if (a[n-1]!=0) search(g,n-1);

printf("%lld\n",ans);
fclose(stdin);fclose(stdout);

return 0;
}
