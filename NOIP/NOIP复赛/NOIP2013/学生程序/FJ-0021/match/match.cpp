#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
// 交换第二列中的某两个位置 <==> 交换第一列中相同的两个位置
const int MaxN = 100000 +11;
int a[MaxN], b[MaxN], n;
typedef pair<int, int> Q;
Q c1[MaxN], c2[MaxN];
int nl[MaxN];
#define x first
#define y second
int LL[MaxN], RR[MaxN];
long long cnt = 0;
const long long mod = 99999997;
void merge(int L, int R){
	int mid = (L + R) >> 1;
	int lcnt = 0, rcnt = 0;
	for (int i = L; i <= mid; i++)
		LL[lcnt++] = nl[i];
	for (int i = mid + 1; i <= R; i++)
		RR[rcnt++] = nl[i];
	LL[lcnt] = 0x7fffffff;
	RR[rcnt] = 0x7fffffff;
	int li = 0, ri = 0;
	for (int i = L; i <= R; i++){
		if (LL[li] <= RR[ri])
			nl[i] = LL[li++];
		else {
			nl[i] = RR[ri++];
			cnt += (long long)(lcnt - li);
			cnt %= mod;
		}
	}	
}
void merge_sort(int L, int R){
	if (L < R){
		merge_sort(L, (L + R) >> 1);
		merge_sort(((L + R) >> 1) + 1, R);
		merge(L,R);
	}
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d",a + i);
		c1[i] = make_pair(a[i],i);
	}
	sort(c1, c1 + n);
	for (int i = 0; i < n; i++){
		scanf("%d",b + i);
		c2[i] = make_pair(b[i],i);
	}
	sort(c2, c2 + n);
	for (int i = 0; i < n; i++){
		nl[c1[i].y] = c2[i].y;
	}
	merge_sort(0, n - 1);
	printf("%lld\n",cnt % mod);
	//for (int i = 0; i < n; i++)
	//	printf("%d ",nl[i]);
}
