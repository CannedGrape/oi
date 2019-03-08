#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iomanip>
using namespace std;
int main()
{
	int n,k,p=0,o,c=1,q;
	freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
	cin>>n>>k;
	if(k>0)
	{
		
	while(n>0)
		{
			q=n;
			while(q>0)
			{	
				c=n;
			    o=q%10;
				if(o==k)
				p++;
				q=q/10;			
			}
			n--;
		}	}
		if(k==0)
		{
	while(n>0)
		{
			c=n;
			o=c%10;
			q=c;
			while(q>0)
			{
				if(q%10==k)
				p++;
				q=q/10;
			}
			n--;
		}	
		}
		cout<<p;
	fclose(stdin);
	fclose(stdout);
}
