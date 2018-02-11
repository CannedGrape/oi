#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdlib>
using namespace std;
int fsfssmax(int a,int b)
{
	if(a>=b) return a;
	if(a<b) return b;
}
struct children
	{
		int num;
		int fs;
		int tzz;
		int no;
	}chi[10000];
	int n;
	int p;
	int i;
	int j,k;
	int sum=0;
	int fsmin=-10000;
	int sum2=0;
	int ben=0;
	int fssmax=0;
	int sfssmax=0;
	int xs;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	for(i=0;i<n;i++) cin>>chi[i].num;
	for(i=0;i<n;i++) chi[i].no=i;
	chi[0].tzz=chi[0].num;
	chi[0].fs=chi[0].num;
	for(i=0;i<n;i++) 
	{
	   sum=0;
	   sum2=0;
	   fssmax=0;
	   for(j=0;j<=i;j++)
	   {
	      if(chi[j].num>=0) sum=sum+chi[j].num;
	      else if(chi[j].num<0) 
	      {
				if(chi[j].num>fsmin)fsmin=chi[j].num;
				sum2=chi[j].num;
	            for(k=1;j+k<i;k++)
	            {
					sum2+=chi[k+j].num;
					if(sum2>=0) 
					{
						ben=1;
						break;
					}
					
				}
				if(ben==1) 
				{
					j=j+k;
					sum+=sum2;
					ben=0;
				}
				else 
				{
					fssmax=fsfssmax(fssmax,sum)	;
					sum=0;
				}
		  }
		
	   }
    if((sum>0)||(fssmax>0))chi[i].tzz=fsfssmax(fssmax,sum);
    else chi[i].tzz=fsmin;
    }     
	chi[0].fs=chi[0].num;  
	for(i=1;i<n;i++) 
	{
	sfssmax=-1000;	
	   for(j=0;j<i;j++)
	   {  		
		if((chi[j].tzz+chi[j].fs)>sfssmax)sfssmax=chi[j].tzz+chi[j].fs;
	   }
	chi[i].fs=sfssmax;
    }
	sfssmax=chi[1].fs;	
    for(i=0;i<n;i++) sfssmax=fsfssmax(chi[i].fs,sfssmax);
    cout<<sfssmax%p;
	return 0;
}
