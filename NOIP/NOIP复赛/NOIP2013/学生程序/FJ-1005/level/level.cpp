#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
int n,m,s[1001]={},p[1001]={},i,j,k,l[1001]={},maxl=0;
int main()
{
	freopen("level.in","r",stdin);
	freopen("level.out","w",stdout);
	
	cin>>n>>m;
	for(i=1;i<=n;i++)
		l[n]=1;
	for(i=1;i<=m;i++)
	{
		cin>>s[i];
		for(j=1;j<=s[i];j++)
			cin>>p[j];
		for(j=2;j<=s[i];j++)
		{
			if(p[j]-p[j-1]>1)
				for(k=p[j-1]+1;k<p[j];k++)
					if(l[k]>maxl)
						maxl=l[k];
				for(j=1;j<=s[i];j++)
				{
					if(l[p[j]]<maxl+1)
						l[p[j]]=maxl+1;
				}
			maxl=1;
		}
	}
	for(i=2;i<=n;i++)
		if(l[i]<l[i-1])
			l[i]=l[i-1];
	cout<<l[n];
	//system("pause");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
