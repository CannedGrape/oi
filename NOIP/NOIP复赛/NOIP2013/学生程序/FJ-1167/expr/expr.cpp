#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
string s;
int a[11][100001],f[100001]={0};
int n=0,ans;
bool flag=false;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	int ii;
	for(int i=0;i<s.size();i++)
	{
		if(flag==false){n++;flag=true;}
		if(s[i]>=48 && s[i]<=57)
		{
			a[f[n]][n]=s[i]-48;cout<<s[i]<<endl;system("pause");
			f[n]++;
		}
		else
		{
			n++;flag=false;
			if(s[i]=='+')a[0][n]='+';
			if(s[i]=='*') a[0][n]='*';
			f[n]=1;
		}
	}
	for(int i=1;i<=n;i+=2)
	{
		if(a[0][i+1]=='+')
		{
			for(int j=1,k=f[i];j<=f[i],k>=1;j++,k--)
			{
				if(k==1)ans+=a[j-1][i];
				else ans+=a[j-1][i]*(k-1)*10;
				cout<<k<<endl<<a[j-1][i];system("pause");
		    }
		    cout<<ans<<endl;system("pause");
		}
		if(a[0][i+1]=='*')
		{
			int k1=0,k2=0;
			for(int j=1,k=f[i];j<=f[i],k>=1;j++,k--)
			{
				if((k-1)*10==0)k1+=a[j-1][i];
				else k1+=a[j-1][i]*(k-1)*10;
		    }
		    for(int j=1,k=f[i+2];j<=f[i+2],k>=1;j++,k--)
			{
				if((k-1)*10==0)k2+=a[j-1][i+2];
				else k2+=a[j-1][i+2]*(k-1)*10;
		    }
		    ans+=k1*k2;
		    cout<<ans<<endl;system("pause");
		}
	}
	cout<<ans%10000/1000*1000+ans%1000/100*100+ans%100/10*10+ans%10+1<<endl;
	return 0;
}
