#include<cstdio>
int n,h[100001],tot,ans;
int a[100001];
int main()
{   freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    int l=1;
    scanf("%d",&n);
    tot=n;
    for (int i=1;i<=n;++i){scanf("%d",&h[i]);if(h[i]==0)tot--;}
    while (tot!=0)
    { 
    
    while (a[l]==h[l])++l;
    int x=h[l]-a[l];
    int r=l;
    while ((r<n&&h[r+1]!=a[r+1])){++r;if(r>l)x=x<h[r]-a[r]?x:h[r]-a[r];}
    for (int i=l;i<=r;++i){a[i]+=x;if (a[i]==h[i])tot--;}
    ans+=x;
    }
    printf("%d",ans);
    fclose(stdin);fclose(stdout);
}
