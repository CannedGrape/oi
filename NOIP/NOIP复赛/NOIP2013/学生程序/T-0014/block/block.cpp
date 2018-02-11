# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <string>
# include <algorithm>
# include <math.h>

using namespace std;

int main() {
	freopen("block.in","r",stdin);
	freopen("block.out","w",stdout);
	int n,x,y = 0,sum = 0;
	scanf("%d",&n);
	while (n--) { 
		scanf("%d",&x); 
		if (x > y) sum += (x - y);
		y = x;
	}
	printf("%d\n",sum);
	return 0;
}
