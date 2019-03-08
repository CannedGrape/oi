#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
struct node
{
	int x,pos;
}ta[110000],tb[110000];
int a[110000],b[110000],a2[110000],b2[110000],pos1[110000];;
int n;
inline bool operator < (node lhs,node rhs)
{
	return lhs.x < rhs.x;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&n);
	for (int i = 1;i <= n;i ++)
	{
		scanf("%d",&a[i]);
		ta[i].x = a[i];
		ta[i].pos = i;
	}
	for (int i = 1;i <= n;i ++)
	{
		scanf("%d",&b[i]);
		tb[i].x = b[i];
		tb[i].pos = i;
	}
	sort(ta + 1,ta + n + 1);
	sort(tb + 1,tb + n + 1);
	for (int i = 1;i <= n;i ++)
	{
		a2[ta[i].pos] = i;
		b2[tb[i].pos] = i;
		pos1[i] = ta[i].pos;
	}
	//for (int i = 1;i <= n;i ++)
	//	printf("%d %d\n",pos1[i],b2[i]);
	int ans = 0;
	for (int i = 1;i <= n;i ++)
		if (a2[i] != b2[i])
		{
			ans ++;
			pos1[a2[i]] = pos1[b2[i]];
			swap(a2[i],a2[pos1[b2[i]]]);
		}
	cout << ans % 99999997;
	fclose(stdin);fclose(stdout);
}