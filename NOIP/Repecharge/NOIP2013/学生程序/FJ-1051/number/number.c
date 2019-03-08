#include<stdio.h>
#define MINLONG -2147483600
long int n,p;
long int num[1300000],spe[1300000],score[1300000],maxscore=MINLONG,g[1200][2500]={0};
long int nabs(long int a)
{
     if(a<0)return 0-a;
     return a;
}
long int f(long int start,long int end)
{
     long int i,j,k,sum,max=MINLONG;
     for(i=start;i<=end;i++)
     {
         for(j=i;j<=end;j++)
         {
             if(g[i][j]!=0&&i<1200&&j<2500)
                {
                           max=g[i][j];
                           break;
                           break;
                }
             sum=0;
             for(k=i;k<=j;k++)
                 sum+=num[k];
             if(sum>max)max=sum;
         }
     }
     g[start][end]=max;
     return max;
}
long int maxsum(long int start,long int end)
{
     long int i,max=MINLONG;
     for(i=start;i<=end;i++)
         if((spe[i]+score[i])>max)max=spe[i]+score[i];
     return max;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long int i;
    scanf("%ld %ld",&n,&p);
    for(i=1;i<=n;i++)
        scanf("%ld",&num[i]);
    for(i=1;i<=n;i++)
        spe[i]=f(1,i);
    for(i=1;i<=n;i++)
    {
        if(i!=1)score[i]=maxsum(1,i-1);
           else score[i]=spe[i];
        if(score[i]>maxscore)
           {
                             if(score[i]>=0)maxscore=score[i]%p;
                                else maxscore=0-(nabs(score[i]%p));
           }
    }
    printf("%ld\n",maxscore);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
