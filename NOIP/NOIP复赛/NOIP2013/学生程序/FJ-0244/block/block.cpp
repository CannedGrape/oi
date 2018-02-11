#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;
const int N=100000+20000;
int n,h[N],H[N];
int main()
{
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++) cin>>h[i];
	memcpy(H,h,sizeof(h));
	int tot=0;
	while(true){
	    int beg=0;
	    for(beg=0;beg<n;beg++) if(H[beg]) break;
	    if(beg==n) break;
	    int end;
	    for(end=beg;end<n;end++) if(end+1==n||!H[end+1]) break;
	    for(int i=beg;i<=end;i++) H[i]--;
	    tot++;
    }
    cout<<tot<<endl;
    return 0;
}
