#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
const int N=100000+20000;
int n,h[N],a[N],b[N];
int main()
{
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i];
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	a[0]=1;
	b[0]=1;
	for(int i=1;i<n;i++) for(int j=0;j<i;j++){
		if(h[i]>h[j]&&b[j]+1>a[i])
		    a[i]=b[j]+1;
		if(h[i]<h[j]&&a[j]+1>b[i])
		    b[i]=a[j]+1;
	}
	int Max=0;
	for(int i=0;i<n;i++){
	    if(a[i]>Max) Max=a[i];
	    if(b[i]>Max) Max=b[i];
   }
   cout<<Max<<endl;
   return 0;
}














