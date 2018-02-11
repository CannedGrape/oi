#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
using namespace std;
#define rep(i,a,b)	for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)
typedef long long ll;
const int maxn = 1001;
int n,myl,myr,flag[maxn];
ll pi,minn,ans[maxn],best;
ll max(ll a,ll b){
	if(a>b) return a;
	else return b;
}
struct node{
	int l,r;
}human1[maxn];
void Init(){
	scanf("%d%d%d",&n,&myl,&myr);
	pi=myl;
	rep(i,1,n){
		scanf("%d%d",&human1[i].l,&human1[i].r);
		pi*=human1[i].l;}
}
void Solve(){
	down(i,n,1){
		int k;
		k=0;minn=0;
		rep(j,1,n)
			if(!flag[j]){
				if(k==0||((long long)(pi/(human1[j].l*human1[j].r))<minn)){
					minn=pi/(human1[j].l*human1[j].r);
					k=j;
				}
			}
		ans[i]=(long long)(pi/(human1[k].l*human1[k].r));
		flag[k]=1;
		pi=(long long)(pi/human1[k].l);
	}
	rep(i,1,n)
		best=max(best,ans[i]);
	cout<<best;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	Init();
	Solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
