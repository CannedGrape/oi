#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
bool su( double x, long long y ){
	if( x-y>0 )
		return false;
	else{	
		for( long long i=2; i<=x-1; i++ ){
			if( y%i==0 && x!=1   )
				return false;
		}
		return true;
	}
}
int main(){
	long long 
		n,
		i,
		max=0;
	double
		j;	
	freopen( "prime.in","r",stdin );
	freopen( "prime.out","w",stdout );	
	cin>>n;
	for( i=2; i<n; i++ ){
		if( su(i,i) ){
			j=n/(i*1.0);
			if( su( j,j ) ){
				if( i>=j && i>max )
					max=i;
				if( i<=j && j>max )
					max=j;	
			}
		}
	}
	cout<<max<<endl;
	fclose(stdin);	
	fclose(stdout);
//	system("pause");
	return 0;
}
