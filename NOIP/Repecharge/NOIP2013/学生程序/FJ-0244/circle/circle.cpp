#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
const int N=1000000+200000;
int p[N],q[N],r[N];
int n,m,k,x;
int K;
int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	
	cin>>n>>m>>k>>x;
	for(int i=0;i<n;i++) p[i]=i;
	for(int i=0;i<10;i++){
		memcpy(q,p,sizeof(p));
		for(int j=0;j<n;j++)
			p[j]=(q[j]+m)%n;
	}
	for(int i=0;i<n;i++) q[p[i]]=i;
	
	
	for(int i=0;i<n;i++) r[i]=i;
	for(int i=1;;i++){
		for(int j=0;j<n;j++) r[j]=q[r[j]];
		if(memcmp(r,p,sizeof(p))==0){
			K=i;
			break;
		}
	}
	
	
	for(int i=0;i<n;i++) r[i]=i;
	
	for(int i=0;i<k%K;i++){
		memcpy(p,r,sizeof(r));
		for(int j=0;j<n;j++) r[q[j]]=p[j];
	}
	for(int i=0;i<n;i++) if(r[i]==x) cout<<i<<endl;
	return 0;
}
