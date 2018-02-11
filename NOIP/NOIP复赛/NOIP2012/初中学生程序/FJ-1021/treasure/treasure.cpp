#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int main(){
	int 
		n,
		m,
		start,
		miyao=0,
		j,
		k,
		a;
	short int
		map[10001][100];	
	freopen( "treasure.in","r",stdin );
	freopen( "treasure.out","w",stdout );	
	cin>>n>>m;
	for( int i=1; i<=n; i++ ){
		for(  j=1; j<=m; j++ ){
			cin>>a;		
			cin>>map[i][j-1];	//ÃÜÂë 
		}
	}
	cin>>start;
	j=start;
	for( int i=1; i<=n; i++ ){
		k=map[i][j]%m;
		if( k==0 )
			miyao=miyao+map[i][j];
		else{
			if( j-map[i][j]%m>=0 ){
				miyao=map[i][j];
				j=j-map[i][j]%m;
			}
			else{
				miyao=map[i][j];
				j=m+(j-map[i][j]%m);
			}
		}
	}
	if( miyao>20123 )
		cout<<miyao%20123<<endl;
	else
		cout<<miyao<<endl;



	fclose(stdin);	
	fclose(stdout);
	return 0;
}
