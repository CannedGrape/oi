#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
typedef long long ll;
using namespace std;
int ph,ans,a,tmp,b;
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&a);
	while(a--){
		scanf("%d",&tmp);
		if(tmp>ph){
			ans+=tmp-ph;
		}
		ph=tmp;
	}
	printf("%d\n",ans);
	return 0;
}