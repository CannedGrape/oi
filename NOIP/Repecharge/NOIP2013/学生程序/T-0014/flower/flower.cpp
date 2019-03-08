# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <algorithm>
# include <math.h>

using namespace std;

int n, h[100010];
bool flag;
int ans=-2147483647;
bool have[100010] = {};

bool check() {
	int c[100010],cn=0;
	for (int i=1;i<=100010;++i) 
		if(have[i]) c[++cn]=h[i];
	bool flag=true;
	for (int i=1;i<=cn/2;i++) {
		if(c[2*i]<=c[2*i-1] || c[2*i]<=c[2*i+1]) {
			flag=false;
			break;
		}
	}
	if(flag) return true;
	for (int i=1;i<=cn/2;i++) {
		if(c[2*i]>=c[2*i-1] || c[2*i]>=c[2*i+1]) {
			flag=false;
			break;
		}
	}
	if(flag) return true;
	return false;	
}
void tryy(int p,int tot) {
	if (p==n && check()) {
		ans=max(ans,tot);
		return;
	}
	else return;
	have[p]=true;
	tryy(p+1,tot);
	have[p]=false;
	tryy(p+1,tot-1);
}
		
int main() {
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &h[i]);
	
	tryy(1,n);
	cout<<ans<<endl;
	 system("pause");
	return 0;
}
