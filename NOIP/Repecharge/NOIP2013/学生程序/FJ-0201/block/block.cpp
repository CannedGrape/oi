#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define F(i,j,k) for (int i=j;i<=k;i++)

int n;
int a[100050];
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>n;
	F(i,1,n){
		scanf("%d",&a[i]);
	}
	a[0]=0;
	int ans=0;
	F(i,1,n){
		int minn=0;
		bool b=1;
		F(j,1,n){
			if (a[j]==0) continue;
			if (a[minn]==0){
				minn=j;
			}else if (a[minn]>a[j]){
				minn=j;
			}
		}
		F(j,minn+1,n){
			if (a[j]>=a[minn]){
				a[j]-=a[minn];
			}else{
				break;
			}
		}
		for (int j=minn-1;j>=1;j--){
			if (a[j]>=a[minn]){
				a[j]-=a[minn];
			}else {
				break;
			}
		}
		ans+=a[minn];
		a[minn]=0;
	}
	cout<<ans;
	return 0;
}
