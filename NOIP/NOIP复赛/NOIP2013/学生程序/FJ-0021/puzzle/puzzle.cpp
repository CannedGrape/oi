#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
// S --> pos of empty block
// ++RP
// if i have more time , i will try to union some query so that program can run faster
const int MaxN = 31;
const int Qsize = 1048576 * 2 + 1111;
int n,m;
struct q{
	int S,t;
	q(int S, int t):S(S),t(t){;}
	q(){S = t = 0;}
}Q[1048576 * 2 + 1111]; //  clear before use!!!
/*
State :
[high 10] PLayer Block
[low  10] empty Block
Move -- >
move empty block to each block that can be.
bty.
if this action move with player block update it.

use pos from [0..29]
*/
bool used[1048576 * 2 + 1111]; // clear before use!!!
int Pos2S(int x/*line*/, int y/*col*/){
	return y + x * m;
};
int S2X(int S){
	return S%m;
}
int S2Y(int S){
	return S/m;
}
int make_S(int SPlayer, int SEmpty){
	return (SPlayer << 10) | SEmpty;
}
int get_Player(int S){
	return S >> 10;
}
int get_Empty(int S){
	return S & ((1 << 10) - 1);
}
bool map[MaxN * MaxN];
int msize = 0; // < n * m
int head , tail;
void push(q c){
	Q[tail++] = c;
	if (tail >= Qsize) 
		tail = 0;
}
int work(int ex,int ey,int sx,int sy, int tx, int ty){
	head = tail = 0;
	int stop = Pos2S(tx,ty);
	memset(Q, 0, sizeof(Q));
	memset(used,0, sizeof(used));
	int SS = make_S(Pos2S(sx,sy),Pos2S(ex,ey));
	Q[tail++] = q(SS, 0);
	used[SS] = true;
	while (head != tail){
		q cur = Q[head++];
		if (head >= Qsize)
			head = 0;
		int Sp = get_Player(cur.S);
		int Se = get_Empty(cur.S);
		// printf("Player: (%d, %d) Empty: (%d, %d)\n",S2X(Sp),S2Y(Sp),S2X(Se),S2Y(Se));
		if (get_Player(cur.S) == stop)
			return cur.t;
		if (Se - m >= 0 && map[Se - m]){
			int Np = Sp, Ne = Se - m;
			if (Ne == Np)
				Np = Se;
			if (Np == stop)
				return cur.t + 1;
			int Ns = make_S(Np, Ne);
			if (!used[Ns]){
				push(q(Ns, cur.t + 1));
				used[Ns] = true;
			}
		}
		if (Se + m < msize && map[Se + m]){
			int Np = Sp, Ne = Se + m;
			if (Ne == Np)
				Np = Se;
			if (Np == stop)
				return cur.t + 1;
			int Ns = make_S(Np, Ne);
			if (!used[Ns]){
				push(q(Ns, cur.t + 1));
				used[Ns] = true;
			}
		}
		if (S2Y(Se) + 1 < m && map[Se + 1]){
			int Np = Sp, Ne = Se + 1;
			if (Ne == Np)
				Np = Se;
			if (Np == stop)
				return cur.t + 1;
			int Ns = make_S(Np, Ne);
			if (!used[Ns]){
				push(q(Ns, cur.t + 1));
				used[Ns] = true;
			}
		}
		if (S2Y(Se) - 1 >= 0 && map[Se - 1]){
			int Np = Sp, Ne = Se - 1;
			if (Ne == Np)
				Np = Se;
			if (Np == stop)
				return cur.t + 1;
			int Ns = make_S(Np, Ne);
			if (!used[Ns]){
				push(q(Ns, cur.t + 1));
				used[Ns] = true;
			}
		}
	}
	return -1;
};
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	// check S -> (X,Y) nothing.
	// check (S1,S2) -> (S) nothing.
	int q;
	scanf("%d%d%d",&n,&m,&q);
	msize = n * m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x = 0;scanf("%d",&x);
			map[Pos2S(i,j)] = x;
		}
	for (int i = 0; i < q; i++){
		int ex, ey, sx, sy,  tx, ty;
		scanf("%d%d%d%d%d%d",&ex,&ey,&sx,&sy,&tx,&ty);
		if (tx == sx && ty == sy){
			puts("0");
			continue;
		}
		if (map[Pos2S(tx-1,ty-1)] == false || map[Pos2S(sx-1,sy-1)] == false){
			puts("-1");
			continue;
		}
		printf("%d\n",work(ex-1,ey-1,sx-1,sy-1,tx-1,ty-1));
	}
}
