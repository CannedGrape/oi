#include<cstdio>
long long a[100001][2],b[100001][2],aa[100001][2],bb[100001][2];
void swap(long long &a,long long &b)
{
     long long c=a;
     a=b;
     b=c;
}
void qsortt(int l,int r)
{
     int i=l,j=r,mid=aa[(l+r)/2][0];
     while(i<=j)
     {
         while(aa[i][0]<mid) i++;
         while(aa[j][0]>mid) j--;
         if(i<=j)
         {
             swap(aa[i][0],aa[j][0]);
             swap(aa[i][1],aa[j][1]);
             a[aa[i][1]][1]=j;
             a[aa[j][1]][1]=i;
             i++;
             j--;
         }
     }
     if(i<r) qsortt(i,r);
     if(l<j) qsortt(l,j);
}
void qsorttt(int l,int r)
{
     int i=l,j=r,mid=bb[(l+r)/2][0];
     while(i<=j)
     {
         while(bb[i][0]<mid) i++;
         while(bb[j][0]>mid) j--;
         if(i<=j)
         {
             swap(bb[i][0],bb[j][0]);
             swap(bb[i][1],bb[j][1]);
             b[bb[i][1]][1]=j;
             b[bb[j][1]][1]=i;
             i++;
             j--;
         }
     }
     if(i<r) qsorttt(i,r);
     if(l<j) qsorttt(l,j);
}
int main()
{
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
    int i,j,n,f[100001];
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i][0]);
        aa[i][0]=a[i][0];
        a[i][1]=i;
        aa[i][1]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&b[i][0]);
        bb[i][0]=b[i][0];
        b[i][1]=i;
        bb[i][1]=i;
    }
    qsortt(1,n);
    qsorttt(1,n);
    f[1]=0;
    for(i=2;i<=n;i++)
    {
        if(bb[a[i][1]][1]<i&&aa[b[i][1]][1]<i)
        {
            f[i]=(f[i-1]+2*i-bb[a[i][1]][1]-aa[b[i][1]][1]-1)%99999997;
            for(j=bb[a[i][1]][1];j<i;j++)
                a[aa[i][1]][1]++;
            for(j=aa[b[i][1]][1];j<i;j++)
                b[bb[i][1]][1]++;
        }
        else
        if(bb[a[i][1]][1]<i)
        {
            f[i]=(f[i-1]+i-bb[a[i][1]][1])%99999997;
            for(j=bb[a[i][1]][1];j<i;j++)
                a[aa[i][1]][1]++;
        }
        else
        if(aa[b[i][1]][1]<i)
        {
            f[i]=(f[i-1]+i-aa[b[i][1]][1])%99999997;
            for(j=aa[b[i][1]][1];j<i;j++)
                b[bb[i][1]][1]++;
        }
        else
            f[i]=f[i-1];
    }
    printf("%d\n",f[n]/2);
    return 0;
}
