#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int dis[4001][4001]={0};

inline int minmax(int a,int b,int c){
	b=(b<c?b:c);
	return (a>b?a:b);
}
int main()
{
	freopen("truck.in","r",stdin);
	freopen("truck.out","w",stdout);
	memset(dis,-1,4001*4001*4);
	int n,m;
	int x,y,z;
	scanf("%d",&n);
	scanf("%d",&m); 
	
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		scanf("%d",&y);
		scanf("%d",&(dis[x][y]) );
	}
	
	//floyd
	int t;
	int max=(2<<30);
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dis[i][k]!=-1 && dis[k][j]!=-1){
					//dis[i][j]=max(dis[i][j],min( dis[i][k],dis[k][j] ) );
					dis[i][j]=minmax(dis[i][j],dis[i][k],dis[k][j]);
				}
				
			}
		}
	}
	
	//solve
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&x);
		scanf("%d",&y);
		printf("%d\n",dis[x][y]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
