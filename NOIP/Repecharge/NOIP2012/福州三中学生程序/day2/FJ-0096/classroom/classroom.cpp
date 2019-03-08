#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>
#include <string>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <stdlib.h>
using namespace std;
#define rep(i,a,b)  for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)
const int maxn = 100001;
int n,m,r[maxn],s[maxn],t[maxn],d[maxn],flag,tmp;
void Init(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)	scanf("%d",&r[i]);
	rep(i,1,m)	scanf("%d%d%d",&d[i],&s[i],&t[i]);
}
void Solve(){
		rep(i,1,m){
			rep(j,s[i],t[i]){
				if(r[j]<d[i]){
					flag=i;break;}
				else r[j]-=d[i];
				
				tmp++;
			}
			if(flag) break;
			if(tmp>80000000) break;
		}
		if(flag==0) cout<<"0"<<endl;
		else cout<<"-1"<<endl<<flag<<endl;		
}
int main(){
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);
	Init();
	Solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
