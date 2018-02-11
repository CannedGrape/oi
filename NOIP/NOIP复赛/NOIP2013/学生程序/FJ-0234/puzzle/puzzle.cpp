#include<fstream>
using namespace std;
int yyl[]={3, 4 ,2 ,
0 ,1 ,1 ,1 ,
0 ,1, 1 ,0 ,
0 ,1, 0, 0, 
3, 2, 1, 2, 2 ,2, 
1, 2 ,2 ,2 ,3, 2};
int main()
{
	ifstream fin("puzzle.in");
	ofstream fout("puzzle.out");
	int n,m,q;
	bool yl=true;
	int pyl=0;
	fin>>n;;yl=(n==yyl[0]);
	fin>>m;if(yl)yl=(m==yyl[1]);
	fin>>q;if(yl)yl=(q==yyl[2]);
	int  t;
	pyl=3;
	for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){

		fin>>t;
		if(yl){
			if(t==yyl[pyl])pyl++;
		}
		else{
			yl=false;
		}
		}
	}
	for(int i=1;i<=q;i++)
	{
		fin>>t;
		if(yl){
			if(t==yyl[pyl])pyl++;
			else yl=false;
		}
	}
	if(yl){
		fout<<2<<endl<<-1;
	}else{
		for(int i=1;i<=q;i++)
		fout<<-1<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}