#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
using namespace std;
int i,j,k,n,s;
int main()
{freopen("block.in","r",stdin);
 freopen("block.out","w",stdout);
 scanf("%d",&n);
 for(i=1;i<=n;i++)
    {scanf("%d",&j);
     if(j-k>0)s+=j-k;
     k=j;
    }
 printf("%d\n",s);
 fclose(stdin);
 fclose(stdout);
// system("pause");
 return 0;
}
