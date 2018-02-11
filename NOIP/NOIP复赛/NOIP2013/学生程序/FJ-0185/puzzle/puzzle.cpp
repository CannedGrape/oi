#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>

using namespace std;

const int inci[4]={-1,0,1,0};
const int incj[4]={0,1,0,-1};
const int MOD=3000000;

struct R{
  int step,bli,blj,M[12][12];
};

int N,M,Q,EX,EY,SX,SY,TX,TY,Map[12][12],able[12][12];
bool visited[MOD];

void work();
int describe(int[12][12]);
void output(int[12][12]);

int main(){
  freopen("puzzle.in","r",stdin);
  freopen("puzzle.out","w",stdout);
  cin >> N >> M >> Q;
  int x;
  for (int i=1;i<=N;++i)
    for (int j=1;j<=M;++j) scanf("%d",&able[i][j]);
  while (Q--) work();
  return 0;
}

//0:unmoveable 1:moveable 2:start 3:blank;
void work(){
  queue <R> q;
  cin >> EX >> EY >> SX >> SY >> TX >> TY;
  for (int i=1;i<=N;++i)
    for (int j=1;j<=M;++j)
      Map[i][j]=able[i][j];
  Map[SX][SY]=2; Map[EX][EY]=3;
  memset(visited,false,sizeof(visited));
  visited[describe(Map)]=true;
  R rec;
  for (int i=1;i<=N;++i)
    for (int j=1;j<=M;++j)
      rec.M[i][j]=Map[i][j];
  rec.step=0;
  rec.bli=EX; rec.blj=EY;
  q.push(rec);
  //output(rec.M);
  int tmp;
  while (!q.empty()){
    R re=q.front(); q.pop();
    for (int k=0;k<4;++k){
      int nexti=re.bli+inci[k],nextj=re.blj+incj[k];
      if (nexti<1 || nexti>N || nextj<1 || nextj>M || !re.M[nexti][nextj]) continue;
      //swap(re.M[re.bli][re.blj],re.M[nexti][nextj]);
      int t=re.M[re.bli][re.blj];
      re.M[re.bli][re.blj]=re.M[nexti][nextj];
      re.M[nexti][nextj]=t;
      tmp=describe(re.M);
      if (visited[tmp]) continue;
      visited[tmp]=true;
      R re_=re;
      //swap(re.M[re.bli][re.blj],re.M[nexti][nextj]);
      //swap(re_.M[re.bli][re.blj],re_.M[nexti][nextj]);
      t=re.M[re.bli][re.blj];
      re.M[re.bli][re.blj]=re.M[nexti][nextj];
      re.M[nexti][nextj]=t;
      ++re_.step;
      re_.bli=nexti; re_.blj=nextj;
      if (re_.M[TX][TY]==2){
	printf("%d\n",re_.step);
	//output(re.M);
	//output(re_.M);
	return;
      }
      q.push(re_);
    }
  }
  printf("-1\n");
}

int describe(int A[12][12]){
  int hash=0;
  for (int i=1;i<=N;++i)
    for (int j=1;j<=M;++j)
      hash=((hash*133+A[i][j]*i-A[i][j]*j)%MOD+MOD)%MOD;
  return hash;
}

void output(int A[12][12]){
  for (int i=1;i<=N;++i){
    for (int j=1;j<=M;++j) cout << A[i][j] << " ";
    cout << endl;
  }
}
