#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int n,ans;
int h[100010]={};

void init()
{
     scanf("%d",&n);
     for(int i=1;i<=n;i++)
       scanf("%d",&h[i]);
}

void work()
{
     int k=1;
     bool j;
     
     ans=1;
     while(h[k]==h[k+1] && k+1<=n) k++;
     
     if(k!=n){
     ans++;
     if(h[k]<h[k+1]) j=true;
     if(h[k]>h[k+1]) j=false;}
     
     for(int i=k+2;i<=n;i++){
     if(h[i]<h[i-1] && j==true) {j=false,ans++;}
     else 
     if(h[i]>h[i-1] && j==false) {j=true,ans++;}
     }
}

void print()
{
     cout<<ans<<endl;
}

int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    init();
    work();
    print();
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
