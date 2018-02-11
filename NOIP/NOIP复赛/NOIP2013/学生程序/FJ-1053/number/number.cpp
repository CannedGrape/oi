#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
using namespace std;
typedef long long longv;

inline longv app(longv* ar,longv* sr,int n)
{
	longv tmx=LLONG_MIN;
	for (int i=0;i<n;i++)
	{
		if (ar[i]+sr[i]>tmx)
			tmx=ar[i]+sr[i];
	}
	return tmx;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,p;
	cin>>n>>p;
	longv* ar=new longv[n],* sr=new longv[n];
	for (int i=0;i<n;i++)
	{
		cin>>ar[i];
	}
	for (int i=1;i<n;i++)
	{
		ar[i]=max(ar[i],ar[i]+ar[i-1]);
	}
	
	sr[0]=ar[0];
	for (int i=1;i<n;i++)
	{
		sr[i]=app(ar,sr,i);
	}
	cout<<*max_element(sr,sr+n)%p<<endl;
	delete ar;
	delete sr;
	fclose(stdin);
	fclose(stdout);	
}