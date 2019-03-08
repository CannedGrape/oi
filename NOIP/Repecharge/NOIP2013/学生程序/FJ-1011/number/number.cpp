#include <fstream>
using namespace std;
int a[1000001],b[1000001],c[1000001],n,mo,maxx=0;
ifstream fin("number.in");ofstream fout("number.out");
int main()
{
	fin>>n>>mo;
	for (int i=1;i<=n;i++)
		fin>>a[i];
	b[1]=a[1];
	for (int i=2;i<=n;i++)
	{
		if (a[i]>0)
			b[i]=a[i]+b[i-1];
		else
			b[i]=a[i-1];
	}
	c[1]=b[1];maxx=c[1];
	for (int i=2;i<=n;i++)
	{
		if (c[i-1]+b[i-1]>maxx)
		{
			c[i]=c[i-1]+b[i-1];
			maxx=c[i];
		}
		else c[i]=maxx;
	}
	fout<<maxx%mo;
	fin.close();
	fout.close();
	return 0;
}