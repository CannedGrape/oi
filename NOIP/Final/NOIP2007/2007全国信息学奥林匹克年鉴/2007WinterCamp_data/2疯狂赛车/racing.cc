#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const	int		limitSize	= 1000 + 10;
const	int		limitNode	= limitSize * limitSize * 2 + 10;
const	double		infinity	= 1e20;
const	double		pi		= acos(0.0) * 2;
const	double		eps		= 1e-6;

struct		Tpoint
{
	double	x , y;
	Tpoint(){}
	Tpoint(double x0 , double y0){ x = x0 , y = y0; }
	
	void	rotate(double theta)
	{
		double	r = sqrt(x * x + y * y);
		theta += atan2(y , x);
		x = r * cos(theta);
		y = r * sin(theta);
	}
	void	fixLength(double length)
	{
		double	r = sqrt(x * x + y * y);
		x = x / r * length;
		y = y / r * length;
	}
};

inline	Tpoint	operator + (const Tpoint& A , const Tpoint& B)
{
	return Tpoint(A.x + B.x , A.y + B.y);
}

inline	Tpoint	operator - (const Tpoint& A , const Tpoint& B)
{
	return	Tpoint(A.x - B.x , A.y - B.y);
}

inline	Tpoint	operator * (double k , const Tpoint& A)
{
	return	Tpoint(k * A.x , k * A.y);
}

inline	double	__distance(const Tpoint& A , const Tpoint& B)
{
	return sqrt( (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y) );
}

inline	Tpoint	crossPoint(const Tpoint& A , const Tpoint& B , const Tpoint& P , const Tpoint& Q)
{
	double	t = ((P.x - A.x) * (Q.y - P.y) - (P.y - A.y) * (Q.x - P.x))
		/   ((B.x - A.x) * (Q.y - P.y) - (B.y - A.y) * (Q.x - P.x));
	return	Tpoint(A.x + t * (B.x - A.x) , A.y + t * (B.y - A.y));
}

inline	double	dotProduct(const Tpoint& A , const Tpoint& B)
{
	return A.x * B.x + A.y * B.y;
}

inline	double	crossProduct(const Tpoint& A , const Tpoint& B)
{
	return A.x * B.y - A.y * B.x;
}

inline	bool	onSegment(const Tpoint& P , const Tpoint& A , const Tpoint& B)
{
	return	dotProduct( A - P , B - P ) < - eps;
}

inline	bool	conLine(const Tpoint& p0 , const Tpoint& p1 , const Tpoint& p2)
{
	return	fabs( crossProduct(p1 - p0 , p2 - p0) ) < eps;
}


struct		Tedge
{
	int	u;
	double	cost;

	Tedge(){}
	Tedge(int u0 , double cost0){ u = u0 , cost = cost0; }
};

struct		TnodeInfo
{
	int	u;
	double	distFromOrigin;
};

bool	operator < (const TnodeInfo& A , const TnodeInfo& B)
{
	if( fabs(A.distFromOrigin - B.distFromOrigin) < eps ) return 0;
	return A.distFromOrigin < B.distFromOrigin;
}

int		n , N;
double		va , vb;
Tpoint		list	[limitNode];

int		cnt	[limitSize];
TnodeInfo	online	[limitSize][limitSize * 2];
TnodeInfo	S	[limitSize * 2];

vector<Tedge>	mat	[limitNode];

void	init()
{
	scanf("%d" , &n); N = n;
	scanf("%lf%lf" , &va , &vb);
	list[0] = Tpoint(0 , 0);
	for(int i = 1; i <= n; i ++)
		scanf("%lf%lf" , &list[i].x , &list[i].y);
}

void	addEdge(int a , int b , double cost)
{
	mat[a].push_back( Tedge(b , cost) );
	mat[b].push_back( Tedge(a , cost) );

	//printf("(%.2lf %.2lf) --> (%.2lf %.2lf) , %.2lf\n" , list[a].x , list[a].y , list[b].x , list[b].y , cost);
}

void	addKeyPoint(const Tpoint& P , const Tpoint& A , const Tpoint& B , int idx , int start)
{
	if( onSegment(P , A , B) )
	{
		list[ ++ N ] = P;

		online[ idx ][ cnt[idx] ].u = N;
		online[ idx ][ cnt[idx] ].distFromOrigin = __distance(P , A);
		cnt[idx] ++;

		addEdge(start , N , __distance(P , list[start]) / vb);
	}
}

void	calcKeyPoint(const Tpoint& P , const Tpoint& A , const Tpoint& B , int idx , int start)
{
	Tpoint	alpha = B - A;
	alpha.rotate( pi / 2.0 );
	Tpoint	Q = P + alpha;

	Tpoint	H = crossPoint(P , Q , A , B);
	double	h = __distance(H , P);
	double	k = (vb / va);
	double	x = sqrt( k * k * h * h / (1 - k * k) );

	alpha = (B - A);
	alpha.fixLength(x);

	addKeyPoint(H + alpha , A , B , idx , start);
	addKeyPoint(H - alpha , A , B , idx , start);
}

void	process()
{
	int	i , j , p;

	memset(cnt , 0 , sizeof(cnt));	
	for(i = 0; i <= N; i ++)
		mat[i].clear();

	for(i = 0; i <= n; i ++)
	{
		for(j = 0; j < n; j ++)
		{
			if( i == j || i == j + 1 ) continue;
			if( conLine(list[i] , list[j] , list[j + 1]) ) continue;
			calcKeyPoint(list[i] , list[j] , list[j + 1] , j , i);
		}
	}

	for(i = 0; i <= n; i ++)
		for(j = i + 1; j <= n; j ++)
		{
			if( i + 1 == j ) addEdge(i , j , __distance(list[i] , list[j]) / va);
			else addEdge(i , j , __distance( list[i] , list[j] ) / vb);
		}

	for(i = 0; i < n; i ++)
	{
		S[0].u = i; S[1].distFromOrigin = 0;
		for(p = 0; p < cnt[i]; p ++)
			S[p + 1] = online[i][p];
		S[cnt[i] + 1].u = i + 1; S[cnt[i] + 1].distFromOrigin = __distance(list[i] , list[i + 1]);

		//printf("%d\n" , cnt[i]);
		
		sort(S , S + cnt[i] + 2);
		for(p = 0; p <= cnt[i]; p ++)
			addEdge(S[p].u , S[p + 1].u , (S[p + 1].distFromOrigin - S[p].distFromOrigin) / va);
	}
}

struct			Theap
{
	int	heapSize;
	double	low	[limitNode];
	int	heap	[limitNode];
	int	pos	[limitNode];

	void	init()
	{
		heapSize = 1; low[0] = 0;
		heap[1] = 0; pos[0] = 1;

		for(int i = 1; i <= N; i ++)
		{
			low[i] = infinity;
			heap[ ++ heapSize ] = i;
			pos[i] = heapSize;
		}
	}

	void	getMin(int& u , double& min)
	{
		u = heap[1];
		min = low[u];

		heap[1] = heap[ heapSize -- ];
		pos[ heap[1] ] = 1;
		pos[ u ] = 0;

		heapifyDown( 1 );
	}

	void	renew(int v , double cost)
	{
		if( pos[v] )
		{
			if( cost < low[v] )
			{
				low[v] = cost;
				heapifyUp( pos[v] );
			}
		}
	}

	void	heapifyDown(int u)
	{
		int	min = u;
		int	left = u * 2;
		int	right = u * 2 + 1;

		if( left <= heapSize && heapSmaller(left , min) ) min = left;
		if( right <= heapSize && heapSmaller(right , min) ) min = right;

		if( min != u )
		{
			heapSwap(min , u);
			heapifyDown( min );
		}
	}

	void	heapifyUp(int u)
	{
		while( u > 1 && heapSmaller(u , u / 2) )
		{
			heapSwap(u , u / 2);
			u /= 2;
		}
	}

	inline	bool	heapSmaller(int a , int b)
	{
		return	low[ heap[a] ] < low[ heap[b] ];
	}

	inline	void	heapSwap(int a , int b)
	{
		int	t;
		t = heap[a]; heap[a] = heap[b]; heap[b] = t;
		pos[heap[a]] = a; pos[heap[b]] = b;
	}
}			heap;

void	solve()
{
	double		min;
	int		u , i , size;

	heap.init();

	while( 1 )
	{
		heap.getMin(u , min);
		if( u == n ) break;

		size = mat[u].size();
		for(i = 0; i < size; i ++)
			heap.renew(mat[u][i].u , min + mat[u][i].cost);		
	}

	printf("%.6lf\n" , min);
	//printf("force way = %.6lf\n" , __distance(list[0] , list[n]) / vb);
}

int	main()
{
	//freopen("racing.in" , "r" , stdin);
	//freopen("racing.out" , "w" , stdout);

	init();
	process();
	solve();

	return 0;
}
