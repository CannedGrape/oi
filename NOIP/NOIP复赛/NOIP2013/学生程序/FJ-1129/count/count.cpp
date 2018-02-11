#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
char x,a[10];
int ans=0;
void work(int k)
{
	k--;
	while (k>=0)
	{
		if(a[k]==x) ans++;
		k--;
    }
}
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	int i,l,j;
	char tmp;
	scanf("%s %c",&a,&x);
	l=strlen(a);
	for(i=0;i<l/2;i++) {tmp=a[i];a[i]=a[l-1-i];a[l-1-i]=tmp;}
	while (l>0)
	{
		work(l);
		if(int(a[0])>48) {a[0]=char(int(a[0]-1));}
		else 
		{
			i=0;
			while(i<l && a[i]=='0') i++;
			if(i!=l)
			{
				a[i]=char(int(a[i]-1));
			    for(j=0;j<i;j++) a[j]=char(57);
			    if(a[l-1]=='0') l--;
			}
			else l=0;
		}
		//for(i=0;i<l;i++) cout<<a[i];
		//cout<<endl;
	}
	if(x=='0') ans--;
	cout<<ans<<endl;
	return 0;
}