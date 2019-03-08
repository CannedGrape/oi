#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int len,h1=0,hh1[200000]/*³ËºÅ*/,h2=0,hh2[200000]/*¼ÓºÅ*/,sf;
long long dqz1=0,dqz2=0,sum=0,cdx=1;
char a[200000];
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    int i,j,k;
    cin>>a;
    len=strlen(a);
    for(i=0;i<len;i++)
      {if(a[i]=='*') {h1++;hh1[h1]=i;}
       if(a[i]=='+') {h2++;hh2[h2]=i;}
       }
    hh2[0]=-1;
    for(i=1;i<=h1;i++)
      {
       j=hh1[i]-1;k=hh1[i]+1;cdx=1;
       dqz1=0;dqz2=0;
       while(j>=0&&a[j]!='*'&&a[j]!='+')
         {
          dqz1=dqz1+(a[j]-'0')*cdx;
          cdx=cdx*10;j--;
          }
       dqz1=dqz1%10000;
       while(k<len&&a[k]!='*'&&a[k]!='+')
         {
          dqz2=dqz2*10+(a[k]-'0');
          k++;}
       dqz2=dqz2%10000;
       sum=sum+dqz1*dqz2;}
    dqz1=0;dqz2=0;
    for(i=0;i<=h2;i++)
      {
       sf=hh2[i]+1;dqz1=0;
       while(a[sf]!='+'&&sf<len)
         {
          if(a[sf]=='*') {dqz1=0;break;}
          else dqz1=dqz1*10+(a[sf]-'0');
          sf++;}
       sum=sum+dqz1;}
    cout<<sum%10000<<endl;
    //system("pause");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
