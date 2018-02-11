#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <memory.h>
using namespace std;
int n,f1[100010],f2[100010];
int d1[100010],d2[100010];
int b1[100010],b2[100010];
int step=0;

void swap(int& aa,int& bb){int cc=aa;aa=bb;bb=cc;}
void init()
{
     cin>>n;
     for(int i=1;i<=n;i++)
       scanf("%d",&f1[i]),d1[i]=f1[i];
     for(int i=1;i<=n;i++)
       scanf("%d",&f2[i]),d2[i]=f2[i];
}

void work()
{
     sort(f1+1,f1+n+1);
     sort(f2+1,f2+n+1);
     
     //for(int i=1;i<=n;i++)
    //   cout<<f1[i]<<" ";cout<<endl;
   //  for(int i=1;i<=n;i++)
  //     cout<<f2[i]<<" ";cout<<endl;
   //  cout<<endl;
     
     for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++){
       if(d1[i]==f1[j]) b1[i]=j;
       if(d2[i]==f2[j]) b2[i]=j;}
     
     //for(int i=1;i<=n;i++) cout<<b1[i]<<" ";cout<<endl;
    // for(int i=1;i<=n;i++) cout<<d2[i]<<" ";cout<<endl;
     
     for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++)
       if(b1[i]==b2[j])
         {b1[i]=d2[j];break;}
       }
     
    // for(int i=1;i<=n;i++)
     //  cout<<d1[i]<<" ";cout<<endl;
    // for(int i=1;i<=n;i++)
    //   cout<<b1[i]<<" ";cout<<endl;
    // for(int i=1;i<=n;i++)
     //  cout<<d2[i]<<" ";cout<<endl;
     
     for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++)  
       if(b1[i]==d2[j]){
       for(int k=j;k>=i+1;k--)
       {swap(d2[k-1],d2[k]);
        step++;//print0();
        }
       break;}
       if(step>99999997) step%=99999997;
       }
}

void print()
{
     cout<<step<<endl;
}

int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    
    init();
    work();
    print();
    
    freopen(stdin);
    freopen(stdout);
   // system("pause");
    return 0;
}
