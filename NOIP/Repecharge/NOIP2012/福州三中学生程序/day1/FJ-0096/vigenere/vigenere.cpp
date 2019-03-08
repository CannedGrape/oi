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
using namespace std;
#define rep(i,a,b)	for(int i=(a);i<=(b);i++)
#define down(i,a,b) for(int i=(a);i>=(b);i--)
const int maxm = 1001;
int a[maxm][maxm],len1,len2,key[maxm],w[maxm],p,c[maxm];
char s1[maxm],s2[maxm];
int change(int x){
	if(x>=97)
		return x-97+1;
	if(x<=90)
		return x-65+1;
}
void Init(){
	rep(i,1,26)
		rep(j,1,26){
			int h;
			h=(i+j-1)%26;
			if(h==0)	h=26;
			a[i][h]=j;
	}
	scanf("%s",&s1);
	scanf("%s",&s2);
}
void Solve(){
	len1=strlen(s1);len2=strlen(s2);
	rep(i,0,len1-1)
		key[i+1]=int(s1[i]);
	key[0]=key[len1];
	rep(i,0,len2-1)
		w[i+1]=int(s2[i]);
	rep(i,1,len2){
		int j1,j2;
		j1=change(w[i]);
		j2=change(key[i%len1]);
		c[i]=a[j2][j1];
		if(w[i]>=97)  c[i]=c[i]+97-1;
		if(w[i]<=90)  c[i]=c[i]+65-1;}
	rep(i,1,len2)
		cout<<char(c[i]);
	cout<<endl;
}
int main(){
	freopen("vigenere.in","r",stdin);
	freopen("vigenere.out","w",stdout);
	Init();
	Solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
