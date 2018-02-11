#include<iostream>
#include<string>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[100005]={},n;
int findd(bool mark)
{
    int head=1,j,hight,low,tol=0;
    while(head<=n)
      {
        if(mark==1)
          {
            hight=a[head];
            while(a[head]>=hight&&head<=n)
              {
                hight=a[head];
                head++;
              }
            mark=0;
            tol++;
          }
        else
          {
            low=a[head];
            while(a[head]<=low&&head<=n)
              {
                low=a[head];
                head++;
              }
            mark=1;
            tol++;
          }
      }
    return tol;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    int h,l,i;
    cin>>n;
    for(i=1;i<=n;i++)
      scanf("%d",&a[i]);
    h=findd(1);
    l=findd(0);
    if(h>l)
      cout<<h<<endl;
    else
      cout<<l<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
