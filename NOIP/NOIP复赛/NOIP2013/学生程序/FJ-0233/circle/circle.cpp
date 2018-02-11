#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<algorithm>
using namespace std;
bool f[1000000];
int n,m,k,x;
long long ans,sum,t;
long long pow(long long a,long long b) 
{
	long long r=1,base=a;
    while( b != 0 )
  {
     if  (b & 1) r=r*base%t;
     base*=base%t;
     b>>=1;
  }
  return r;
}

int main()
{
	freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
	cin>>n>>m>>k>>x;
	sum=x;
	memset(f,(false),sizeof(f));
	f[x]=true;
	if (k<=50)
	{
		//cout<<k1<<"......"<<endl;
	    while (true)
	    {
			sum=(sum+m)%n;
		    //cout<<sum<<"fw23r"<<endl;
            if (f[sum]==false)
		    {
				f[sum]=true;
			    t++;
			    //cout<<t<<endl;
		    }
            else 
            {
				t++;
			    //cout<<t<<endl;
			    long long p=0;
			    p=pow(10,k);
			    //cout<<p<<endl;
			    ans=(x+p*m)%n;
			    cout<<ans<<endl;
			    exit(0);
		    }
	    }
    }
	else 
	  while (true)
	    {
			sum=(sum+m)%n;
		    //cout<<sum<<"fw23r"<<endl;
            if (f[sum]==false)
		    {
				f[sum]=true;
			    t++;
			    //cout<<t<<endl;
		    }
            else 
            {
				t++;
			    //cout<<t<<endl;
			    int p=0;
			    p=100000000000%t;
			    //cout<<p<<endl;
			    ans=(x+p*m)%n;
			    cout<<ans<<endl;
			    exit(0);
		    }
		}
	return 0;
}
