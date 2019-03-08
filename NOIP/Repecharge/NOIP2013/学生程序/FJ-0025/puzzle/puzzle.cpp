#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

#define FORBID 0
#define BLANK 3
#define CHESS 1
#define GIVEN 2
#define TARGET 10

const int maxn = 35;

struct Point
{
	int x, y, gx, gy, step;
};

int mat[maxn][maxn];
int N, M, Q;
int a, b, c, d, e, f;
bool vis[maxn][maxn] = {{0}};

int BFS()
{
	memset(vis, 0, sizeof(vis));
	Point temp;
	queue<Point> q;
	bool flag = false;
	
	temp.x = a;
	temp.y = b;
	temp.gx = c;
	temp.gy = d;
	temp.step = 0;
	
	q.push(temp);
	vis[a][b] = true;
	
	while(!q.empty())
	{
		Point now = q.front();
		int tx = now.x, ty = now.y;
		int ngx = now.gx, ngy = now.gy;
		int nx, ny;
		
		if(tx == e && ty == f)
			flag = true;
		else
			flag = false;
		
		temp.step = now.step + 1;
		
		if(temp.step > N * M)
			break;
		
		//up
		nx = tx - 1;
		ny = ty;
		temp.gx = ngx;
		temp.gy = ngy;
		if(nx > 0 && mat[nx][ny] != FORBID && !vis[nx][ny])
		{
			temp.x = nx;
			temp.y = ny;
			vis[nx][ny] = true;
			if(nx == ngx && ny == ngy)
			{
				temp.gx = tx;
				temp.gy = ty;
				vis[nx][ny] = false;
				if(flag)
					return temp.step;
			}
			q.push(temp);
			
		}
		//down
		nx = tx + 1;
		ny = ty;
		temp.gx = ngx;
		temp.gy = ngy;
		if(nx <= N && mat[nx][ny] != FORBID && !vis[nx][ny])
		{
			temp.x = nx;
			temp.y = ny;
			vis[nx][ny] = true;
			if(nx == ngx && ny == ngy)
			{
				temp.gx = tx;
				temp.gy = ty;
				vis[nx][ny] = false;
				if(flag)
					return temp.step;
			}
			q.push(temp);
		}
		//left
		nx = tx;
		ny = ty - 1;
		temp.gx = ngx;
		temp.gy = ngy;
		if(ny > 0 && mat[nx][ny] != FORBID && !vis[nx][ny])
		{
			temp.x = nx;
			temp.y = ny;
			vis[nx][ny] = true;
			if(nx == ngx && ny == ngy)
			{
				temp.gx = tx;
				temp.gy = ty;
				vis[nx][ny] = false;
				if(flag)
					return temp.step;
			}
			q.push(temp);
		}
		//right
		nx = tx;
		ny = ty + 1;
		temp.gx = ngx;
		temp.gy = ngy;
		if(ny <= M && mat[nx][ny] != FORBID && !vis[nx][ny])
		{
			temp.x = nx;
			temp.y = ny;
			vis[nx][ny] = true;
			if(nx == ngx && ny == ngy)
			{
				temp.gx = tx;
				temp.gy = ty;
				vis[nx][ny] = false;
				if(flag)
					return temp.step;
			}
			q.push(temp);
		}
		//end
		q.pop();
	}
	return -1;
}


int main()
{
    freopen("puzzle.in", "r", stdin);
    freopen("puzzle.out", "w", stdout);
    
    scanf("%d%d%d", &N, &M, &Q);
    for(int i = 1; i <= N; ++i)
    	for(int j = 1; j <= M; ++j)
    		scanf("%d", &mat[i][j]);
    for(int i = 1; i <= Q; ++i)
    {
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		mat[a][b] = BLANK;
		mat[c][d] = GIVEN;
		mat[e][f] = TARGET;
		cout << BFS() << endl;
		mat[a][b] = mat[c][d] = mat[e][f] = CHESS;
	}

    return 0;
}

