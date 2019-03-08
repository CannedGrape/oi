#include<fstream>
using namespace std;
long n,m,k,x;
int main()
{
	ifstream fin("circle.in");
	ofstream fout("circle.out");
	fin>>n>>m>>k>>x;
		bool jishu=((k%2)==1);
	if(k<100000000){
		for(int i=1;i<=k;i++){
			x+=10*m;
			x%=n;
		}
		fout<<x;
	}
/*	else if(k<=10000000){

		if(!jishu){
			for(int i=1;i<=k-1;i+=2){
				x+=100*m;
				x=x%n;
			}
		}else{//jishu
			for(int i=1;i<=k-1;i+=2){//k-1 is oushu
				x+=100*m;
				x=x%n;
			}
			x+=10*m;
			x=x%n;
		}
		fout<<x;
	}*/
	else{
		int i;
		long long xx=x;
		for(i=1;i<=k/100;i+=100){
			for(int q=1;q<=10;q++){
				xx+=10000000000*m;
				xx%=n;
			}
		}
		if(!jishu){
			for(;i<=k-1;i+=2){
				xx+=100*m;
				xx=x%n;
			}
		}
		else{//jishu
			for(;i<=k-1;i+=2){//k-1 is oushu
				xx+=100*m;
				xx=xx%n;
			}
			xx+=10*m;
			xx=xx%n;
		}
		fout<<xx;
	}
	
	fin.close();
	fout.close();
	return 0;
}
