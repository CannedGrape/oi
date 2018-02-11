#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
using namespace std;
int n;
long long x0,y0;
long long ans=0xffffffff;
long long ls[1010],rs[1010];
long long ex[1010];

void qsort(int l,int r)
{
     int i=l,j=r;
     long long mid=ex[(i+j)/2];
     while(i<=j){
     while(ex[i]<mid) i++;
     while(ex[j]>mid) j--;
     if(i<=j){
     swap(ex[i],ex[j]);
     swap(ls[i],ls[j]);
     swap(rs[i],rs[j]);
     i++;j--;}
     }
     
     if(i<r) qsort(i,r);
     if(l<j) qsort(l,j);
}

void init()
{
     int i;
     cin>>n;
     cin>>x0>>y0;
     for(i=1;i<=n;i++)
       cin>>ls[i]>>rs[i],ex[i]=ls[i]*rs[i];
     qsort(1,n);
}

void work()
{
     int i;
     long long z=x0,t=-1;
     
     ans=0;
     for(i=1;i<=n;i++)
       t=z/rs[i],z*=ls[i],ans=max(ans,t);
}

void print()
{
     cout<<ans<<endl;
}

int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    
    init();
    work();
    print();
    
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
