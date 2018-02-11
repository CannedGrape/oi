#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	ifstream fin("count.in");
	ofstream fout("count.out");
	int n,x;
    fin>>n>>x;
	int sum=0;
	for(int i=n;i>=1;i--)
	{
		if(i==x)
		++sum;
	int t=i;
	while((t/10)!=0)
	{
		if((t%10)==x)
		++sum;	
		t=t/10;
		if(t==x)
		++sum;
	
	}
	
	
	
	}
	fout<<sum<<endl;
	return 0;
}
