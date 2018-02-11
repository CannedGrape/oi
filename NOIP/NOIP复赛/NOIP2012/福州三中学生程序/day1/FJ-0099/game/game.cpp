#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
long long dc[1001][3],nc,n,i,j,tail,tails,minn=0,s=1,ss;
bool sign=true;
int main()
{   freopen("game.in","r",stdin);freopen("game.out","w",stdout);
    scanf("%I64d",&n);tail=n;
    for(i=0;i<=n;i++)scanf("%I64d %I64d",&dc[i][1],&dc[i][2]);
    while(sign)
      {sign=false;
       for(j=1;j<=tail-1;j++)
         {if((dc[j][2]>dc[j+1][2])||((dc[j][2]==dc[j+1][2])&&(dc[j][1]>dc[j+1][1])))
            {sign=true;
             nc=dc[j][1];dc[j][1]=dc[j+1][1];dc[j+1][1]=nc;
             nc=dc[j][2];dc[j][2]=dc[j+1][2];dc[j+1][2]=nc;
             tails=j;
         }  }
       tail=tails;
      }
    for(i=1;i<=n;i++)
     {s*=dc[i-1][1];
      ss=s/dc[i][2];
      if(ss>minn)minn=ss;
     }
    printf("%I64d\n",minn);
    fclose(stdin);fclose(stdout);
    return 0;
}
