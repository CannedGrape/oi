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
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	cin>>n;
	F(i,1,n){
		scanf("%d",&a[i]);
	}
	int l=1,r=1000000;
	int ans=0;
	do{
		int temp1=0,temp2=0;
		int mid=(l+r)>>1;
		int b;
		int up1=0,down1=0;
		if (a[1]>mid) {
			b=1;
			up1++;
		}else{
			b=-1;
			down1++;
		}
		temp1++;
		F(i,2,n){
			if (b==1){
				if (a[i]<=mid){
					temp1++;
					b=-b;
				}
			}else{
				if (a[i]>mid){
					temp1++;
					b=-b;
				}
			}
			if (a[i]<=mid){
				down1++;
			}else{
				up1++;
			}
		}
		if (up1>down1) l=mid+1;
		else r=mid-1;
		if (temp1>ans) ans=temp1;
	}while (l<=r);
	cout<<ans;
	return 0;
}
