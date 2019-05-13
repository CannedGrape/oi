#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 100000;

typedef struct tagNode 
{
	bool deleted;
	int val;
	tagNode *prev;
	tagNode *next;
} Node, *pNode;

Node s[MAXN];
pNode h[MAXN];
int n;

void movedown(int x)
{
	int y = x * 2;
	if (y > n)
		return ;
	if (y+1<=n && h[y+1]->val<h[y]->val)
		++y;
	if (h[x]->val > h[y]->val)
	{
		swap(h[x], h[y]);
		movedown(y);
	}
}

int main()
{
	freopen("backup.in", "rt", stdin);
	int m, k;
	cin >> m >> k;
	n = m - 1;
	int last;
	cin >> last;
	pNode lastp = 0;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		pNode tmp = s + i;
		tmp->deleted = false;
		tmp->val = x - last;
		tmp->prev = lastp;
		if (lastp)
			lastp->next = tmp;
		lastp = tmp;
		h[i + 1] = tmp;
		last = x;
	}
	lastp->next = 0;
	for (int i = n; i > 0; --i)
		movedown(i);
	int ans = 0;
	int tt = k;
	if (k)
		while (n)
		{
			pNode h1 = h[1];
			if (!h1->deleted)
			{
				ans += h1->val;
				
				if ((--tt) == 0)
					break;
				int newval = -h1->val;
				if (h1->prev)
				{
					newval += h1->prev->val;
					h1->prev->deleted = true;
					if (h1->prev = h1->prev->prev)
						h1->prev->next = h1;
				}
				else
					h1->deleted = true;
				if (h1->next)
				{
					newval += h1->next->val;
					h1->next->deleted = true;
					if (h1->next = h1->next->next)
						h1->next->prev = h1;
				}
				else
					h1->deleted = true;
				if (h1->deleted)
				{
					if (h1->next)
						h1->next->prev = 0;
					if (h1->prev)
						h1->prev->next = 0;
				}
				else
					h1->val = newval;
			}
			if (h[1]->deleted)
				h[1] = h[n--];
			movedown(1);
		}
	freopen("backup.out", "wt", stdout);
	cout << ans << endl;
	return 0;
}
