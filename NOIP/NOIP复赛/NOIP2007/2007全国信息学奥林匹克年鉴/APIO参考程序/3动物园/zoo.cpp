#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int maxn=10010;
const int maxm=50010;
const int maxk=16;
const int maxnum=1000000000;

int n,m,ans;
int e[maxm];
int f[maxn][maxk];
vector<int> dl[maxm],l[maxm],list[maxn], backup;

inline void getinfo() {
	scanf("%d %d\n",&n,&m);
	for (int i=1; i<=m; i++) {
		dl[i].clear();
		l[i].clear();
	}
	for (int i=1; i<=n; i++)
		list[i].clear();
	for (int i=1; i<=m; i++) {
		scanf("%d",&e[i]);
		int w=e[i]+4;
		if (w>n) w=w-n;
		list[w].push_back(i);
		int x,y;
		scanf("%d %d",&x,&y);
		for (int j=1; j<=x; j++) {
			int z;
			scanf("%d",&z);
			dl[i].push_back(z);
		}
		for (int j=1; j<=y; j++) {
			int z;
			scanf("%d",&z);
			l[i].push_back(z);
		}
	}
	ans=0;
	backup=list[n];
	return;
}

inline bool check(int x, int condition, int st, int ed) {
  for (int i=0; i<dl[x].size(); i++) {
  	int now=dl[x][i];
  	if ((now>=st)&&(now<=ed)) {
  		now=now-st;
  		if ((condition&(1<<now))==0) return true;
  	}
  }
  for (int i=0; i<l[x].size(); i++) {
  	int now=l[x][i];
  	if ((now>=st)&&(now<=ed)) {
  		now=now-st;
  		if ((condition&(1<<now))!=0) return true;
  	}
  }
  return false;
}

inline void get_init(int st) {
	list[n]=backup;
	for (int i=1; i<=n; i++)
		for (int j=0; j<maxk; j++)
			f[i][j]=-maxnum;
	int sum=0;
	for (int i=1; i<=4; i++) 
		for (int j=0; j<list[i].size(); j++) {
			int w=list[i][j];
		  if (check(w,st,1,4)) sum++; else list[n].push_back(w);
		}
	f[4][st]=sum;
  return;
}

inline void calc(int x, int now, int next) {
	int cur=now+(next<<4);
	int sum=0;
	for (int i=0; i<list[x+1].size(); i++) {
		int w=list[x+1][i];
		if (check(w,cur,x-3,x+1)) sum++;
	}
	if (f[x+1][cur>>1]<f[x][now]+sum)
		f[x+1][cur>>1]=f[x][now]+sum;
	return;
}

inline void calcans() {
	for (int i=0; i<maxk; i++)
		if (ans<f[n][i]) ans=f[n][i];
	return;
}

inline void work() {
	for (int st=0; st<maxk; st++) {
		get_init(st);
		for (int i=4; i<n; i++)
			for (int now=0; now<maxk; now++) 
				if (f[i][now]!=-maxnum) {
					calc(i,now,0);
					calc(i,now,1);
				}
		calcans();
	}
	return;
}

inline void out() {
	printf("%d\n",ans);
	return;
}

int main() {
	
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	getinfo();
	work();
	out();
	
	return 0;
}
