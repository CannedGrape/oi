#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <string>
#include <cstring>
#include <memory.h>
#include <map>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define down(i,b,a) for(int i=(b);i>=(a);i--)
#define mk(a,b) make_pair((a),(b))
typedef long long ll;
const int maxn = 1000,maxl = 700,maxdat = 100000000,geps = 1;
struct hugeint{
	ll dat[maxl+geps];int last;
	void init(int start = 1){
		memset(dat,0,sizeof dat);last = 0;
		dat[0] = start;
	}bool operator<(const hugeint &r){
		int maxlast = max(last,r.last);
		down(i,maxlast,0){
			if(dat[i] < r.dat[i]) return true;
			else if(dat[i] > r.dat[i]) return false;
		}return false;
	}void operator*=(int r){
		rep(i,0,last) dat[i] *= r;
		rep(i,0,last) dat[i+1] += dat[i]/maxdat,dat[i]%=maxdat;
		if(dat[last+1] != 0) last++;
	}void operator/=(int r){
		down(i,last,1) dat[i-1] += dat[i]%r*maxdat,dat[i]/=r;
		dat[0]/=r;
	}void print(){
		printf("%lld",dat[last]);
		down(i,last-1,0) printf("%08d",(int)dat[i]);
	}
}ans,tmp,calc;
int n;pair<int,int> nums[maxn+geps];
void Init(){
	scanf("%d",&n);
	int x,y;
	rep(i,0,n) scanf("%d%d",&x,&y),nums[i] = mk(y,x);
	sort(nums,nums+n+1);
	ans.init(0),tmp.init(nums[0].second);
}
int permu[11];bool used[11];
ll outputans = 0x3fffffff;
void calcpermu(){
	ll calcvar = nums[0].second,maxscore = 0;
	rep(i,1,n){
		if(maxscore<calcvar/nums[permu[i]].first) maxscore=calcvar/nums[permu[i]].first;
		calcvar *= nums[permu[i]].second;
	}outputans = min(outputans,maxscore);
}
void dfs(int deap){
	if(deap>n) {calcpermu();return;}
	rep(i,1,n) if(!used[i]){
		permu[deap] = i;used[i] = true;
		dfs(deap+1);
		used[i] = false;
	}
}
void solve(){
	if(n<=10){
		dfs(1);
		printf("%lld\n",outputans);
		return;
	}
	rep(i,1,n){
		calc = tmp;
		calc/=nums[i].first;
		if(ans < calc) ans = calc;
		tmp*=nums[i].second;
	}ans.print();printf("\n");
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	
	Init();
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


