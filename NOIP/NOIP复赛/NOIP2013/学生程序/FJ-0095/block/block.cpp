#include<iostream>
#include<stdio.h>
using namespace std;
int n,a[100010];
long long ans=0;
void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++) scanf("%d",&a[i]);
}
void work(int l,int r,int last)
{
     int i,an=l,s;
     for(i=l+1;i<=r;i++)
       if(a[i]<a[an]) an=i;
     s=a[an]-last;
     ans+=s;
     if(an!=l) work(l,an-1,last+s);
     if(an!=r) work(an+1,r,last+s);
}
int main()
{
    
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    
    init();
    work(1,n,0);
    cout<<ans<<endl;
    return 0;
}

/*
5
2 3 4 1 2
*/
