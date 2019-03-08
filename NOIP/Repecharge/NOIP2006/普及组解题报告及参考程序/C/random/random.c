#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  FILE *in=fopen("random.in","r");
  FILE *out=fopen("random.out","w");
  int n,t,a[1005],i,j,temp;
  fscanf(in,"%d",&n);
  temp=n;
  memset(a,0,sizeof(a));
  for(i=1;i<=n;i++)
    {
      fscanf(in,"%d",&t);
      a[t]++;
      if(a[t]!=1)
        temp--;
    }
  fprintf(out,"%d\n",temp);
  for(i=1;i<=1000;i++)
    if(a[i])
      fprintf(out,"%d ",i);
  fprintf(out,"\n");
  fclose(in);
  fclose(out);
  return 0;
}
