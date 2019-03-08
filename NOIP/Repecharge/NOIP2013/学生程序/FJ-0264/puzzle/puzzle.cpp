#include <cstdio>
#include <queue>
const int N=31,NN=N*N*N*N,move[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
struct info{
	int x,y;
	info(const int a=0,const int b=0):
		x(a),y(b){}
}e,s,t;
struct inpo{
	info a1,a2;
	inpo(const info a=info(0,0),const info b=info(0,0)):
		a1(a),a2(b){}
};
struct inli{
	int next,data;
	inli(const int a=0,const int b=0):
		next(a),data(b){}
}line[NN*8];
std::queue <inpo> que;
std::queue <int> que2;
int n,m,q,map[N][N],bein[NN],son[NN],nl,np,bo[NN],dis[NN],tot;
int change(info a){ return (a.x-1)*m+a.y; }
int change2(inpo a){ return (change(a.a1)-1)*n*m+change(a.a2); }
bool check(info a,int t){
	int x=a.x+move[t][0],y=a.y+move[t][1];
	if (x<=0 || y<=0 || x>n || y>m) return 0;
	return map[x][y];
}
void bfs(inpo t){
	que.push(t);
	bein[change2(t)]=np;
	while (!que.empty()){
		inpo now=que.front();
		que.pop();
		for (int i=0;i<4;i++)
		if (check(now.a2,i)){
			inpo ne=inpo(now.a1,info(now.a2.x+move[i][0],now.a2.y+move[i][1]));
			if (ne.a1.x==ne.a2.x && ne.a1.y==ne.a2.y) ne=inpo(now.a2,now.a1);
			int xx=change2(ne),yy=change2(now);
			line[++nl]=inli(son[xx],yy),son[xx]=nl;
			line[++nl]=inli(son[yy],xx),son[yy]=nl;
			if (!bein[xx]){
				bein[xx]=np;
				que.push(ne);
			}
		}
	}
}
void makefat(){
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
	if (map[i][j])
	for (int k=1;k<=n;k++)
	for (int l=1;l<=m;l++)
	if (map[k][l] && !bein[change2(inpo(info(i,j),info(k,l)))]){
		++np;
		bfs(inpo(info(i,j),info(k,l)));
	}
}
int getans(int x,int y){
	while (!que2.empty()) que2.pop();
	que2.push(x);
	bo[x]=tot;
	dis[x]=0;
	while (!que2.empty()){
		int now=que2.front();
		que2.pop();
		for (int i=son[now];i;i=line[i].next)
		if (bo[line[i].data]!=tot){
			int ne=line[i].data;
			dis[ne]=dis[now]+1;
			if (ne==y)
			return dis[ne];
			que2.push(ne);
			bo[ne]=tot;
		}
	}
	return -1;
}
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++) scanf("%d",&map[i][j]);
	makefat();
	for (int i=1,x,y;i<=q;i++){
		scanf("%d%d",&x,&y);
		e=info(x,y);
		scanf("%d%d",&x,&y);
		s=info(x,y);
		scanf("%d%d",&x,&y);
		t=info(x,y);
		int ans=-1;
		for (int j=0;j<4;j++)
		if (check(t,j)){
			info ne=info(t.x+move[j][0],t.y+move[j][1]);
			x=change2(inpo(s,e)),y=change2(inpo(t,ne));
			if (!bein[x] || !bein[y] || bein[x]!=bein[y]) continue;
			++tot;
			int save=getans(x,y);
			if (ans==-1 || (save<ans && save!=-1)) ans=save;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
}
