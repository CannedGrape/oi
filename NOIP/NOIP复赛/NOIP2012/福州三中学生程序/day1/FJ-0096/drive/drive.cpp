#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <string.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stdlib.h>
using namespace std;
#define rep(i,a,b)	for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)
const int maxn = 100001,maxm = 10001,INF = 0x3fffffff;
int n,h[maxn],firstc[maxn],secondc[maxn],limitx,suma,sumb,q,nowx,ansx,ansh,x[maxm],s[maxm],m;
double ans;
void Init(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&h[i]);
		firstc[i]=-1;
		secondc[i]=-1;}
	down(i,n-1,1){
		int max1,max2,k1,k2,maxh1,maxh2;
		max1=INF,max2=INF;
		k1=-1,k2=-1;
		rep(j,i+1,n){
			if(int(abs(h[i]-h[j]))<max1||((int(abs(h[i]-h[j]))==max1)&&(h[j]<maxh1)))
				k1=j,max1=int(abs(h[i]-h[j])),maxh1=h[j];}
		rep(j,i+1,n)
			if(j!=k1){
				if(int(abs(h[i]-h[j]))<max2||((int(abs(h[i]-h[j]))==max2)&&(h[j]<maxh2))){
					k2=j,max2=int(abs(h[i]-h[j])),maxh2=h[j];		
				}
			}
		firstc[i]=k1;
		secondc[i]=k2;
	}
}
void Solve(){
	q=0;//0代表下一个是A走，1代表B走 
	scanf("%d",&limitx);
	ans=INF;
	rep(i,1,n){
		nowx=i;suma=0;sumb=0;
		double kl;
		while(suma+sumb<=limitx){
			if(q==0){
				if(secondc[nowx]!=-1&&(suma+sumb+int(abs(h[nowx]-h[secondc[nowx]]))<=limitx)){
					suma+=int(abs(h[nowx]-h[secondc[nowx]]));
					nowx=secondc[nowx];q=1;}
				else break;}
			else {
				if(firstc[nowx]!=-1&&(suma+sumb+int(abs(h[nowx]-h[firstc[nowx]]))<=limitx)){
					sumb+=int(abs(h[nowx]-h[firstc[nowx]]));
					nowx=firstc[nowx];q=0;}
				else break;}
		}
			if(sumb==0)	kl=INF;
			if(suma!=0&&sumb!=0)	kl=double(suma)/double(sumb);
		if(kl<ans||(kl==ans&&h[i]>ansh))
			ans=kl,ansh=h[i],ansx=i;	
	}
	printf("%d\n",ansx);
	scanf("%d",&m);
	rep(i,1,m)
		scanf("%d%d",&s[i],&x[i]);
	rep(i,1,m){
		q=0;
		nowx=s[i];suma=0;sumb=0;
		while(suma+sumb<=x[i]){
			if(q==0){
				if(secondc[nowx]!=-1&&(suma+sumb+int(abs(h[nowx]-h[secondc[nowx]]))<=x[i])){
					suma+=int(abs(h[nowx]-h[secondc[nowx]]));
					nowx=secondc[nowx];q=1;}
				else break;}
			else {
				if(firstc[nowx]!=-1&&(suma+sumb+int(abs(h[nowx]-h[firstc[nowx]]))<=x[i])){
					sumb+=int(abs(h[nowx]-h[firstc[nowx]]));
					nowx=firstc[nowx];q=0;}
				else break;}
		}
		printf("%d %d\n",suma,sumb);
	}
}
int main(){
	freopen("drive.in","r",stdin);
	freopen("drive.out","w",stdout);
	Init();
	Solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
