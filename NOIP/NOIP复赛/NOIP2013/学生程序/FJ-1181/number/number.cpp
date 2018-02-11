#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,k,l,x,n,p,y,a[100000],t[100000],f[100000];


int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>p;
	x=0;
	y=0;
	memset(t,0,sizeof(t));
	memset(f,0,sizeof(f));
    
	for (i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for (i=1;i<=n;i++){
		for (j=1;j<=i;j++){
			for (k=1;k<=i;k++){
				for (l=j;l<=k;l++){
				  x=x+a[l];
				  if (x>t[i]) t[i]=x;
				}
				x=0;
			}
		}
	    if (i=1) f[i]=t[i];
		else{
		  for (j=1;j<i;j++){
			y=f[j]+t[j];
		    if (y>f[i]) f[i]=y;
		  }	
		  y=0;
		}		
	}

	for (i=1;i<=n;i++){
		if (f[i]>f[0]) f[0]=f[i];
	}
	cout<<f[0]%p;
	return 0;
}
