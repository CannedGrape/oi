#include<iostream>
using namespace std;
int main(){
	freopen("treasure.in","r",stdin);
	freopen("treasure.out","w",stdout);
	int N,	/*N层楼*/
		M,	/*M个房间*/
		i,	/*第i层*/
		j;	/*第j个房间*/
	int y,/*目前所在层数所走过的共有y个有楼梯的房间*/
		Y,
		da;	/*密码*/
	cin>>N>>M;
	int fang[N][M][2];
	for(i=0;i<=N-1;i++){
		for(j=0;j<=M-1;j++){
			cin>>fang[i][j][0]>>fang[i][j][1];
		}
	}
	j=0;
	da=0;
	for(i=0;i<=N-1;i++){
		da=da+fang[i][j][1];
		Y=fang[i][j][1];
		y=0;
		while(y<Y){
			if(j>M-1)j=0;
			if(fang[i][j][0]==1)y++;
			j++;
		}
		j--;
	}
	int mi;
	cin>>mi;
	if(mi==1)da++;
	cout<<da;
	return 0;
}
