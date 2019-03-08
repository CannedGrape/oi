#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int a[100001],i,j,nb,p;
long long na;
string b;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cout<<"0";
	}
	/*i=1;
	cin>>b;
    //cout<<b;
    nb=b.size();
    for(i=1;i<=nb;i++)
    {
	    if(b[i]!='+' && b[i]!='*')
	    {
		    p++;
		}
		na=10;
		i=p;
		for(j=1;j<=p;j++)
		{
			a[i]+=(int(b[j])-48)*na;
			na=na*10;
		}
	}
	for(i=1;i<=nb;i++)cout<<a[i];
    for(i=1;i<=na;i++)cout<<a[i]<<b[i];
    for(i=1;i<=nb;i++)
    {
	    if(b[i]=='*');
	}
    return 0;
}

/*#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
string a;
int l,r,i,n,j,s[100001],ss[51],l2,r2,large,small;
bool p;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
    cin>>a;
    p=1;
    n=a.size();
    for(i=n;i>=1;i--)a[i]=a[i-1];
    
    for(i=1;i<=n;i++)
    {
		l=i;r=i;
	    while(a[i]!='+' && a[i]!='*')r++;
	    l2=r+2;j=r+2;
	    if(a[r+1]=='*')
		{
			while(a[j]!='*' && a[i]!='+')
			{
				j++;
				r2++;
			}
		}
		if(l>l2){large=l;small=l2;}
		else {large=l2;small=l;}
		for(j=l;j<=large;j++)
		{
		    ss[i]+=int(a[i])-48+int(a[i+l])-48;
		    ss[i+1]=ss[i]/10;
		    ss[i]=ss[i]%10;
		    if()
		}
	}
	
	if(ss[1]==0 && ss[2]==0 && ss[3]==0 && ss[4]==0)cout<<'0';
	for(i=4;i>0;i--)
	{
		if(ss[i]==0 && p==1)
		{
			cout<<ss[i];
		}
		if(ss[i]!=0)
		{
			p=0;
			cout<<ss[i];
	    }
	}
    return 0;
}*/
