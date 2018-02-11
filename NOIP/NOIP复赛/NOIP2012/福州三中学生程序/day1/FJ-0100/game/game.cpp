#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
using namespace std;

const int MAX=1000+5;
long long n,result[MAX],temp,king,form[MAX][MAX],ma,fi=999999999;
bool note[MAX];

void cal()
{
	for(int i=1;i<=n;i++)
	{
		temp=1;
		for(int j=0;j<i;j++)
		{
			temp*=form[result[j]][1];
		}
		temp/=form[i][2];
		ma=max(ma,temp);
	}
	fi=min(fi,ma);
}

void dfs(int step)
{
	for(int i=1;i<=n;i++)
	{
		if(note[i]==0)
		{
			note[i]=1;
			result[step]=i;
			if(step==n)
				cal();
			else
				dfs(step+1);
			note[i]=0;
		}
	}
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n;
	cin>>king>>temp;
	for(int i=1;i<=n;i++)
		cin>>form[i][1]>>form[i][2];
	form[0][1]=king;
	dfs(1);
	cout<<fi<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
