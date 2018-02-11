#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<time.h>

ofstream fou("hookey.in");
long n,w,i,j,k,a[1000100];
int main(){
	cout<<"n,w=";cin>>n>>w;
	fou<<n<<' '<<n-1<<endl;
	for (i=1;i<=n;i++) a[i]=i;
	srand(time(0));
	for (i=1;i<=n;i++){
		j=rand()%(n-i+1)+i;
		k=a[i];a[i]=a[j];a[j]=k;
		if (i>1){
			j=rand()%(i-1)+1;
			fou<<a[j]<<' '<<a[i];
			fou<<' '<<rand()%9999+1;
			fou<<rand()%9999+1<<endl;
		};
	}
	return 0;
}