#include<stdio.h>
char a[100001]={},c;
int i,j,num=1,myfinal=0;
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    while(num<=100000)
    {
       c=getchar();
       if(c==13||c==10){num--;break;}
       else {a[num]=c;num++;}
    }
    int number=1,happy=0,happy2[100000]={},happy2number=0;
    while(number<=num)
    {
       happy=0;i=number;
       while(i<=num)
       {
          if(a[i]!='+'&&a[i]!='*') i++;
          else break;
       }
       i--;
       int d=1;
       for(j=i;(j>=i-3)&&(j>=1);j--)
       {
         if(a[j]=='+'||a[j]=='*') break;
         else {happy=happy+(a[j]-48)*d;d=d*10;}
       }
       if(a[i+1]=='+'||i==num)
       {
          int final2=1,k;
          for(k=1;k<=happy2number;k++)
          {
             final2*=happy2[k];
             final2%=10000;
          }
          final2*=happy;
          final2%=10000;
          myfinal+=final2;
          myfinal%=10000;
          happy2number=0;
       }
       else if(a[i+1]=='*')
       {
          happy2number++;
          happy2[happy2number]=happy;
       }
       number=i+2;
    }
    printf("%d\n",myfinal);
    return 0;
}
