#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxN = 100000 + 1111;
struct seg_tree{
	struct node{
		int cnt;
		bool lcnt, rcnt;
		int L, R;
		node *lc, *rc;
	}nodes[MaxN * 4], *top;int cnt;
	seg_tree(){
		top = nodes;
		cnt = 1;
	}
	void init(int L, int R, node* nd){
		nd->L = L, nd->R = R, nd->cnt = nd->lcnt = nd->rcnt = 0;
		if (L == R)
			return ;
		nd -> lc = nodes + cnt++;		
		nd -> rc = nodes + cnt++;
		init(L, (L + R)>>1, nd -> lc);
		init(((L + R)>>1) + 1, R, nd -> rc);
	}
	
	int query(){
		return top->cnt;
	}
	
	void update(node *nd){
		nd->cnt = 0;
		if (nd->lc){
			nd->lcnt = nd->lc->lcnt;
			nd->cnt += nd->lc->cnt;
		}
		if (nd->rc){
			nd->rcnt = nd->rc->rcnt;
			nd->cnt += nd->rc->cnt;
		}
		if (nd->lc && nd->rc && nd->lc->rcnt && nd->rc->lcnt)
			nd->cnt--;
	}
	
	void inc(int p, node* nd){
		if (nd->L == p && nd->R == p){
			nd->cnt = 1; nd->lcnt = nd->rcnt = 1;
			return ;
		}
		if (p <= (nd->L + nd->R)>>1)
			inc(p, nd->lc);
		else
			inc(p, nd->rc);
		update(nd);
	}
}T;
pair<int,int> Q[MaxN];
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	// test segtree
	/*int n,m;
	scanf("%d%d",&n,&m);
	T.init(0,n,T.top);
	for (int i = 0; i < m; i++){
		int x,y;
		scanf("%d",&x);
		if (x==1)
			printf("%d\n", T.query());
		if (x==2){
			scanf("%d",&y);
			T.inc(y,T.top);
		}
	}*/
	int n;
	scanf("%d", &n);
	T.init(0,n+10,T.top);
	for (int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		Q[i] = make_pair(-x, i);
	}
	sort(Q + 1, Q + n + 1);
	Q[n + 1] = make_pair(0,0);
	long long ans = 0;
	for (int i = 1; i <= n; i++){
		T.inc(Q[i].second, T.top);
		while (i <= n && Q[i+1].first == Q[i].first){
			T.inc(Q[++i].second,T.top);
		}
		long long x = (long long)T.query() * (long long)(-Q[i].first + Q[i + 1].first);
	//	printf("%d\n",x);
		ans += x;
	}
	printf("%lld\n",ans);
}
