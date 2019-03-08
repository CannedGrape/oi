#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
const int Maxn = 100005;
struct node {
  int data, lab;
}a[Maxn], b[Maxn];
inline bool operator <(const node& lhs,const node &rhs) {
  return lhs.data < rhs.data || (lhs.data == rhs.data && lhs.lab < rhs.lab); }
int n,ans ,cnt,pa[Maxn],pb[Maxn];
bool p[Maxn];
int main() {
  freopen("match.in","r",stdin); freopen("match.out","w",stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
	  scanf("%d",&a[i].data);
	  a[i].lab = i;
   }
   std::sort(a, a + n);
   for (int  i = 0; i < n; ++i) pa[a[i].lab] = i;
   for (int i = 0; i < n; ++i) {
	  scanf("%d",&b[i].data);
	  b[i].lab = i;
   }
   std::sort(b, b + n);
   for (int i = 0; i < n; ++i) pb[b[i].lab] = i;
   //memset(p,0,sizeof(p));
   for (int i = 0; i < n; ++i)
   if (!p[i]) {
	 p[i] = true;
	 int last = pa[i],now = pb[i], cnt = 1; 
	 while (last != now) 
	   p[a[now].lab] = true, 
	   now = pb[a[now].lab],
	   ++cnt;
	 ans = (ans  + cnt - 1) % 99999997;
  }
  printf("%d",ans);
 fclose(stdin); fclose(stdout);
}
   
	  
