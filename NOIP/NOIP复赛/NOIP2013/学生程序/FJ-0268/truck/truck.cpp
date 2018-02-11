#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct node{
	int x,next,v;
}line[101000];
int n,m,son[10100],len,l,dui[10100],d[10100],ques,uss[10010];
bool pd[10100];
int col[10001],a,b;
void update(int x){
	if (x==1) return ;
	if (d[dui[x]]>d[dui[x/2]]){
		swap(dui[x],dui[x/2]);
		uss[dui[x]]=x;uss[dui[x/2]]=x/2;
		update(x/2);
	}
}
void add(int x){
	dui[++len]=x;
	uss[x]=len;
	update(len);
}
void down(int x){
	int j=x;
	if (x*2<=len && d[dui[j]]<d[dui[x*2]]) j=x*2;
	if (x*2<len && d[dui[j]]<d[dui[x*2+1]]) j=x*2+1;
	if (j==x) return ;
	swap(dui[x],dui[j]);
	uss[dui[x]]=x;uss[dui[j]]=j;
	down(j);
}
void dec(int x){
	dui[1]=dui[len--];
	down(1);
}
int main(){
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1,c;i<=m;i++){
		scanf("%d%d%d",&a,&b,&c);
		line[++len].next=son[a];son[a]=len;line[len].x=b;line[len].v=c;
		line[++len].next=son[b];son[b]=len;line[len].x=a;line[len].v=c;
	}
	scanf("%d",&ques);
	for (int i1=1;i1<=ques;i1++){
		int x,y;scanf("%d%d",&x,&y);
		memset(d,-1,sizeof(d));
		memset(dui,0,sizeof(dui));
		memset(pd,true,sizeof(pd));
		memset(uss,0,sizeof(uss));
		d[x]=101000;l=1;pd[x]=false;
		dui[1]=x;uss[x]=1;
		for (int i=1;i<=n && l>0;i++){
			if (d[dui[1]]==-1) break;
			int now=dui[1];dec(1);
			if (now==y) break;
			//cout<<d[now]<<endl;
			for (int j=son[now];j;j=line[j].next)
			  if (min(d[now],line[j].v)>d[line[j].x]){
					d[line[j].x]=min(d[now],line[j].v);
					//cout<<d[line[j].x]<<"    "<<line[j].x<<"    "<<pd[line[j].x]<<endl;
					if (pd[line[j].x]){
						pd[line[j].x]=false;
						//cout<<d[line[j].x]<<"    "<<line[j].x<<endl;
						add(line[j].x);
					}else {
						//cout<<line[j].x<<"     "<<dui[uss[line[j].x]]<<endl;
						update(uss[line[j].x]);
					}
			  }
		}
		printf("%d\n",d[y]);
	  }
	fclose(stdin);
	fclose(stdout);
}
