#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
const int maxn = 10000;//Need Change
char M[maxn],K[maxn],C[maxn];
int Mlen,Klen;
void Init(){
	gets(K);gets(M);
	Mlen = strlen(M),Klen = strlen(K);
	rep(i,0,Klen) if('A'<=K[i] && K[i]<='Z') K[i] += (-'A') + 'a';
}
int remulti(int a,int b){
	return (a-b+26)%26;
}
char charremulti(char a,char b){
	char plus = ('a'<=a && a<='z')?'a':'A';
	char ret = remulti(a-plus,b-'a');
	return ret+plus;
}
void solve(){
	rep(i,0,Mlen) C[i] = charremulti(M[i],K[i%Klen]);
	puts(C);
}
int main(){
	freopen("vigenere.in","r",stdin);
	freopen("vigenere.out","w",stdout);
	
	Init();
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


