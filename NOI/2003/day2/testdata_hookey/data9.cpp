#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<time.h>

ofstream fou("hookey.in");
long i,n,w;
int main(){
	cout<<"n,w=";cin>>n>>w;
	fou<<n<<' '<<n-1<<endl;
	srand(time(0));
	for (i=1;i<n;i++)
		fou<<i<<' '<<i+1<<' '<<rand()%w+1<<endl;
	return 0;
};