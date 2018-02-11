#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string>
using namespace std;
int N,M,u,v,Q;
int f[10010]={};
int find(int x){
    if(x!=f[x])f[x]=find(f[x]);
    return f[x];
}
struct edge{int u,v,t;}e[2000010];
struct ques{int v,next,ans;}q[1000010];
int qlast[2000010],qx=0,son[10010]={};
inline void addq(int u,int v){
       ++qx;
       q[qx].v=v;q[qx].next=qlast[u];qlast[u]=qx;q[qx].ans=-1;
}
bool cmp(edge a,edge b){
     return a.t>b.t;
}
void swap(int &a,int &b){
    int c;
    c=a;a=b;b=c;
}
struct son_link{int v,next;}p[2000010];
int lsts[2000010]={};
int main(){
    freopen("truck.in","r",stdin);freopen("truck.out","w",stdout);
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;++i){
            lsts[i]=i;
            p[i].v=i;p[i].next=0;
            f[i]=i;
            son[i]=1;
    }
    for(int i=1;i<=M;++i){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].t);
    }
    sort(e+1,e+1+M,cmp);
    scanf("%d",&Q);
    for(int i=1;i<=Q;++i){
            scanf("%d%d",&u,&v);
            addq(u,v);addq(v,u);
    }
    int fu,fv,tmp;
    for(int i=1;i<=M;++i){
            fu=find(e[i].u),fv=find(e[i].v);
            if(fu!=fv){
                       if(son[fv]<son[fu])swap(fu,fv);
                       f[fv]=fu;
                       for(int k=lsts[fu];k;k=p[k].next){//bianlierzi
                               for(int kk=qlast[p[k].v];kk;kk=q[kk].next)//erzi de xunwen
                                       if(q[kk].ans==-1 && find(q[kk].v)==find(p[k].v))q[kk].ans=e[i].t;
                               tmp=k;
                       }
                       son[fu]+=son[fv];son[fv]=0;
                       p[tmp].next=lsts[fv];
            }
    }
    for(int i=1;i<=2*Q;i+=2){
            if(q[i].ans<q[i+1].ans)q[i].ans=q[i+1].ans;
            printf("%d\n",q[i].ans);
    }
	fclose(stdin);fclose(stdout);
    return 0;
}
