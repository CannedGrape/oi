# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <algorithm>
# include <math.h>

using namespace std;

int edge[10001][10001],n,m,q;
int he[10001][10001];
void openFile() {
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
}
void init() {
	for (int i=1;i<=10000;i++) for (int j=1;j<=10000;j++) edge[i][j]=he[i][j]=-2140000000;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=m;i++) {
		int x,y,num;
		scanf("%d %d %d",&x,&y,&num);
		edge[x][y]=edge[y][x]=he[x][y]=he[y][x]=num;
	}
}
void work() {
	for (int k=1;k<=n;k++)
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				if (min(he[i][k],he[k][j]) > he[i][j]) he[i][j]=min(he[i][k],he[k][j]);
}
void oupt() {
	scanf("%d",&q);
	for (int i=1;i<=q;i++) {
		int f,t;
		scanf("%d %d",&f,&t);	
		if (he[f][t] < 0) printf("-1\n");
		else printf("%d\n",max(he[t][f],he[f][t]));
	}
}
int main() {
	openFile();
	init();
	work();
	oupt();
	return 0;
}
