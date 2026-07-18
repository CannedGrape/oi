#include <iostream>

using namespace std;

const int MODO = 65536;
const int MAXT = 65536+100;
const int HALF = 7;

int n, m, tree[MAXT], q[HALF][(1<<HALF)+10];

int low(int x)
{
	return (x&(x^(x-1)));	
}

void add_tree(int x)
{
	x++;
	while (x<MAXT){
		tree[x]++;
		x+=low(x);
	}	
}

int sum_tree(int x)
{
	int s=0;
	x++;
	while (x>0){
		s+=tree[x];
		x-=low(x);
	}
	return s;	
}

void init()
{
	int i, j, x1, x;
	
	scanf("%d%d", &n, &m);
	memset(tree, 0, sizeof(tree));
	memset(q, 0, sizeof(q));
	for (i=1; i<=n; i++){
		scanf("%d", &x);
		add_tree(x);
		for (j=0; j<HALF; j++)
			q[j][x%(1<<(j+1))]++;
	}
}

int get(int l, int r)
{
	if (l>=0 && r>=0)
		return sum_tree(r)-sum_tree(l-1);
	else
	if (r>=0)
		return sum_tree(r)+sum_tree(MODO-1)-sum_tree(l+MODO-1);
	else
		return sum_tree(r+MODO)-sum_tree(l+MODO-1);
}

void work()
{
	int delta, x, i, j, q1[HALF][(1<<HALF)+10];
	__int64 total, cur;
	char ch;
	
	delta=0;
	total=0;
	while (m--){
		scanf("%1s%d", &ch, &x);
		if (ch=='A'){
			delta=(delta+x)%MODO;
			for (i=0; i<HALF; i++){
				for (j=0; j<(1<<(i+1)); j++)
					q1[i][(j+x)%(1<<(i+1))]=q[i][j];
				for (j=0; j<(1<<(i+1)); j++)
					q[i][j]=q1[i][j];
			}
		}
		else
		{
			cur=0;
			if (x<HALF){
				for (i=(1<<x); i<(1<<(x+1)); i++)
					cur+=q[x][i];
			}
			else
			{
				i=(1<<x);
				while (i<MODO){
					cur+=get(i-delta, i+(1<<x)-1-delta);
					i+=(1<<(x+1));	
				}				
			}
			total+=cur;
		}	
	}
	printf("%I64d\n", total);
}

int main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	init();
	work();
	
	return 0;
}

