#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int p,n,a[1000001],t[1000001],i,j,f[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>n>>p;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    
    for(i=1;i<=n;i++)
    {
		for(j=1;j<=i;j++)
		{
	        t[i]+=a[j];
		}
	}
	for(i=1;i<=n;i++)
	{
	    for(j=1;j<i;j++)
	    {
		    f[i]+=t[j];
		}
	}
	sort(f+1,f+1+n);
	cout<<f[n]%p+1;
    return 0;
}
/*3．小朋友的数字 
(number.cpp/c/pas) 
【问题描述】 
有n个小朋友排成一列。每个小朋友手上都有一个数字，这个数字可正可负。规定每个
小朋友的特征值等于排在他前面（包括他本人）的小朋友中连续若干个（最少有一个）小朋
友手上的数字之和的最大值。 
作为这些小朋友的老师，你需要给每个小朋友一个分数，分数是这样规定的：第一个小
朋友的分数是他的特征值，其它小朋友的分数为排在他前面的所有小朋友中（不包括他本人），
小朋友分数加上其特征值的最大值。 
请计算所有小朋友分数的最大值，输出时保持最大值的符号，将其绝对值对p取模后
输出。 
【输入】 
输入文件为number.in。 
第一行包含两个正整数n、p，之间用一个空格隔开。 
第二行包含n个数，每两个整数之间用一个空格隔开，表示每个小朋友手上的数字。 
【输出】 
  输出文件名为number.out。 
输出只有一行，包含一个整数，表示最大分数对p取模的结果。 */

