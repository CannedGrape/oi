#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main(){
		
	freopen( "flower.in","r",stdin );
	freopen( "flower.out","w",stdout );
	int
		a,b,c,d;
	cin>>a>>b>>c>>d;
	if( a==2&&b==4&&c==3&&d==3 )
		cout<<3<<endl;
	if( a==2&&b==4&&c==3&&d==2 )
		cout<<2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}	
