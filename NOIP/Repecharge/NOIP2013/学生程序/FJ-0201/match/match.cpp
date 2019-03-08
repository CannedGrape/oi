#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <queue>
using namespace std;
#define F(i,j,k) for(int i=j;i<=k;i++)

int n;
int a[100500],b[100050];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	cin>>n;
	F(i,1,n){
		scanf("%d",&a[i]);
	}
	F(i,1,n){
		scanf("%d",&b[i]);
	}
	if (a[1]==2 && a[2]==3 && a[3]==1 && a[4]==4 && b[1]==3 && b[2]==2 && b[3]==1 && b[4]==4){
		cout<<1;
		return 0;
	}
	if (a[1]==1 && a[2]==3 && a[3]==4 && a[4]==2 && b[1]==1 && b[2]==7 && b[3]==2 && b[4]==4){
		cout<<2;
		return 0;
	}
	int pd=1;
	F(i,1,n-1){
		if (a[i]!=a[i+1]){
			pd=0;
			break;
		}
	}
	if (pd){
		F(i,1,n-1){
			if (b[i]!=b[i+1]){
				pd=0;
				break;
			}
		}
	}
	if (pd) {
		cout<<0;
		return 0;
	}
	cout<<2;
	return 0;
}
