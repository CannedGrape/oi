#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
typedef long long ll;
using namespace std;
int A[100000];

int m,n,j,ans;
struct lsh{int v;int i;
	int operator<(const lsh &k)const{
		return k.v>v;
	}
};
lsh H[100000];
void ls(){
	for(int i=1;i<=n;++i){
		H[i].v=A[i];H[i].i=i;
	}
	sort(H+1,H+n+1);
	int p=0,last=-1;
	for(int i=1;i<=n;++i){
		if(A[H[i].i]>last)++p;
		last=A[H[i].i];
		A[H[i].i]=p;
	}
}
int T[300000],S[300000],M=1;
int queryl(int x){
	////-out<<"ql"<<x<<endl;
	int s,t,ans=0;
	for(s=M,t=x+M;s^t^1;s>>=1,t>>=1){
		ans=max(ans,T[s|1]);
		if(t&1)ans=max(ans,T[t&(~1)]);
		//-out<<"q"<<s<<" "<<t<<" "<<ans<<endl;
	}
	//-out<<"qfin"<<ans<<endl;
	return ans;
}
int queryg(int x){
	//-out<<"qg"<<x<<endl;
	int s,t,ans=0;
	for(s=x+M,t=M-1+M;s^t^1;s>>=1,t>>=1){
		if(~s&1)ans=max(ans,S[s|1]);
		ans=max(ans,S[t&(~1)]);
		//-out<<"q"<<s<<" "<<t<<" "<<ans<<endl;
	}
	//-out<<"qfin"<<ans<<endl;
	return ans;
}
int insl(int x,int val){
	//-out<<"insl"<<x<<" "<<val<<endl;
	int i=x+M;
	T[i]=val;
	for(i>>=1;i;i>>=1){
		T[i]=max(T[i<<1],T[(i<<1)|1]);
		//-out<<"upl"<<i<<" "<<T[i]<<endl;
	}
	//-out<<endl;
	return 0;
}
int insg(int x,int val){
	//-out<<"insg"<<x<<" "<<val<<endl;
	int i=x+M;
	S[i]=val;
	for(i>>=1;i;i>>=1){
		S[i]=max(S[i<<1],S[(i<<1)|1]);
		//-out<<"upg"<<i<<" "<<S[i]<<endl;
	}
	//-out<<endl;
	return 0;
}
int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&A[i]);
	}
	ls();
	
	//ZKW START
	while(M<=n+1)M<<=1;
	for(int i=1;i<=n;++i){
		int il=queryl(A[i]);
		if(il)il++;
		insg(A[i],il);
		int ig=queryg(A[i])+1;
		insl(A[i],ig);
	}
	ans=max(S[1],T[1]);
	memset(S,0,sizeof(S));
	memset(T,0,sizeof(T));
	for(int i=1;i<=n;++i){
		int ig=queryg(A[i]);
		if(ig)ig++;
		insl(A[i],ig);
		int il=queryl(A[i])+1;
		insg(A[i],il);
	}
	ans=max(ans,max(S[1],T[1]));
	printf("%d\n",ans);
	return 0;
}