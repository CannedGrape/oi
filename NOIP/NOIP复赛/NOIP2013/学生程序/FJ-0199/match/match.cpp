#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100100,P=99999997;
struct Dot{
    int x,pos;
    bool operator <(const Dot&rhs) const{
	    return x<rhs.x;
	}
}a[maxn],b[maxn];
int n,num[maxn],ans,m[maxn];
int get(){
    int f=0,v=0; char ch;
    while (!isdigit(ch=getchar())) if (ch=='-') break;
    if (ch=='-') f=1; else v=ch-48;
    while (isdigit(ch=getchar())) v=v*10+ch-48;
    if (f) return -v; else return v;
}
bool cmp(int x1,int x2){
    return x1>x2;
}
void me(int l,int mid,int r){
    int l1=l,r1=mid,l2=mid+1,r2=r;
    int sum=0; int k=l-1;
    while (l1<=r1&&l2<=r2){
		k++;
	    if ((l1<=r1&&l2<=r2&&num[l1]<=num[l2])||l2>r2){
		    m[k]=num[l1]; ans=(ans+sum)%P; l1++;
		}
		else {
		    m[k]=num[l2]; sum++; l2++;
		}
	}
	for (int j=l1;j<=r1;j++) m[++k]=num[j],ans=(ans+sum)%P;
	for (int j=l2;j<=r2;j++) m[++k]=num[j];
	for (int i=l;i<=r;i++) num[i]=m[i];
}
void ms(int l,int r){
    int mid=(l+r)>>1;
    if (l==r) return;
    ms(l,mid);
    ms(mid+1,r);
    me(l,mid,r);
}
int main(){
    freopen("match.in","r",stdin);
    freopen("match.out","w",stdout);
	n=get();
	for (int i=1;i<=n;i++){
	    a[i].x=get(); a[i].pos=i;
	} 
	for (int i=1;i<=n;i++){
	    b[i].x=get(); b[i].pos=i;
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for (int i=1;i<=n;i++){
	   num[b[i].pos]=a[i].pos;
	}
    ms(1,n);
	printf("%d\n",ans);
	return 0;
}
