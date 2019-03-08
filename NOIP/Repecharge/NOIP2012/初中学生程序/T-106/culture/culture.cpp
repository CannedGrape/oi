#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int n,k,m,s,t,c[101]={},link[101][101];
int minl=2147483647;
bool h=false;
bool a[101][101]={};
bool g[101][101]={};
int r_c[10000]={};
bool nf(int x,int l){
	for(int i=1;i<=l;i++){
		if(c[r_c[i]]==c[x]||a[x][r_c[i]]){
			return false;
		}
	}
	return true;
}
void road(int city,int dis,int d){
	if(city==t){
		if(dis<minl){
			minl=dis;
		}
		h=true;
	}
	for(int i=1;i<=n;i++){
		if(g[city][i]&&nf(i,d)){
			r_c[d]=i;
			road(i,dis+link[city][i],d+1);
		}
	}
}
int main(){
	freopen("culture.in","r",stdin);
	freopen("culture.out","r",stdout);
	int u,v,d;
	cin>>n>>k>>m>>s>>t;
	memset(link,127,sizeof(link));
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		cin>>u>>v>>d;
		g[u][v]=g[v][u]=true;
		link[u][v]=link[v][u]=(link[u][v]<d?link[u][v]:d);
	}
	if(a[t][s]||c[s]==c[t]){
		cout<<-1;
		return 0;
	}
	r_c[1]=c[s];
	road(s,0,1);
	if(!h) cout<<"!h:";
	cout<<(h?minl:-1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
