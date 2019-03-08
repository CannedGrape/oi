#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m,x[300001];
char a[2000001];
inline int js2(int i,int j)
{
       int k,l;
       for(k=i,l=1;k<=j;k+=2)
         l=(l*x[k])%10000;
       return l;
}
inline int js(int i,int k)
{
       int l;
       for(l=k+2;x[l]!=-1 && l<n;l+=2);
       if(l<n)
         return (js(k+1,l)+js2(i,k-1))%10000;
       else
         return (js2(k+1,n)+js2(i,k-1))%10000;
}
int main()
{
    freopen("expr.in","r",stdin);
    freopen("expr.out","w",stdout);
    int i,j,k;
    scanf("%s",&a);
    m=strlen(a)-1;
    for(i=0;i<=m;i++)
      if(a[i]=='+')
        x[++n]=-1;
      else
        if(a[i]=='*')
          x[++n]=-2;
        else
          {
           for(j=i;a[j+1]!='+' && a[j+1]!='*' && j<m;j++);
           x[++n]=a[j]-'0';
           if(j-1>0 && a[j-1]!='+' && a[j-1]!='*')
             {
              x[n]+=(a[j-1]-'0')*10;
              if(j-2>0 && a[j-2]!='+' && a[j-2]!='*')
                {
                 x[n]+=(a[j-2]-'0')*100;
                 if(j-3>0 && a[j-3]!='+' && a[j-3]!='*')
                   x[n]+=(a[j-3]-'0')*1000;
                }
             }
           i=j;
          }
    for(i=2;x[i]!=-1 && i<n;i+=2);
    if(i<n)
      printf("%d\n",js(1,i));
    else
      printf("%d\n",js2(1,n));
    fclose(stdin);
    fclose(stdout);
    return 0;
}
