#include<stdio.h>
#include<string>
#include<string.h>
#include<cstring>
using namespace std;
const int maxN=1010;
char k[maxN]={},M[maxN]={};
inline const char solve(const char &x,const char &y)
{
	register char s=x,t=y;
	if(t>='A' && t<='Z')
	    t-='A';
	else
	    t-='a';
	if(s>='A' && s<='Z')
	{
	    s-=t;
	    if(s<'A')
	        s+=26;
	}
	else
	{
		s-=t;
		if(s<'a')
		    s+=26;
	}
	return s;
}
int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    register int lk,lM,kpos;
    scanf("%s%s",&k,&M);
    lk=strlen(k);
    lM=strlen(M);
    for(register int i=0;i<=lM-1;++i)
    {
		kpos=i%lk;
		printf("%c",solve(M[i],k[kpos]));
	}
	printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
