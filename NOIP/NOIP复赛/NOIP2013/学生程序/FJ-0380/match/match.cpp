#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>

typedef long long ll;
using namespace std;
struct match{
	int s;int t;
	bool operator<(const match& n)const {return n.s>s;}
};
match S[100010];
int E[100010];
int m,ans;


int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d",&m);
	for(int i=0;i<m;++i){
		scanf("%d",&S[i].s);
	}
	for(int i=0;i<m;++i){
		scanf("%d",&S[i].t);
	}
	sort(S,S+m);
	for(int i=0;i<m;++i){
		E[i]=S[i].t;
	}
	for(int i=0;i<m;++i){
		int q=E[i];
		for(int j=0;j<i;++j){
			if(E[j]>q)ans++;
		}
		ans%=99999997;
	}
	cout<<ans<<endl;
	return 0;
}