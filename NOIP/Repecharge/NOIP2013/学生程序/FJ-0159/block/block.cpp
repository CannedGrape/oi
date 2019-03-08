#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;
int a[100000]={0};
void js(int& l,int r)
{
     int i;
     for(i=l;i<=r;i++)
     {  
       a[i]--;
       if(a[i]==0)
         l=i+1;
     }
}
int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int n,i;
    long long k=0;
    cin>>n;
    int x=1,y=n;
    for(i=1;i<=n;i++)
    {
      cin>>a[i];
      if(a[i]==0)
        x=i+1;
    }
    while(y!=0)
    {
      while(a[y]!=0&&a[x]!=0)
      {
        js(x,y);
        k++;
      }
      if(x=y)
      {
        while(a[y]==0&&y>=1)
          y--;
        x=y;
        while(a[x-1]!=0)
          x--;
      }
    }
    cout<<k;
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
