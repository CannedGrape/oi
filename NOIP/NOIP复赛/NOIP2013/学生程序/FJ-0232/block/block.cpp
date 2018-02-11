#include<cmath>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#define F(i,j,k) for(i=j;i<=k;i++)
using namespace std;
struct by
{
	int s,z;
} a[100001];
int n,i,o,sum=0,maax=0;
int wp(int t,int w,int bu)
{
	int i,j,k=0,l,minn=2147483647;
	if(sum==0)return 0;
	if(t==w)
	{
	    //cout<<t<<" "<<a[t].s<<" "<<maax<<endl;
	    maax=maax+a[t].s;
	    a[t].s=0;
		return 0;
    
	}
	if(t>w)return 0;
	minn=2147483647;
	F(i,t,w)if(minn>a[i].s)minn=a[i].s;maax=maax+minn;
	F(i,t,w)
	{
		a[i].s=a[i].s-minn;
		sum=sum-minn;
	}
	//cout<<t<<" "<<w<<" "<<sum<<" "<<minn<<" "<<maax<<endl;
	//F(i,t,w)cout<<a[i].s<<" ";
	//cout<<endl;
	i=t;
	while(a[i].s==0||a[i].z==0)i++;
	{   
		j=i+1;
		while(a[j].s!=0)j++;
		if(j<=n)
		l=j+1;
		while(a[l].s!=0)l++;
	    if(j>n)j--;
	    if(l>n)l--;
		//cout<<i<<" "<<j<<" "<<l<<endl;
		a[i].z=1;	
		if(i!=j&&j!=l)
		{
		  k=1;	
		  wp(i,j-1,bu);
		  wp(j+1,l,bu);
		}
		else
		{if(j!=l)
		{
		  k=1;
		  wp(i,j,bu);
		  wp(j+1,l,bu);
	    } 
	    else{
		if(i!=j)
		{
		  k=1;
		  wp(i,j-1,bu);
		  wp(j,l,bu);
		}
		else if(i==j&&j==l)wp(i,j,bu);}
	   }
	}
}
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	cin>>n;
	F(i,0,100000)
	{
	   a[i].s=0;
       a[i].z=0;
	}
	F(i,1,n)
	{
		scanf("%d",&a[i].s);
        sum+=a[i].s;
        a[i].z=1;
	}
	//cout<<sum<<endl;
	wp(1,n,0);
	cout<<maax;
	return 0;
}
