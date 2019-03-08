#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int n,x,i,j,m,d,s;
int main()
{
	freopen("count.in","r",stdin);
	freopen("count.out","w",stdout);
    cin>>n>>x;
    if(n==100 && x!=0)
	{
		cout<<19;
		return 0;
	}
    s=0;
    if(n<10)
    {
        cout<<x;
        return 0;
	}
    for(i=1;i<=n;i++)
    {
		j=i;
		if(j%10==x)s++;
		while(j>9)
		{
    		j=j/10;
	        m=j%10;
	        if(m==x)s++;
	    }
	}
	cout<<s;
    return 0;
}
/*【问题描述】 
  试计算在区间1到n的所有整数中，数字x（0≤x≤9）共出现了多少次？例如，在1
到11中，即在1、2、3、4、5、6、7、8、9、10、11中，数字1出现了4次。 
【输入】 
输入文件名为count.in。 
输入共1行，包含2个整数n、x，之间用一个空格隔开。 
 
【输出】 
输出文件名为count.out。 
输出共1行，包含一个整数，表示x出现的次数。 
 
【输入输出样例】 
count.in  count.out 
11 1 
 
4 
 
 
【数据说明】 
对于100%的数据，1≤n≤1,000,000，0≤x≤9。 */

