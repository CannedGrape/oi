#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100100,inf=211111111;
int N,a[maxn];
struct Heap{
    int h,sum;
    bool operator <(const Heap&rhs)const{
	    return sum<rhs.sum; 
	}
};
queue<Heap>Q;
priority_queue<Heap>Heap1;
priority_queue<Heap>Heap2;
int get(){
    int v=0,f=0; char ch;
    while (!isdigit(ch=getchar())) if (ch=='-') break;
    if (ch=='-') f=1; else v=ch-48;
    while (isdigit(ch=getchar())) v=v*10+ch-48;
    if (f) return -v; else return v;
}
int main(){
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    N=get();
    for (int i=1;i<=N;i++) a[i]=get();
    Heap1.push((Heap){-1,0}); Heap2.push((Heap){inf,0});
    while (!Q.empty()) Q.pop();
    for (int i=1;i<=N;i++){
        while (Heap1.top().h>=a[i]){
		    Q.push(Heap1.top());
		    Heap1.pop();
		}
		Heap2.push((Heap){a[i],Heap1.top().sum+1});
		while (!Q.empty()) {Heap1.push(Q.front()); Q.pop();}
		while (Heap2.top().h<=a[i]){
		    Q.push(Heap2.top());
		    Heap2.pop();
		}
		Heap1.push((Heap){a[i],Heap2.top().sum+1});
		while (!Q.empty()){Heap2.push(Q.front()); Q.pop();}
	
	}
	int ans=max(Heap1.top().sum,Heap2.top().sum);
	printf("%d\n",ans); 
    return 0;
}
