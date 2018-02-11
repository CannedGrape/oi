//IOI2000 Sample Program
//Day 1
//Task: Palin
//Programmer: Shao Zheng
//Email: shaoz@sina.com
//Date:2000.09.23
//Algorithm: Dynamic Programming, O(N^2)

#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <mem.h>

#define fin "PALIN.IN"
#define fon "PALIN.OUT"
#define maxs 5000

typedef int Tg[maxs+1];
typedef char Ts[maxs+1];

typedef Tg *Pg;

FILE *fi,*fo;
Pg g[maxs+1];
int i;
int len;
Ts a,reva;

void Init()
{
 int i,j;
 g[0]=(Pg)malloc(sizeof(Tg));
 g[1]=(Pg)malloc(sizeof(Tg));

 for (i=2;i<=maxs;i++) g[i]=g[i%2];

 fi=fopen(fin,"r");
 fo=fopen(fon,"wt");
 fscanf(fi,"%i\n",&len);
 for (i=1;i<=len;i++) fscanf(fi,"%c",&(a[i]));
 fclose(fi);

 for (i=len;i>=1;i--) reva[len+1-i]=a[i];
}

#define max(a,b) (a>b?a:b)

int MaxPub(Ts a)
{
 int i,j,k,now,answer;
 memset(g[0],0,sizeof(*g[0]));
 answer=0;
 k=len;
 for (i=1;i<=k-1;i++)
  {
    (*g[i])[0]=0;
    for (j=1;j<=k-i;j++)
      {
	now=max((*g[i-1])[j],(*g[i])[j-1]);
	if (a[i]==reva[j])
	  now=max(now,(*g[i-1])[j-1]+1);
	(*g[i])[j]=now;
      }
    answer=max((*g[i])[k-i]*2,answer);
    answer=max((*g[i])[k-1-i]*2+1,answer);
  }
  return answer;
}

int main()
{
  Init();
  fprintf(fo,"%d\n",len-MaxPub(a));
  fclose(fo);
  return 0;
}
