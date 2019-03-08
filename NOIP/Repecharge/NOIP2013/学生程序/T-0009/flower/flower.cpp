#include<cstdio>
int h[100001];
int f[2][2];
int n;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;++i)scanf("%d",&h[i]);
    f[0][0]=f[0][1]=f[1][1]=f[1][0]=1;
    for (int i=2;i<=n;++i)
    {
        if (h[f[0][1]]<h[i])
        {
           if (f[0][0]%2==1)++f[0][0];
           f[0][1]=i;                
        }
        else if (h[f[0][1]]>h[i])
        {
           if (f[0][0]%2==0)++f[0][0];
           f[0][1]=i;  
        }
        //运用条件A（g[2i-1]<g[2i]&&g[2i+1]<g[2i]）; 
        if (h[f[1][1]]>h[i])
        {
            if (f[1][0]%2==1)++f[1][0];
            f[1][1]=i;                
        }
        else if (h[f[1][1]]<h[i])
        {
            if (f[1][0]%2==0)++f[1][0];
            f[1][1]=i; 
        }
        //运用条件B （g[2i-1]>g[2i]&&g[2i+1]>g[2i]） ;
    }
    if (f[0][0]>f[1][0])printf("%d\n",f[0][0]);
    else printf("%d\n",f[1][0]);
    fclose(stdin);fclose(stdout);
}     
