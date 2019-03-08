#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
int m[1000005];
int main(){
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
	long long n,x,count=0;
	cin>>n>>x;
	long long i,j;
	for(i=1;i<=n;i++){
	    m[i]=i;
		while(m[i]!=0){	
	        if(m[i]%10==x) count++;
	        m[i]/=10;
		}
	    
	}
	cout<<count;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
