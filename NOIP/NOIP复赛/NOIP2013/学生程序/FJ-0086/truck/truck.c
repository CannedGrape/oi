#include<stdio.h>
#define min(A,B)A<B?A:B
#define max(A,B)A>B?A:B
int n,m,x,y,z,Q,ans=999999,ok=0;
int e[50001][4]={0},last[10001]={0},top=0;
int fa[10001]={0},a[50001][2]={0},s[10001]={0};
int ee[20001][4]={0},ll[10001]={0},tt=0,vv[10001]={0};
void add(int sn,int fn,int va)
{
     top++;
     e[top][0]=sn;
     e[top][1]=fn;
     e[top][2]=va;
     e[top][3]=last[sn];
     last[sn]=top;
}
void adde(int sn,int fn,int va)
{
     tt++;
     ee[tt][0]=sn;
     ee[tt][1]=fn;
     ee[tt][2]=va;
     ee[tt][3]=ll[sn];
     ll[sn]=tt;
}
int find(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=find(fa[x]);
        return fa[x];
    }
    else return x;
}
void qsort(int x,int y)
{
     int i=x,j=y,mid=a[(i+j)/2][0],k;
     while(i<=j)
     {
         while(a[i][0]>mid)i++;
         while(a[j][0]<mid)j--;
         if(i<=j)
         {
                 k=a[i][0];a[i][0]=a[j][0];a[j][0]=k;
                 k=a[i][1];a[i][1]=a[j][1];a[j][1]=k;
                 i++;j--;
         }
     }
     if(i<y)qsort(i,y);
     if(x<j)qsort(x,j);
}
void kru()
{
     int i,j,t,z,p,q,x,y;
     for(i=1;i<=m;i++)
     {
         t=a[i][1];z=a[i][0];
         x=e[t][0];y=e[t][1];
         p=find(x);q=find(y);
         if(p!=q)
         {
             fa[p]=q;
             adde(x,y,z);adde(y,x,z);
         }
         if(s[0]==n-1)break;
     }
}
void seek(int x,int y)
{
     int i,j;
     if(x==y){ok=1;return;}
     for(i=ll[x];i!=0;i=ee[i][3])
     if(vv[ee[i][1]]==0)
     {
         vv[ee[i][1]]=1;
         seek(ee[i][1],y);
         vv[ee[i][1]]=0;
         if(ok==1)ans=min(ee[i][2],ans);
     }        
}                       
int main()
{
    freopen("truck.in","r",stdin);
    freopen("truck.out","w",stdout);
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        a[top][0]=z;a[top][1]=top;
    }
    for(i=1;i<=n;i++)fa[i]=i;
    qsort(1,m);
    kru();
    scanf("%d",&Q);
    for(i=1;i<=Q;i++)
    {
        scanf("%d%d",&x,&y);
        if(find(x)==find(y)){ans=999999;ok=0;seek(x,y);printf("%d\n",ans);}
        else printf("-1\n");
    }
    return 0;
}
