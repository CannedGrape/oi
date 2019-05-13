#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxn 101

int n;
int a[maxn],b[2*maxn];
long sum[maxn][maxn];
long globalmax = 0;

void Initialize()
{
    int i;
    FILE *fin = fopen("energy.in","r"); 
    fscanf(fin,"%d",&n);
    for (i=1;i<=n;i++)  
        fscanf(fin,"%d",&a[i]);
    fclose(fin);
}

void predoing(int s)
{
    int i,j;
    for (i=0;i<2*n;i++) 
        b[i+1]=a[(i+s)%n+1];
    memset((void*)sum,0,sizeof(sum));
}

long mdfs(int l,int r)
{
    int i,j; long t,max=0;
    if (l==r) return 0;
    if (sum[l][r]>0) return sum[l][r];
    for (i=l;i<r;i++) {
        t = mdfs(l,i)+mdfs(i+1,r)+b[l]*b[i+1]*b[r+1];
        if (t>max) max=t;
    }
    sum[l][r]=max;
    return sum[l][r];
}

void Compute()
{
    int i; long t;
    for (i=0;i<n;i++)
    {
        predoing(i);
        t = mdfs(1,n);
        if (t>globalmax) globalmax=t;
    }
}


void Output()
{
    FILE *fout = fopen("energy.out","w");
    fprintf(fout,"%ld",globalmax);
    fclose(fout);
}

int main()
{
    Initialize();
    Compute();
    Output();
    return 0;             
}
