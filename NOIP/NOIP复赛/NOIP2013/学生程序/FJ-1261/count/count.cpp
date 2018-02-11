#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int n,x,s=0,a;
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	cin>>n>>x;
	for(a=1;a<=n;a++)
    {
        if(a==x||a%10==x&&a/10!=x||a/10==x&&a%10!=x)
		s++;
		if(a%10==x&&a/10==x)
        s+=2;
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
}
