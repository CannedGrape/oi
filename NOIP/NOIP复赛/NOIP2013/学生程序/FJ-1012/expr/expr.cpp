#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct num{int number;char sign;};
char a[1000001];
int l,r,len,m=0,ans=0;
num line[1000001];
int est(int l,int r)
{
  int base=1,tot=0;
  for(int i=r;i>=l;i--)
  {
    tot=tot+((a[i]-'0')*base);
    base=base*10;
  }
  return tot%10000;
}
int go(int l,int r)
{
  int tot=1;
  for(int i=l;i<=r;i++)
    tot=line[i].number*tot;
  return tot;
}
int main()
{
  freopen("expr.in","r",stdin);
  freopen("expr.out","w",stdout);
  scanf("%s",&a);
  l=0;
  r=0;
  len=strlen(a);
  //cout<<len<<endl;
  while(r<len)
  {
    while(a[r]>='0'&&a[r]<='9')  r++;
   // printf("The No.%d number is between %d and %d\n",m+1,l,r-1);
    line[++m].number=est(l,r-1);
    line[m].sign=a[r];
    l=r+1;
    r=l;
  }
  line[m].sign='*';
  //for(int i=1;i<=m;i++)  
    //cout<<line[i].number<<" "<<line[i].sign<<endl;
  l=1;
  r=1;
  while(r<=m)
  {
    while(line[r].sign=='*')  r++;
    if(r>m) r=m;
    ans=(ans+go(l,r))%10000;
    r++;
    l=r;
  }
  printf("%d\n",ans);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
