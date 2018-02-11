#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100010
using namespace std;
int n,h[maxn],p=0,min2=maxn;
int x,y,ret=0;
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);int m=0;
	for (int i=1;i<=n;i++) 
	{scanf("%d",&h[i]);m=m+h[i];}
	int j=1,i=1;
	while (m>0){
		x=1;y=1;int min1;
	  while (j<=n){min2=maxn;
	  while (h[j]>0 && j<=n) {
	  if (h[j]<min2 && h[j]>0) min2=h[j];
	  j++;}
	  if (h[j]==0) j--;
	  if ((j-i+1)>(y-x+1)) {
		x=i;y=j;min1=min2;
	  }
	   else if (i==j && y==x && h[i]>0) {x=i;y=j;min1=min2;
	   }
	  j++;
	  while (h[j]==0 && j<=n) j++;
	  i=j;
	}
	  for (int i2=x;i2<=y;i2++) h[i2]=h[i2]-min1;
	  ret=ret+min1;
	  m=m-(y-x+1)*min1;
	  i=j=1;
	}
	cout<<ret<<endl;
	fclose(stdin);
   fclose(stdout);
	return 0;
}
