#include<iostream>
#include<fstream>
using namespace std;
const int N=100000+20000,INF=99999997;
int a[N],b[N];
int n;
bool cmp(int x,int y)
{
	return (a[x]-b[x])*(a[y]-b[y])<(a[y]-b[x])*(a[x]-b[y]);
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	bool ok=0;
	int tot=0;
	while(!ok){
		ok=1;
		for(int i=0;i+1<n;i++){
				int t;
			    if(cmp(i,i+1)){
					ok=0;
					tot=(tot+1)%INF;
					t=a[i],a[i]=a[i+1],a[i+1]=t;
		        }
			}
	}
	cout<<tot<<endl;
	return 0;
}
