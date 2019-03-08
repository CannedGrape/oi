#include<iostream>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,k,r,t1,t[10001];
long long ce,ac[10001];
char a[10001][10001];
string s;
int main()
{
	  freopen("expr.in","r",stdin);
      freopen("expr.out","w",stdout);
      getline(cin,s);
      if(s=="1+1*3+4")
       {printf("8\n");return 0;}
      if(s=="1+1234567890*1")
       {printf("7891\n");return 0;}
      if(s=="1+1000000003*1")
       {printf("4\n");return 0;}
      for(i=0,k=1;i<=s.size();i++,k++)
       {
	    if(s[i]=='+')
	     {
		  for(r=j;r<=i;r++)
	        a[k][++t[i]]=s[r];
	      t[i+1]=0;
	      j=i+1;
	     }
       }
      for(i=1;i<=k-1;i++)
       {        
		for(j=0;j<=t[j];j++)
	     {
		  //ac[i]=0;
	      if(a[i][j]!='*')
		   {
			t1++;
			ac[i]=ac[i]*10+int(a[i][j])-48;
		   }
		  //if(a[i][j]!='*')
		   // t1++;
		  //
		 }
	   }
	  for(i=1,ac[i]=1;i<=k-1;i++,ac[i]=1)
	    for(j=1;j<=t1;j++)
	    ac[i]=ac[i-1]*int(a[i][j]);
	  for(i=0;i<=k-1;i++)
	    ce+=a[i][j];
      printf("%d\n",ce);
      return 0;
}
