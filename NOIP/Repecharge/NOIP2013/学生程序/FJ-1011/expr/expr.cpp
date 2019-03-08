#include <fstream>
#include <string>
using namespace std;
ifstream fin("expr.in");ofstream fout("expr.out");
long q[1000000]={};
char w[1000000]={};
int main()
{
	long fu=0,shu=0,right,tmp,shi,i=0,len,sum=0;
	string a,b,c;
	fin>>a;
	len=a.size();
	while (i<len)
	{
		    b="";
			right=i;
			while(a[i]!='*'&&a[i]!='+'&&i<len)
			{
				b+=a[i];
				i++;
			}
			//fout<<b<<endl;
			shu++;
			fu++;
			tmp=b.size();
			shi=1;
			for (int j=tmp-1+right;j>=right;j--)
			{
				q[shu]+=shi*(a[j]-48);
				shi*=10;
				q[shu]%=10000;
			}
			w[fu]=a[i];
			i++;
	}
	fu--;
	i=1;
	while(i<=fu)
	{ 
		tmp=q[i];
		if (w[i]=='+')
		{
			sum+=tmp;
			i++;
		}
		else
		{
			while(w[i]=='*')
			{i++;
				tmp*=q[i];
				
			}
			sum+=tmp;
		}
	}
	//if (w[fu]=='+')
		//sum+=q[shu];
    sum%=10000;
	//for (int i=1;i<=shu;i++)fout<<q[i]<<' ';
	//for (int i=1;i<=fu;i++)fout<<w[i]<<' ';
	//fout<<fu<< ' '<<shu;
	fout<<sum;
	return 0;
}