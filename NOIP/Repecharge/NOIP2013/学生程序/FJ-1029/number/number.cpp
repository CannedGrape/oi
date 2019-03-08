#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<math.h>
#include<cstring>
using namespace std;
int n,p,num[1000001],a[1000001],best,best1;
void doing()
{
     int i,j;
     a[1]=num[1];
     best=a[1];best1=a[1];
     for(i=2;i<=n;i++)
       if(best+num[i]>=num[i]){
         a[i]=best+num[i];
         best=a[i];
         }
       else{
         a[i]=num[i];
         best=a[i];
       }
     for(i=1;i<n;i++)
       if(a[i]+best1>best1)
         best1=best1+a[i];
     if(best1<0){
       best1*=-1;
       best1%=p;
       best1*=-1;
     }
     else
       best1%=p;
     printf("%d",best1);
}
void init()
{
     int i,j;
     scanf("%d%d",&n,&p);
     for(i=1;i<=n;i++){
       scanf("%d",&num[i]);
       if(num[i]<0){
         num[i]*=-1;
         num[i]%=p;
         num[i]*=-1;
       }
       else
         num[i]%=p;
     }
     doing();
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    init();
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
