#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

typedef long long ll;
using namespace std;

struct road{
	int s;int t;int v;
	bool operator<(const road& n)const {return n.v<v;}
};
road E[50000];

int fa[10010];
int find(int x){
	if(fa[x]!=x){return (fa[x]=find(fa[x]));}
	else{return fa[x];}
}
int con(int x,int y){
	return (fa[find(x)]=find(y));
}

inline int iptn(){
	int tmp=0;int c=0;
	//scanf("%d",&tmp);
	
	while((c=getchar())){
		c-='0';
		if((c>=0)&&(c<10)){break;}
	}
	tmp=c;
	while((c=getchar())){
		c-='0';
		if((c<10)&&(c>=0)){tmp=tmp*10+c;}
		else{break;}
	}
	return tmp;
}

int n,m,ps,pt,pv,q,s,t,ans;
int main(){
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	n=iptn();m=iptn();
	
	for(int i=0;i<m;++i){
		E[i].s=iptn();E[i].t=iptn();E[i].v=iptn();
	}
	sort(E,E+m);
	
	int q;q=iptn();
	while(q--){
		s=iptn();t=iptn();
		int i;ans=-1;for(int i=0;i<n+10;++i){fa[i]=i;}
		for(i=0;i<m;++i){
			ps=E[i].s; pt=E[i].t; pv=E[i].v;
			con(ps,pt);
			if(find(s)==find(t)){ans=pv;break;}
		}
		printf("%d\n",ans);
    }
	
	return 0;
}