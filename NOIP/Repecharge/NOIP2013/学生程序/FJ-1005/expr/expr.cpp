#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
using namespace std;
string s;
long long ans[100001]={},len,j=1;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	len=s.length()-1;
	for(long long i=0;i<=len;i++)
	{
		if(s[i]=='+')
		{
			j++;
			i++;
			ans[j]=0;
			for(;i<=len;i++)
			{
				if(s[i]=='+'||s[i]=='*')
				{
					i--;
					break;
				}
				ans[j]=(ans[j]*10+int(s[i])-48)%10000;	
			}
		}
		else
		{
			if(s[i]=='*')
			{
				j++;
				i++;
				ans[j]=0;
				for(;i<=len;i++)
				{
					if(s[i]=='+'||s[i]=='*')
					{
						i--;
						break;
					}
					ans[j]=(ans[j]*10+int(s[i])-48)%10000;	
				}
				ans[j]=(ans[j-1]*ans[j])%10000;
				ans[j-1]=0;
			}
			else
				ans[j]=(ans[j]*10+int(s[i])-48)%10000;
		}
	}

	for(long long i=2;i<=j;i++)
	{
		ans[i]+=ans[i-1];
		ans[i]%=10000;	
	}
	cout<<ans[j];
	//system("pause");
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
