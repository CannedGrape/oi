#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
#include<math.h>
using namespace std;
int n,x,ans;
void doing()
{
     int i,j;
     for(i=1;i<=n;i++){
       j=i;
       while(j>0){
         if(j%10==x)
           ans++;
         j/=10;
       }
     }
     printf("%d",ans);
}
void init()
{
     scanf("%d%d",&n,&x);
     doing();
}
int main()
{
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    init();
    fclose(stdin);
    fclose(stdout);
    //system("pause");
    return 0;
}
