#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int N,a[100010]={},b[100010]={},cnt,t,ans=0;
int main(){
    freopen("match.in","r",stdin);freopen("match.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;++i)scanf("%d",&a[i]);
    for(int i=1;i<=N;++i)scanf("%d",&b[i]);
    do{
            cnt=0;
            for(int i=1;i<=N-1;++i)
            if(((long long)(a[i]-b[i])*(long long)(a[i]-b[i])+(long long)(a[i+1]-b[i+1])*(long long)(a[i+1]-b[i+1]))>((long long)(a[i]-b[i+1])*(long long)(a[i]-b[i+1])+(long long)(a[i+1]-b[i])*(long long)(a[i+1]-b[i])))
            {
                t=a[i];a[i]=b[i];b[i]=a[i];
                ++cnt;
            }
            ans=(ans+cnt)%99999997;
    }while(cnt);
    printf("%d\n",ans);
//    system("pause");
	fclose(stdin);fclose(stdout);
    return 0;
}
