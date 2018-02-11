#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	freopen("truck.in","w",stdout);
	int n,m;
	srand(time(0));
	n=1000;m=3000;
	cout<<n<<" "<<m<<endl;
	int tp=n/2;
	for(int i=2;i<=tp;i++)
	{
		cout<<i<<" "<<rand()%(i-1)+1<<" "<<rand()%100001<<endl;
	}
	for(int i=1;i<=m/2-(tp-1);i++)
	{
		int x=rand()%tp+1,y;
		while((y=rand()%tp+1)==x);
		cout<<x<<" "<<y<<" "<<rand()%100001<<endl;
	}
	
	for(int i=2;i<=tp;i++)
	{
		cout<<i+tp<<" "<<rand()%(i-1)+1+tp<<" "<<rand()%100001<<endl;
	}
	for(int i=1;i<=m/2-(tp-1);i++)
	{
		int x=rand()%tp+1+tp,y;
		while((y=rand()%tp+1+tp)==x);
		cout<<x<<" "<<y<<" "<<rand()%100001<<endl;
	}
	int q=3000;cout<<q<<endl;
	for(int i=1;i<=q;i++)
	{
		int x=rand()%n+1,y;
		while((y=rand()%n+1)==x);
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
