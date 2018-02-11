#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
char a[105],b[1010],c[1010];
char JHS_make(int j,int i)
{
	if('a'<=b[i]&&b[i]<='z')
	  {if('a'<=a[j]&&a[j]<='z')
		  if(b[i]-a[j]>=0) return b[i]-a[j]+'a';
		  else return b[i]-a[j]+'z'+1;
		else
		   if(b[i]-a[j]+'A'-'a'>=0) return b[i]-a[j]+'a'+'A'-'a';
		   else return b[i]-a[j]+'z'+1+'A'-'a';
	  }
	else 
	  {if('A'<=a[j]&&a[j]<='Z')
		  if(b[i]-a[j]>=0) return b[i]-a[j]+'A';
		  else return b[i]-a[j]+'Z'+1;
		else 
		  if(b[i]-a[j]+'a'-'A'>=0) return b[i]-a[j]+'A'+'a'-'A';
		  else return b[i]-a[j]+'Z'+1+'a'-'A';
	  }
}
int main()
{
  freopen("vigenere.in","r",stdin);
  freopen("vigenere.out","w",stdout);
  scanf("%s%s",a,b);
  int la,lb,j;
  j=0;
  la=strlen(a);
  lb=strlen(b);
  for(int i=0;i<lb;i++)
    {if(j==la)j=0;
	  c[i]=JHS_make(j,i);  
	  printf("%c",c[i]);
	  j++;
	}
  printf("\n");
  fclose(stdin);
  fclose(stdout);	
  return 0;	
}