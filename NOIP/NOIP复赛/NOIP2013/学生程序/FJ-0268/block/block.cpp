#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int h[110000],n,m,ans;
int main(){
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
	  scanf("%d",&h[i]);
	  m=max(m,h[i]);
	}
	if (n*m<=5000*10000){
		//cout<<m<<endl;
		for (int i=1;i<=m;i++){
			int k=0;
		 for (int j=1;j<=n+1;j++)
		  if (h[j]>=i) k++;
		   else if (k>0){
				//cout<<i<<"   "<<j<<endl;
				 ans++;k=0;
		   }
		//if (k>0) ans++;
		 }
		cout<<ans;
	}else {
		for (int i=1;i<=n;i++){
			int k=999999;
			if (i-1!=0 && h[i-1]<=h[i]) k=min(k,h[i]-h[i-1]);
			if (h[i+1]<h[i] && i+1!=n) k=min(k,h[i]-h[i+1]);
			//cout<<k<<endl;
			if (k!=999999) ans+=k;
			  else ans++;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
}
