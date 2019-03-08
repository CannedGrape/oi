#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
int t,w,f,sum,t1[100003],t2[100002];
char c;
int main ()
{
	freopen ("expr.in","r",stdin);
	freopen ("expr.out","w",stdout);
	while (scanf ("%c",&c)==1)
	{
		if (isdigit (c))
		{
			t=c-48;
			if (w==0) w=t;
			else w*=10,w+=t;
		}
		else
		{
			f++,t1[f]=w,w=0;
			if (c=='*') t2[f]=-1;
			else t2[f]=-2;
		}
	}
	for (int i=1;i<=f;i++)
	{
		if (t1[i]<0) continue;
		w=i;
		while (t2[i]==-1) t1[i]*=t1[w+1],t2[i]=t2[w+1],t1[w+1]=-1,w++;
	}
	for (int i=1;i<=f;i++)
	{
		if (t1[i]>0) sum+=t1[i];
		sum%=10000;
	}
	printf ("%d\n",sum);
	return 0;
}
