#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
char a[10001],b[10001],c[10001],d[10001],k[10001];
int n,m;
int main()
{
    freopen("vigenere.in","r",stdin);
    freopen("vigenere.out","w",stdout);
    
    int i,j;
    
    scanf("%s%s",&k[0],&c[0]);
    n=strlen(k)-1;
    m=strlen(c)-1;
    for(i=0;i<=n;i++)
      {if(k[i]>=97)
         k[i]-=32;
       a[i]=k[i];
       b[i]=k[i]+32;
       }
    
    j=-1;
    for(i=0;i<=m;i++)
      {j++;
       if(j>n)
         j=0;
       if(c[i]<97)
         d[i]=(c[i]-a[j]+26)%26+65;
       else
         d[i]=(c[i]-b[j]+26)%26+97;
       }
    
    printf("%s\n",d);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}
