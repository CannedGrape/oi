#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string.h>
using namespace std;
int n,m,s,f,q;
bool a[1000001],c;
int b[10000001],k,sum,s0[10001];
void treasure(int i,int j)
{
	if(c==1) return;
	if(i==n)
	{
		c=1;
		cout<<s<<endl;
		return;
	}
	s+=b[i*m+j];
	s%=20123;
	if(a[i*m+j]) q=0;
	else q=1;
	treasure(i+1,(s0[i]+b[i*m+j]+q)%m);
}
int main()
{
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=n*m-1;i++)
    	cin>>a[i]>>b[i];
    cin>>k;
    for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	{
    		if(!a[i*m+j])
    			s0[i]++;
		}
    treasure(0,k);
	fclose(stdin);
	fclose(stdout);
    return 0;
}
