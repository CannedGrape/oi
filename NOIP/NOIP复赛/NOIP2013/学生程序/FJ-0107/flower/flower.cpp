#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int n,h[1000000]={};
int h2[1000000][2]={};
int i,k,l,m;
   
int case1(int a,int b){
int temp,check,hgg=0,hehe=0,zgg=0,j=0;
    temp=h[a];
    check=b;
    hgg++;
    for(j=a+1;j<n;j++)
      {if(check==0)
         {if(h[j]<temp)
            {hehe=case1(j,1);
             zgg=max(hehe,zgg);
            }
         }
       else
         {if(h[j]>temp)
            {hehe=case1(j,0);
             zgg=max(hehe,zgg);
            }
         }
      }
      
    return hgg+zgg;
}
int main(){
int ans;
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    
    for(i=0;i<n;i++)
      {cin>>h[i];
      }
    ans=max(case1(0,0),case1(0,1));
    cout<<ans;
    return 0;
}
    
