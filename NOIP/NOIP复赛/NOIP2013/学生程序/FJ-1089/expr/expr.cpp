#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
char s[100003];
long long sz[10003]={0};
bool joc[10003][10003]={false};/* +:false *:true */
int i=0,r=0,j,xiang=1,k,ans=0;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin.getline(s,100003);
	for(j=0;j<strlen(s);j++)	
	{	
		if(s[j]=='+')
		{
			r=j-1;
			xiang++;
			for(k=i;k<=r;k++)
			sz[xiang-1]+=(s[k]-'0')*pow(10,(r-k)*1.0);
			i=j+1;
			r=j+1;
		}
		else 
		if(s[j]=='*')
		{
			r=j-1;
			xiang++;
			joc[xiang-1][xiang]=true;
			for(k=i;k<=r;k++)
			sz[xiang-1]+=(s[k]-'0')*pow(10,(r-k)*1.0);
			i=j+1;
			r=j+1;
		}
	}
	for(k=i;k<strlen(s);k++)sz[xiang]+=(s[k]-'0')*pow(10,(strlen(s)-k)*1.0);
		sz[xiang]/=10;
	for(k=1;k<=xiang;k++)
	sz[k]%=10000;
	for(k=1;k<=xiang;k++)
	{
		if(joc[k][k+1]==true)
		{sz[k]*=sz[k+1];
			sz[k]%=10000;
			sz[k+1]=0;
		}
	}
	for(k=1;k<=xiang;k++)
	{
		ans+=sz[k];
		ans%=10000;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	//system("pause");
	return 0;
}