#include<iostream> 
#include<cstdio>
#include<cstdlib>
int n,p,sz[1000005],tz[1000005],m;
using namespace std;
int mod(int a){return a-a/p*p;}
int pd(int py)
{
	if(m<=0)return m;
	int mm,t=0;
    for(int i=1;i<=py;++i)
    {   if(sz[i]<=0)continue;
		mm=sz[i];t=max(t,mm);
		for(int j=i+1;j<=py;j++)
		{   mm+=sz[j];mod(mm);if(mm<=0)break;t=max(t,mm);}
    }
    return t;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    scanf("%d%d%d",&n,&p,&sz[1]);m=tz[1]=sz[1];
    for(int i=2;i<=n;++i){scanf("%d",&sz[i]);m=max(m,sz[i]);tz[i]=pd(i);}
    m=sz[1];sz[2]=sz[1]+tz[1];m=max(m,sz[2]);mod(m);
    for(int i=3;i<=n;i++){sz[i]=max(m,sz[i-1]+tz[i-1]);m=max(m,sz[i]);mod(m);}
	printf("%d\n",mod(m));
return 0;
}
