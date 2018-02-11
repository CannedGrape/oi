#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <cstring>
using namespace std;
const int MaxN = 100000 + 1111;
struct seg_tree{
	struct node{
		int max;
		int L, R;
		node *lc, *rc;
	}nodes[MaxN * 4], *top;int cnt;
	seg_tree(){
		top = nodes;
		cnt = 1;
	}
	void init(int L, int R, node* nd){
		nd->max = 0;
		nd->L = L, nd->R = R;
//		fprintf(stderr,"%d[%d %d]\n",nd,L,R);
		if (L == R)
			return ;
		nd -> lc = nodes + cnt++;		
		nd -> rc = nodes + cnt++;
		init(L, (L + R)>>1, nd -> lc);
		init(((L + R)>>1) + 1, R, nd -> rc);
	}
	
	int query(int L, int R, node* nd){
		
		if (nd->L == L && nd->R == R){
			//printf("[%d %d] [%d %d]",L,R,nd->L,nd->R);
			//printf("=%d\n",nd->max);
			return nd->max;
		}
		int mid = (nd->L + nd ->R) >> 1;
		int rst = 0;
		if (L <= mid && nd->lc)
			rst = max(rst, query(L,min(mid,R),nd->lc));
		if (R > mid && nd->rc)
			rst = max(rst, query(max(mid + 1,L),R,nd->rc));
	//	printf("[%d %d] [%d %d]",L,R,nd->L,nd->R);
		//printf("=%d\n",rst);
		return rst;
	}
	
	void update(node *nd){
		nd->max = max(nd->lc?(nd->lc->max):0, nd->rc?(nd->rc->max):0);
	}
	
	void change(int p, int val, node* nd){
	//	printf("%d %d %d[%d %d]\n",p,val,nd,nd->L,nd->R);
		if (nd->L == p && nd->R == p){
			if (val > nd->max)
				nd->max = val;
			return ;
		}
		if (p <= (nd->L + nd->R)>>1)
			change(p, val, nd->lc);
		else
			change(p, val, nd->rc);
		update(nd);
	}
}T0, T1;
int n,h[MaxN],f[MaxN][2];
set<int> S;
map<int, int> M;
int workA(){
	memset(f,0,sizeof(f));
	f[0][0] = 0;
	f[0][1] = 1;
	T0.cnt = 1;
	T1.cnt = 1;
	T0.init(0, n + 2, T0.top);
	T1.init(0, n + 2, T1.top);
	T1.change(h[0], 1, T1.top);
	int ans = 1;
	for (int i = 1; i < n; i++){
		int k0 = T1.query(0, h[i] - 1, T1.top);
		int k1 = T0.query(h[i] + 1, n + 1, T0.top);
		if (k0 % 2 == 1) {
			f[i][0] = k0 + 1;
			T0.change(h[i], f[i][0], T0.top);
		}
		if (k1 % 2 == 0) {
			f[i][1] = k1 + 1;
			T1.change(h[i], f[i][1], T1.top);
		}
		ans = max(max(f[i][0],f[i][1]),ans);
	}
	return ans;
}
int workB(){
	memset(f,0,sizeof(f));
	f[0][0] = 0;
	f[0][1] = 1;
	T0.cnt = 1;
	T1.cnt = 1;
	T0.init(0, n + 2, T0.top);
	T1.init(0, n + 2, T1.top);
	assert(T1.top);
	T1.change(h[0], 1, T1.top);
	int ans = 1;
	for (int i = 1; i < n; i++){
		int k0 = T1.query(h[i] + 1, n + 1, T1.top);
		int k1 = T0.query(0, h[i] - 1, T0.top);
		if (k0 % 2 == 1) {
			f[i][0] = k0 + 1;
			T0.change(h[i], f[i][0], T0.top);
		}
		if (k1 % 2 == 0) {
			f[i][1] = k1 + 1;
			T1.change(h[i], f[i][1], T1.top);
		}
		ans = max(max(f[i][0],f[i][1]),ans);
	}
	return ans;
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	// test segtree
	/*int n,m;
	scanf("%d%d",&n,&m);
	T.init(0,n,T.top);
	for (int i = 0; i < m; i++){
		int x,y,z;
		scanf("%d",&x);
		if (x==1){
			scanf("%d%d",&y,&z);			
			printf("%d\n", T.query(y,z,T.top));
		}
		if (x==2){
			scanf("%d%d",&y,&z);
			T.change(y,z,T.top);
		}
	}*/
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d",h + i);
		S.insert(h[i]);
	}
	int cnt = 1;
	for (set<int>::iterator it = S.begin(); it != S.end(); it++)
		M[*it] = cnt++;
	for (int i = 0; i < n; i++)
		h[i] = M[h[i]];
//	assert(T1.top);
	int ansA = workA();
	int ansB = workB();
	printf("%d\n",max(ansA, ansB));
}
