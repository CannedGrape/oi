#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

const	int		limitSize	= 500000 + 10;
const	long long	infinity	= (long long)1 << 62;

struct			Tdat
{
	long long	cap , weight;
};

inline	bool	operator < (const Tdat& A , const Tdat& B)
{
	return		A.cap + A.weight < B.cap + B.weight;
}

struct			Tnode
{
	int		left , right , father;
	int		prev , next;
	long long	opt , minOpt;
	long long	delta;
	long long	gap;
};

struct			DecisionTree
{
	int		L , top , root;
	long long	cap , weight;
	Tnode		tree	[limitSize * 2];

	void	init()	// CHECKED
	{
		L = 0; root = 1; top = 2; 

		tree[0].left = tree[0].right = tree[0].father = 0;
		tree[0].prev = tree[0].next = 0;
		tree[0].opt = tree[0].delta = 0; tree[0].minOpt = infinity;
		tree[0].gap = 0;

		tree[1].left = 0; tree[1].right = 2; tree[1].father = 0;
		tree[1].prev = 0; tree[1].next = 2;
		tree[1].opt = tree[1].delta = 0; tree[1].minOpt = 0;
		tree[1].gap = infinity;

		tree[2].left = tree[2].right = 0; tree[2].father = 1;
		tree[2].prev = 1; tree[2].next = 0;
		tree[2].opt = infinity; tree[2].delta = 0; tree[2].minOpt = infinity;
		tree[2].gap = infinity;
	}

	void	process(long long c0 , long long w0)
	{
		cap = c0; weight = w0;

		int	start , end;
		bool	incFlag = 0;

		end = findEnd( root );

		if( weight >= tree[ end ].gap ) return;
		if( tree[ tree[end].right ].minOpt == infinity ) incFlag = 1;

		start = findStart( end );

		//这里start与end是可以更新下一个位置的区间起止,[start,end],闭区间

		//在start前的一个位置copy一份start
		++ top;
		tree[top].left = tree[top].right = 0;
		tree[top].next = start; tree[top].prev = tree[start].prev;
		tree[top].opt = tree[top].minOpt = tree[start].opt;
		tree[top].delta = 0;
		tree[top].gap = weight;

		tree[start].prev = top;
		if( tree[top].prev )
		{
			tree[ tree[top].prev ].next = top;
			tree[ tree[top].prev ].right = top;
			tree[ top ].father = tree[top].prev;
		}
		else
		{
			tree[ start ].left = top;
			tree[ top ].father = start;
		}
		// 注意这里start的minOpt有问题

		//	删除end的下一个位置
		if( incFlag )
		{
			L ++; splay( end );
		}
		else deleteNode( end );
		end = root;
				
		/////	makeMark
		int	end_right = tree[ end ].right;

		tree[ end_right ].father = tree[ end ].right = 0;
		splay( start );
		tree[ start ].opt += weight; renewInfo( start );
		tree[ tree[start].right ].delta += weight;

		end_right = leftMost( end_right );
		splay( end_right );

		tree[ end_right ].left = start;
		tree[ start ].father = end_right;
		renewInfo( end_right );

		int	v = rightMost( tree[ start ].left );		// 目的是为了extendMark
		tree[ v ].gap = tree[ start ].opt - tree[v].opt;

		//int	u = rightMost( tree[ start ].right );			// 目的是为了extendMark
		//tree[ u ].gap = tree[ end_right ].gap - tree[u].gap;
		tree[end].gap = tree[end_right].opt - (tree[end].opt + weight);		// 与上面两句等效
		splay( v );
	}

	void	printSolution()
	{
		cout << L << endl;
		splay( rightMost( root ) );
		splay( rightMost( tree[root].left ) );
		cout << tree[root].opt << endl;
	}

	void	deleteNode(int x)
	{
		splay( x );
		x = leftMost( tree[x].right );
		splay( x );
		
		//可以保证, tree[x]的left和right都是存在的
		{
			int	a = tree[x].left;
			int	b = tree[x].right;

			tree[a].father = tree[b].father = 0;
			a = rightMost( a );
			b = leftMost( b );
			splay( a ); splay( b );

			tree[a].right = b; tree[a].next = b;
			tree[b].father = a; tree[b].prev = a;
			tree[a].gap = tree[b].opt - tree[a].opt;
			root = a;
		}
	}

	inline	int	leftMost(int x) // CHECKED
	{
		while( 1 )
		{
			extendMark( x );
			if( tree[x].left == 0 ) break;
			x = tree[x].left;
		}
		return x;
	}
	
	inline	int	rightMost(int x) // CHECKED
	{
		while( 1 )
		{
			extendMark( x );
			if( tree[x].right == 0 ) break;
			x = tree[x].right;
		}
		return x;
	}

	int	findStart(int x)	// CHECKED
	{
		int	start = x;
		int	tx;
		while( x )
		{
			extendMark( x );
			tx = x;
			if( weight < tree[x].gap )
			{
				start = x; x = tree[x].left;
			}
			else x = tree[x].right;			
		}
		splay( start );
		return start;
	}

	int	findEnd(int x)	// CHECKED
	{
		while( 1 )
		{
			extendMark( x );
			extendMark( tree[x].right );
			if( tree[x].right && tree[ tree[x].right ].minOpt <= cap ) x = tree[x].right;
			else if( tree[x].opt <= cap ) break;
			else x = tree[x].left;
		}
		splay( x );
		return x;
	}

	void	splay(int x)	// CHECKED
	{
		int	y , z;
		while( tree[x].father )
		{
			y = tree[x].father;
			if( tree[y].father == 0 )
			{
				if( x == tree[y].left ) rightRotate( x );
				else leftRotate( x );
			}
			else
			{
				z = tree[y].father;
				if( x == tree[y].left )
				{
					if( y == tree[z].left )
					{
						rightRotate( y );
						rightRotate( x );
					}
					else
					{
						rightRotate( x );
						leftRotate( x );
					}
				}
				else
				{
					if( y == tree[z].left )
					{
						leftRotate( x );
						rightRotate( x );
					}
					else
					{
						leftRotate( y );
						leftRotate( x );
					}
				}
			}
		}

		root = x;
	}

	void	leftRotate(int x)	// CHECKED
	{
		int	y , z;

		y = tree[x].father;
		z = tree[x].left;

		if( tree[ tree[y].father ].left == y ) tree[ tree[y].father ].left = x;
		else tree[ tree[y].father ].right = x;

		tree[x].father = tree[y].father; tree[x].left = y;
		tree[y].father = x; tree[y].right = z;
		tree[z].father = y;

		renewInfo( y );
		renewInfo( x );
	}

	void	rightRotate(int x)	// CHECKED
	{
		int		y , z;

		y = tree[x].father;
		z = tree[x].right;

		if( tree[ tree[y].father ].left == y ) tree[ tree[y].father ].left = x;
		else tree[ tree[y].father ].right = x;

		tree[x].father = tree[y].father; tree[x].right = y;
		tree[y].father = x; tree[y].left = z;
		tree[z].father = y;

		renewInfo( y );
		renewInfo( x );
	}

	inline	void	renewInfo(int x)	// CHECKED
	{
		if( x )
		{			
			if( tree[x].left ) tree[x].minOpt = tree[ tree[x].left ].minOpt + tree[ tree[x].left ].delta;
			else tree[x].minOpt = tree[x].opt;
		}
	}

	inline	void	extendMark(int x)	// CHECKED
	{
		if( x && tree[x].delta > 0 )
		{
			tree[x].opt += tree[x].delta;
			tree[x].minOpt += tree[x].delta;
			tree[ tree[x].left ].delta += tree[x].delta;
			tree[ tree[x].right ].delta += tree[x].delta;
			tree[x].delta = 0;
		}
	}

	/*
	void	showTree()
	{
		puts("===========================================================");
		printf("top = %4d , L = %4d , root = %4d\n" , top , L , root);
		trace( root );
	}

	void	trace( int x )
	{
		if( x == 0 ) return ;
		trace( tree[x].left );
		printf("Node(%2d) : l=%2d,r=%2d,fa=%2d | prev=%2d,next=%2d | opt=%.0lf,minOpt=%.0lf | del=%.0lf | gap=%.0lf\n" , 
			x , tree[x].left , tree[x].right , tree[x].father , tree[x].prev , tree[x].next , tree[x].opt , tree[x].minOpt , tree[x].delta , tree[x].gap);
		trace( tree[x].right );
	}
	*/
};

int			n;
Tdat			list	[limitSize];
DecisionTree		opt;

void	init()
{
	scanf("%d" , &n);
	int		c , w;
	for(int i = 0; i < n; i ++)
	{
		scanf("%d%d" , &c , &w);
		list[i].cap = c; list[i].weight = w;
	}
	sort(list , list + n);
}

void	solve()
{
	opt.init();
//	opt.showTree();
	for(int i = 0; i < n; i ++)
	{
		opt.process( list[i].cap , list[i].weight );
//		opt.showTree();
	}
	opt.printSolution();
}

int	main()
{
	freopen("pendant.in" , "r" , stdin);
	freopen("pendant.out" , "w" , stdout);

	init();
	solve();

	return 0;
}
