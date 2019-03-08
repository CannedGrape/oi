#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
//==================
int n,p,a[1000001],							//输入 
	tz[1000001],fs[1000001],				//中转站 
	ALLAns;									//输出 

int A(int n) {								//n以下连续a[]最大值
	int Ans=0,Ans1=0; 
	int i;
    for (i=1; i<=n; i++) {
		if (a[i]>0) {
			Ans1=Ans1+a[i];
		}
		else {
			if (Ans1>Ans)
				Ans=Ans1;
			Ans1=0;
		}
	}
	if (Ans==0) {
		if (Ans1==0) {
			Ans=a[1];
			for (i=2; i<=n; i++)
				if(a[i]>Ans)
					Ans=a[i];
		}
		else
			Ans=Ans1;
	}
	return Ans;
}

int main ( ) {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    //================================
    int i,j,
		s;									//fs假定最大值（下用。 
	
	scanf("%d%d",&n,&p);
    for (i=1; i<=n; i++) scanf("%d",&a[i]);

	tz[1]=a[1];
    fs[1]=a[1];
//  初始化结束。 
    for (i=2; i<=n; i++)
		tz[i]=A(i);
//	现以求出各个人特征值。（过程上 int A (...)中。 
	for (i=2; i<=n; i++) {
		s=tz[1]+fs[1];
		for (j=1; j<i; j++)
			if(tz[j]+fs[j]>s)
				s=tz[j]+fs[j];
		fs[i]=s;
	}
//	现以求出各个人分数及特征值。 
	ALLAns=fs[1];
	for (i=1; i<=n; i++)
		if (fs[i]>ALLAns)
			ALLAns=fs[i];
//	现以从所有小朋友中找出分数最大的那一个的分数了。
	if (ALLAns>p)
		ALLAns=ALLAns%p;
//	ALLAns做完了最后的处理（ALLAns mod p)
	printf("%d\n",ALLAns);
	
	//================================
    fclose(stdin);
    fclose(stdout);
    system ("pause");
    return 0;
}
