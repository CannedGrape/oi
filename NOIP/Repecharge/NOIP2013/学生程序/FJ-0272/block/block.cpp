#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
int ans,n,h,next;
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	int next=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&h);
		ans+=std::max(h-next,0);
		next=h;
	}
	printf("%d",ans);
	return 0;
}

