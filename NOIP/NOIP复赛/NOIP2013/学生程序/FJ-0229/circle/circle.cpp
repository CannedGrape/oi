#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int m,n,k,x,i,j,l,r,num;long sun=0;
 int f(int s)
 {
		long sum=10;
		if(s==1) return 1;
		s=f(s/2)%num;
		sum=(sum*sum)%num;
		if(k%2!=0)sum=(sum*10)%num;
		return sum;
		}
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>n>>m>>k>>x;
	long w=n;
	i=1;
	while(w%m!=0) {w=n*i;i++;}
	num=w/m;
	sun=f(k)%num;
	long kk=0;
	for(i=1;i<=sun;i++) {kk=(kk+m)%n;}
	kk=(x+kk)%n;
	cout<<kk;
	return 0;	
}
