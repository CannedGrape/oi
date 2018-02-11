#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 
using namespace std;
//==================
 
int n,x,									// ‰»Î 
	ans=0;									//¥∞∏ 
 
int main ( ) {
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
    
    scanf("%d%d",&n,&x);
    
    int i,j=1,l,num;						//For”√°£ 
    bool N;
    
    for (i=1;i<=n;i++){
		N=1;
        while(N){
			l=j*10;
    		num=i%l/j;
    		if(num==x) ans++;
    		j=j*10;
    		if(j>i) N=0;
		}
		j=1;
	}
	printf("%d\n",ans);
	
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
