#include <stdio.h>
#include <iostream>
#define FOR(i,a,b) for(int i = a;i <= b;++i)
using namespace std;

template <typename t> t MAX(t a,t b){return (a > b)?a:b;}
template <typename t> t MIN(t a,t b){return (a < b)?a:b;}

int n;
int tree  [200001];
int left1 [200001];
int right1[200001];
int data  [100001];
int hasth [200001];

bool cmp(int a,int b)
{
     return (left1[a] < left1[b]);
}

int tail,pis,pds;

void make_tree(int left,int right,int root)
{
     left1[root] = left,right1[root] = right;
     tail = MAX(tail,root);
     if (left == right) tree[root] = data[left];
     else
     {
         int mid = (left + right) / 2;
         make_tree(left,mid,root * 2);
         make_tree(mid + 1,right,root * 2 + 1);
         int mi = MIN(tree[root * 2],tree[root * 2 + 1]);
         tree[root * 2] -= mi;
         tree[root * 2 + 1] -= mi;
         tree[root] = mi;
     }
}

void search_tree()
{
     FOR(i,1,tail)
         if (tree[i] != 0) ++pis,hasth[pis] = i;
     pds = pis - 1;
}

int main()
{
    freopen("block.in","r",stdin);
    freopen("block.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&data[i]);
    tail = pis = 1;
    make_tree(1,n,1);
    search_tree();
    printf("%d",pds);
    return 0;
}
