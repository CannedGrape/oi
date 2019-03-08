#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	int n,m,i,j,s[100],a[100],x;
	cin>>n>>m;
	for(i=0;i<m;i++)
	cin>>s[i];
	    for(j=0;j<s[i];j++)
	    cin>>a[j];
    cout<<(a[0]+s[0]+x)%5+1<<endl;
	return 0; 
} 
