#include<stdio.h>
#include<stdlib.h>
int main()
{
  FILE *in=fopen("sequence.in","r") ;
  FILE *out=fopen("sequence.out","w");
  int k,n,i,j,l,t;
  long a[2000];
  long cf(int x,int y);
  fscanf(in,"%ld %ld",&k,&n);
  for(i=0;i<=1050;i++)
    a[i]=0;
  for(i=0;i<=10;i++)
    {
      t=cf(2,i);
      a[t]=cf(k,i);
    }
  
  for(i=1,j=1;i<=1000;i++)
    if(a[i]!=0)
      {
        l=a[i];
        j=1;
      }
    else if(a[i]==0)
      a[i]=a[j++]+l;
  fprintf(out,"%ld\n",a[n]);
  fclose(in);
  fclose(out);
  return 0; 
}

long cf(int x,int y)
{
  int i;
  long q=1;
  if(y==0)
    return 1;
  for(i=1,q=1;i<=y;i++)
    q=q*x;
  return q;
}
