#include <fstream>
using namespace std;
unsigned int n,x,tmp,len=0,tmpn,sum=0,k=1;
int main()
{
	ifstream fin("count.in");ofstream fout("count.out");
	fin>>n>>x;
	tmp=1;len=0;
	while(n/tmp!=0)
	{
		tmp*=10;
	}
	k=tmp;
	for (int i=1;i<=n;i+=1)
	{
		tmpn=i;k=tmp;
		while (k!=1)
		{
			k/=10;
			if (tmpn/k==x)
				sum++;
			tmpn%=k;
		}
	}
	fout<<sum;
	fin.close();
	fout.close();
	return 0;
}