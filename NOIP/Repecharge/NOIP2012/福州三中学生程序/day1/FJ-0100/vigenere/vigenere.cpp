#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

const int MAX=26+5,MAXN=10000+5;
string M,k;
int index=0;
char form[MAX][MAX],C[MAXN],note;

int main()
{
	freopen("vigenere.in","r",stdin);
	freopen("vigenere.out","w",stdout);
	form[0][1]='A'-1;
	for(int i=1;i<=26;i++)
	{
		form[i][1]=form[i-1][1]+1;
		for(int j=2;j<=26;j++)
		{
			if(form[i][j-1]+1>'Z')
				form[i][j]=form[i][j-1]-25;
			else
				form[i][j]=form[i][j-1]+1;
		}
	}
	cin>>k>>M;
	for(int i=0;i<k.size();i++)
		if(k[i]>='a')
			k[i]-=32;
	for(int i=0;i<M.size();i++)
	{
		index%=k.size();
		for(int j=1;j<=26;j++)
		{
			if(form[j][k[index]-64]==M[i])
			{
				cout<<form[j][1];
				break;	
			}
			if(form[j][k[index]-64]==M[i]-32)
			{
				note=form[j][1]+32;
				cout<<note;
				break;
			}
		}
		index++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}