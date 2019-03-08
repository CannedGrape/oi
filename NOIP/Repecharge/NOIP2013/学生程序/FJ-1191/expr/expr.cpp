#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;
char line[30000003],now[30000003];
int ans,ans1=0;
void scan()
{
	scanf("%s",line);
}
void sum()
{
	int jsq=0;
	bool pd=0;
	for (int i=1;i<=strlen(line);i++)
	{
		if (line[i]!='+' && line[i]!='*')
		{
			ans+=line[i];
		}
		if (line[i]=='+')
		{
			ans+=now[jsq];
			ans%=1000;
			pd=0;
		}
		else if (line[i]=='*' && pd==0)
			{
				pd=1;
			} 
			else if (pd==1)
				{
					now[jsq]*=10;
					now[jsq]+=line[i];
					now[jsq]%=1000;
				}
	}
}
void print()
{
	if (ans!=0)printf ("%d",ans/25);
	else printf ("%d",ans1/100);
}
int main()
{
	freopen ("expr.in","r",stdin);
	freopen ("expr.out","w",stdout);
	scan();
	sum();
	print();
	//system ("pause");
	return 0;
} 