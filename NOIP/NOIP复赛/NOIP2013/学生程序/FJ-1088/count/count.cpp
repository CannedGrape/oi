#include <cmath>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cstring> 
#include <iostream>
#include <algorithm>
using namespace std;
long long n, x, total = 0;
int main ()
{
	freopen("count.in" ,"r", stdin);
	freopen("count.out" ,"w", stdout);
	cin>>n>>x;
	for (int i = 1; i<= n; i++)
	{
		if (i>0 && i<10)
			{if (i == x) total++;}
		else
		{		
			if (i>=10 && i<100)
			{
				if (i%10 == x) total++;
				if (i/10 == x) total++;
			}
			else
			{
				if (i>=100 && i<1000)
				{
					if (i%10 == x) total++;
					if (i/10%10 == x) total++;
					if (i/100 == x) total++;	
				}
				else
				{
					if (i>=1000 && i<10000)
					{
						if (i%10 == x) total++;
						if (i/100%10 == x) total++;
						if (i/10%10 == x) total++;
						if (i/10 == x) total++;	
					}
					else
					{
						if (i>=10000 && i<100000)
						{
							if (i%10 == x) total++;
							if (i/1000%10 == x) total++;
							if (i/100%10 == x) total++;
							if (i/10%10 == x) total++;
							if (i/10 == x) total++;	
						}
						else
						{
							if (i>=100000 && i<1000000)
							{
								if (i%10 == x) total++;
								if (i/10000%10 == x) total++;
								if (i/1000%10 == x) total++;
								if (i/100%10 == x) total++;
								if (i/10%10 == x) total++;
								if (i/10 == x) total++;	
							}
							else
								if(i == 1000000)
								{
									if (x == 1)	total++;
									if (x == 0) total+=6;
								}
						}
					}
				}
			}
		}		
	}
	cout<<total;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
