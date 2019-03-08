#include<iostream> 
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,z[100001],ans,cz,s,jc,tl,jc1;
int main ()
{
	freopen ("level.in","r",stdin);
	freopen ("level.out","w",stdout);
	scanf ("%d%d",&n,&m);
	for (int b=1;b<=m;++b)
	{
		scanf ("%d",&s);
		for (int c=1;c<=s;++c)
		{
			scanf ("%d",&cz);
			if (!z[cz]){z[cz]=1;jc=1;++tl;}
		}
		ans+=jc;
		jc=0;
	}
	if (tl!=n)++ans;
	printf ("%d\n",ans);
	return 0;
}
