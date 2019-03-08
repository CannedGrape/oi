#include<iostream>
#include<cstdio>
using namespace std;
int n=0,h[101000]={},f[101000]={},g[101000]={},left_h,right_h;
//f[i] 第i朵花，两端的高度都比它低，g[i] 第i朵花，两端的高度都比它高。 
struct tree
{
    int l,r,value;
}f_tree[4040000]={},g_tree[4040000]={};
//用于对f的决策，下一个高度要比他高。          用于对g的决策 
int minh=0x3fffffff,maxh=0,pos_f=0,pos_g=0,h_f=0,h_g=0;
void make_f_tree(int l,int r,int k);
void make_g_tree(int l,int r,int k);
void change_f(int k);
void change_g(int k);
int find_f_max(int k);
int find_g_max(int k);
void init();
void work()
{
     int ans=1;
     //for(int i=1;i<=n;++i)
     //    cout<<h[i]<<' ';
     //cout<<endl;
     for(int i=1;i<=n;++i)
     {
         left_h=0;
         right_h=h[i]-1;
         f[i]=find_f_max(1)+1;
         
         left_h=h[i]+1;
         right_h=maxh+1;
         g[i]=find_g_max(1)+1;
         
         h_g=f[i];
         pos_g=h[i];
         change_g(1);
         
         h_f=g[i];
         pos_f=h[i];
         change_f(1);
         
         if(f[i]>ans)
             ans=f[i];
         if(g[i]>ans)
             ans=g[i];
     }
     //for(int i=1;i<=n;++i)
     //    cout<<f[i]<<' '<<g[i]<<endl;
     printf("%d\n",ans);
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    init();
    if(n==0)
        printf("0\n");
    else
        work();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

void make_f_tree(int l,int r,int k)
{
     f_tree[k].l=l;
     f_tree[k].r=r;
     f_tree[k].value=0;
     if(l!=r)
     {
         int mid=(l+r)>>1;
         make_f_tree(l,mid,k<<1);
         make_f_tree(mid+1,r,(k<<1)+1);
     }
}
void make_g_tree(int l,int r,int k)
{
     g_tree[k].l=l;
     g_tree[k].r=r;
     g_tree[k].value=0;
     if(l!=r)
     {
         int mid=(l+r)>>1;
         make_g_tree(l,mid,k<<1);
         make_g_tree(mid+1,r,(k<<1)+1);
     }
}
void change_f(int k)
{
     if(f_tree[k].l==f_tree[k].r)
     {
         if(h_f>f_tree[k].value)
             f_tree[k].value=h_f;
         return;
     }
     if(f_tree[k<<1].r>=pos_f)
         change_f(k<<1);
     if(f_tree[(k<<1)+1].l<=pos_f)
         change_f((k<<1)+1);
     f_tree[k].value=max(f_tree[k<<1].value,f_tree[(k<<1)+1].value);
}
void change_g(int k)
{
     if(g_tree[k].l==g_tree[k].r)
     {
         if(h_g>g_tree[k].value) //OrzHGG~~
             g_tree[k].value=h_g;
         return;
     }
     if(g_tree[k<<1].r>=pos_g)
         change_g(k<<1);
     if(g_tree[(k<<1)+1].l<=pos_g)
         change_g((k<<1)+1);
     g_tree[k].value=max(g_tree[k<<1].value,g_tree[(k<<1)+1].value);
}
int find_f_max(int k)
{
     if(f_tree[k].l>=left_h && f_tree[k].r<=right_h)
         return f_tree[k].value;
     int v=0;
     if(left_h<=f_tree[k<<1].r)
         v=find_f_max(k<<1);
     if(right_h>=f_tree[(k<<1)+1].l)
         v=max(v,find_f_max((k<<1)+1));
     return v;
}
int find_g_max(int k)
{
     if(g_tree[k].l>=left_h && g_tree[k].r<=right_h)
         return g_tree[k].value;
     int v=0;
     if(left_h<=g_tree[k<<1].r)
         v=find_g_max(k<<1);
     if(right_h>=g_tree[(k<<1)+1].l)
         v=max(v,find_g_max((k<<1)+1));
     return v;
}
void init()
{
     scanf("%d",&n);
     if(n==0)
         return;
     for(int i=1;i<=n;++i)
     {
         scanf("%d",&h[i]);
         if(h[i]>maxh)
             maxh=h[i];
         if(h[i]<minh)
             minh=h[i];
     }
     for(int i=1;i<=n;++i)
         h[i]-=minh-1;
     maxh-=minh-1;
     minh=0;
     make_f_tree(0,maxh+1,1);
     make_g_tree(0,maxh+1,1);
}
