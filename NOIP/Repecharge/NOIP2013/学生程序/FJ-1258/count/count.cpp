#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a,b=0,c=0,d=0,e,f,g,h,k,l,m,mi=0,a1,l1=0;
char a2[1000000],a3[1000000];
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>a>>a1;//
	for(int i=1;i<=a;i++)
	{
		e=i%10;	if(e==a1){mi+=1;}
		f=(i%100-e)/10;	if(f==a1)mi+=1;
		g=(i%1000-f*10-e)/100;if(g==a1)mi+=1;
		h=(i%10000-g*100-f*10-e)/1000;if(h==a1)mi+=1;
		k=(i%100000-h*1000-g*100-f*10-e)/10000;if(k==a1)mi+=1;
		l=(i%1000000-k*10000-h*1000-g*100-f*10-e)/100000;if(l==a1)mi+=1;
		m=(i%10000000-l*100000-k*10000-h*1000-g*100-f*10-e)/1000000;if(m==a1)mi+=1;
		l1=(i%100000000-m*1000000-l*100000-k*10000-h*1000-g*100-f*10-e)/100000000;if(m==a1)mi+=1;
	}
	cout<<mi;
	fclose(stdin);
	fclose(stdout);
} 
