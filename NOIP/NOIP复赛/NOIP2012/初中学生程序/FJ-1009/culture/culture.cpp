#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
int n,k,m,s,t,c[101],d[101][101];		//d[x][y]是第x号国家到第y号的距离
bool paichi[101][101],studied[101];	//studied[x] show us did he study c[x] or not
int tryy(int cn,int de){
	if (cn==t || !(studied[c[cn]])) return -1;
	studied[c[cn]]=true;
	int f,min=0,now;
	for (f=1;f<n;f++){
		if (d[cn][f]>0 && !paichi[cn][f]){
			now=tryy(f,d[cn][f]);
			if ((now<min && now>0)|| min==0) min=now;
			if (now<min && cn==f) {
				min=0;
				break;
			}
		}
	}
	studied[c[cn]]=false;
	return min+de;
}
int main(){
	int f,f2,b,u,v;
	freopen("culture.in","r",stdin);
	freopen("culture.out","w",stdout);
	scanf("%d %d %d %d %d",&n,&k,&m,&s,&t);
	for (f=1;f<=n;f++){
		for (f2=1;f2<=n;f2++){
			d[f][f2]=0;
		}
	}
	for (f=1;f<=n;f++) scanf("%d",&c[f]);
	for (f=1;f<=k;f++){
		for (f2=1;f2<=k;f2++){
			scanf("%d",&b);
			if (b==0) paichi[f][f2]=false;
			else paichi[f][f2]=true;
		}
	}
	for (f=0;f<m;f++){
		scanf("%d %d %d",&u,&v,&b);
		if ((d[u][v]>b && 0<b) || d[u][v]==0) d[u][v]=b;
	}
	printf("%d",tryy(s,0));
	return 0;
}