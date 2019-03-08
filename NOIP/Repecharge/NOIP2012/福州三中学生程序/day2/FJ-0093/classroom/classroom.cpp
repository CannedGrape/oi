#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,num,be,en,a[10001];
int main()
{
  freopen("classroom.in","r",stdin)	;
  freopen("classroom.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
  for(int i=1;i<=m;i++)
    {scanf("%d%d%d",&num,&be,&en);
	  for(int j=be;j<=en;j++)
	    {a[j]-=num;
		 if(a[j]<0){printf("-1\n");printf("%d\n",i);fclose(stdin);fclose(stdout);return 0;}}
	}
   printf("0\n");
	fclose(stdin);
	fclose(stdout);
   return 0;
}
