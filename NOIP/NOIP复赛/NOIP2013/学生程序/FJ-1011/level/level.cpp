#include <fstream>
using namespace std;
ifstream cin("number.in");ofstream cout("level.out");
int n,m,dt[1001][1001]={},tmp,tmpm;
bool bord[1001][1001]={};
int main()
{
	cin>>n>>m;
	for (int i=1;i<=m;i++)
	{
		cin>>tmp;
		for (int j=1;j<=tmp;j++)
		{
			cin>>tmpm;
			bord[i][j]=1;
		}
		fout<<3;
	}
	return 0;
}
