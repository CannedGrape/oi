#include<stdio.h>
#include<string.h>
#define N 10000
int main()
{
    char s[1300000],ch[110000];
    long i,nump,chp,ans=0,num[110000]={0};
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    gets(s);
    nump=0;
    chp=1;
    for(i=0;i<=strlen(s);i++)
    {
                             if((s[i]>='0')&&(s[i]<='9'))
                                {
                                                         num[nump]*=10;
                                                         num[nump]+=(s[i]-'0');
                                }
                                else
                                {
                                    ch[chp]=s[i];
                                    nump++;
                                    chp++;
                                }
    }
    for(i=1;i<chp;i++)
    {
                      if(ch[i]=='*')
                         {
                                    num[i-1]=((num[i-1]%N)*(num[i]%N))%N;
                                    num[i]=0;
                         }
    }
    for(i=0;i<nump;i++)
    {
                       if(num[i]!=0)ans=((ans%N+num[i]%N))%N;
    }
    printf("%ld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
