#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;

int N,M,K,X;
int Ans;

int Ksm(const int &xi,const int &ki) {
	int Cx=xi,Ck=ki,Sum=1;
	while (Ck>0) {
		if (Ck&1) Sum=1LL*Sum*Cx%N;
		Cx=1LL*Cx*Cx%N;
		Ck=Ck>>1;
	}
	return Sum;
} 

int main() {
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
    scanf("%d%d%d%d",&N,&M,&K,&X);
    Ans=Ksm(10,K); Ans=(X+Ans*M)%N; if (Ans<0) Ans+=N;
	cout<<Ans<<endl;
	//system("pause");
	fclose(stdin);fclose(stdout);
	return 0; 
}
