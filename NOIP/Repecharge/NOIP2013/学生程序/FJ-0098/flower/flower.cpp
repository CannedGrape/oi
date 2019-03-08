#include<cstdio>
#include<iostream>
int h[100010]={0},n,last,i=1,ans=1;
bool down=false,jis=false;
using namespace std;
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    scanf("%d",&n);
    while(i<=n){
        cin>>h[i];
        if(i==1){last=h[i];i++;continue;}
        else if(h[i]>h[i-1]){last=h[i];ans++;i++;down=false;break;}
        else if(h[i]<h[i-1]){last=h[i];ans++;i++;down=true;break;}
        else i++;}
    for(;i<=n;i++){
        cin>>h[i];
        if(down&&h[i]>last){
            ans++;down=false;last=h[i];}
        else if(!down&&h[i]<last){
            ans++;down=true;last=h[i];}
        else if(down&&h[i]<last)last=h[i];
        else if(!down&&h[i]>last)last=h[i];
        }
    cout<<ans<<endl;
    return 0;
}
