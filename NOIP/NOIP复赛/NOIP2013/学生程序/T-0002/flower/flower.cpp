#include<iostream>
#include<stdio.h>
using namespace std;
int s[100005],f[100005],l[3];
int main()
{
	int a,i,j;
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	scanf("%d",&a);
	for(i=1;i<=a;i++)
		scanf("%d",&s[i]);
	if(a<=2)
	printf("%d",a);
	else
	{	
		for(j=2;j<=a-1;j++)
		{
		
			if(s[j]<s[j-1]&&s[j]<s[j+1]||s[j]>s[j-1]&&s[j]>s[j+1])
			{
				l[1]=s[j];
				l[2]=s[j+1];
				for(i=1;i<=a;i++)
				{	
					f[1]=1;
					if(l[2]>l[1]&&s[i]<l[2]||l[2]<l[1]&&s[i]>l[2])
					{
						f[i]=f[i-1]+1;
						l[1]=l[2];
						l[2]=s[i];
					}
					else
						f[i]=f[i-1];
				}
			}
		}
		printf("%d",f[a]);
	}
	return 0;
}
