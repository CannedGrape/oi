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
typedef long long ll;
ll a,b,ans;
void Init(){
	cin>>a>>b;
}
void Solve(){
	if(a==(b+1))	cout<<"1"<<endl;
	else{
		for(ans=(b+1)/a;ans<b;ans++)
			if((a*ans)%b==1)
				break;
		cout<<ans<<endl;
	}	
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	Init();
	Solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
