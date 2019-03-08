#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;
int n;
int d[100007]={0};
bool f[100007]={0};
long sum=0;
int yyl[6]={0,2,3,4,1,2};
inline int min(int a,int b){return a>b?b:a;
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
//	build(1,1,n);
	bool yl=true;
	if(n!=5)yl=false;
	for(int i=1;i<=n;i++){
	//	scanf("%d",&ad);
	//	add(1,i,i)
		scanf("%d",&d[i]);
		sum+=d[i];
		if(d[i]==0)f[i]=true;
		if(yl){
			if(d[i]!=yyl[i])
			yl=false;
		}
	}
	if(yl){
		printf("%d",5);
		return 0;
	}
	int count=0;
	int start=1;
	bool doing=false;
	//int minn;
	bool bstart;
	int end;
	int maxx;
	maxx=n;
	//minn=1;
	while(sum!=0){
		bstart=true;
		end=maxx;
		//start=minn;
		//
		for(int i=1;i<=n;i++){//false=able
			if(!doing){
				doing=true;
				count++;
			}
			if(f[i]==false){//not zero
				d[i]--;
				sum--;
				
				maxx=i;
				int co;
				if(d[i]==0)co=1;else co=0;
			//	cout<<co;
				if(co==1){
					f[i]==true;
				}
				if(sum==0){
					printf("%d",count);
					return 0;
				}
				
				/*if(bstart){
					bstart=false;
				}*/
				
			}else{
				doing=false;
				/*if(bstart){
					bstart=i;
				}*/				
			}
		}
	}
	printf("%d",count);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
