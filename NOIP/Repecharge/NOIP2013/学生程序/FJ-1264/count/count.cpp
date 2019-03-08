#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int x,r=0,h,o,k,g,c,q,j=0,n;
	cin>>n;
	cin>>x;
	for(int i=1;i<=n;i++)
	{
		
		if(i>=1000)
		{
			
			k=i/1000;
			j=i%1000/100;
			c=i%10;
			g=i%100-c;
			if(j==x)
		    r++;
		    if(c==x)
		    r++;
		    if(g==x)
		    r++;
		    if(k==x)
		    r++;
		    break;
		}
		if(i>=100)
		{
			j=i/100;
			c=i%10;
			g=i%100-c;
			if(j==x)
		    r++;
		    if(c==x)
		    r++;
		    if(g==x)
		    r++;
		    break;
		}
		if(i>=10)
	    {
		  j=i/10;
	      c=i-j*10;
		  if(j==x)
		  r++;
		  if(c==x)
		  r++;
		}
		if(i<10)
		{
			if(i==x)
             r++;
		}			
	
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
}
