#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<queue>
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};
struct node{
  int x,y,i,j,dist;
  node(const int xx = 0, const int yy = 0, const int ii = 0, const int jj = 0, const int dd = 0) :
	 x(xx), y(yy), i(ii),j(jj),dist(dd) {}
};
int ex,ey,sx,sy,tx,ty,n,m,Q,map[32][32];
bool set[32][32][32][32];
bool check(int x, int y) {
  if (map[x][y] == 0) return true;
  int tmp = 0; 
  for (int i = 0; i < 4; ++i) 
    tmp = (map[x + dx[i]][y + dy[i]] ? tmp : tmp + 1);
  if (tmp >= 3) return true;
  return false;
}
void work1() {
	int nx,ny,ni,nj,nni,nnj;
	for (int t = 0; t < Q; ++t) {
      scanf("%d%d%d%d%d%d", &ex,&ey,&sx,&sy,&tx,&ty);
	  
	  if (sx == tx && sy == ty) {printf("0\n"); continue;}
	  if (ex == tx && ey == ty) {
		bool bol = false;
		for (int i = 0; i < 4; ++i) 
		  if (sx + dx[i] == tx && sy + dy[i] == ty){bol = true; break;}
		if (bol) {printf("1\n");continue;}
      }
      if (check(sx,sy) || check(tx,ty)) {printf("-1\n"); continue;}
      
	  memset(set,0,sizeof(set));
	  std::queue<node> q;
	  q.push(node(ex,ey,sx,sy,0));
	  set[ex][ey][sx][sy] = true;
	  int ans = -1;
	  while (q.size()) {
	    node u = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
		  nx = u.x + dx[i];
		  ny = u.y + dy[i];
		  if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
		  if (map[nx][ny] == 0) continue;
		  
		  if (nx == u.i && ny == u.j) 
			ni = u.x, nj = u.y;
		  else ni = u.i, nj = u.j;
		  
		  if (nx == tx && ny == ty) {
		    for (int j = 0; j < 4; ++j) {
			  nni = nx + dx[j], nnj = ny + dy[j];
			  if (nni == ni && nnj == nj) {ans = u.dist + 2;break;}
		   } 
 		  }  
		  if (ans != -1) break;
		  if (!set[nx][ny][ni][nj]) {
			q.push(node(nx,ny,ni,nj,u.dist + 1));
			set[nx][ny][ni][nj] = true; 	
		  } 
		}
	    if (ans != -1) break;
	 }
	 printf("%d\n",ans);
   }
}
int main() {
  freopen("puzzle.in","r",stdin);freopen("puzzle.out","w",stdout);
    scanf("%d%d%d",&n,&m,&Q);
    for (int i = 1; i <= n; ++i) 
      for (int j = 1; j <= m; ++j) scanf("%d", &map[i][j]);
    work1();
  fclose(stdin); fclose(stdout);
}
		
      
