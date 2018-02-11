#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
#define F(i,j,k) for (int i=j;i<=k;i++)

struct node{
	int ex,ey,sx,sy,w;
};
int xx[4]={1,0,-1,0};
int yy[4]={0,1,0,-1};
int n,m,qq;
bool map[50][50];
bool pd[50][50][50][50];
node q[500050];
int head,tail;
int bfs(){
	int ex,ey,sx,sy,tx,ty;
	cin>>ex>>ey>>sx>>sy>>tx>>ty;
	memset(pd,0,sizeof(pd));
	q[1]=(node){ex,ey,sx,sy,0};
	pd[ex][ey][sx][sy]=1;
	head=0;
	tail=1;
	int ans=-1;
	do{
		head=head+1;
		if (head>500000){
			head=1;
		}
		node u=q[head];
/*		F(i,1,n){
			F(j,1,m){
				if (i==u.ex && j==u.ey){
					cout<<" ";
					continue;
				}
				if (i==u.sx && j==u.sy){
					cout<<'!';
					continue;
				}
				if (i==tx && j==ty){
					cout<<"x";
					continue;
				}
				cout<<map[i][j];
			}
			cout<<endl;
		}
		cout<<endl;*/
		F(i,0,3){
			node v=u;
			if (u.ex+xx[i]==u.sx && u.ey+yy[i]==u.sy){
				int temp;
				temp=v.ex;
				v.ex=v.sx;
				v.sx=temp;
				temp=v.ey;
				v.ey=v.sy;
				v.sy=temp;
				if (v.sx==tx && v.sy==ty){
					ans=u.w+1;
					return ans;
				}
			}else{
				v.ex+=xx[i];
				v.ey+=yy[i];
			}
			if (!pd[v.ex][v.ey][v.sx][v.sy] && map[v.ex][v.ey] && map[v.sx][v.sy]){
				pd[v.ex][v.ey][v.sx][v.sy]=1;
				v.w=u.w+1;
				tail=tail+1;
				if (tail>1000000){
					tail=1;
				}
				q[tail]=v;
			}
		}
	}while (head!=tail);
	return -1;
}
int main(){
	freopen("puzzle.in","r",stdin);
	freopen("puzzle.out","w",stdout);
	cin>>n>>m>>qq;
	memset(map,0,sizeof(map));
	F(i,1,n){
		F(j,1,m){
			int k;
			cin>>k;
			if (k){
				map[i][j]=1;
			}else map[i][j]=0;
		}
	}
	while (qq--){
		cout<<bfs()<<endl;
	}
	return 0;
}
