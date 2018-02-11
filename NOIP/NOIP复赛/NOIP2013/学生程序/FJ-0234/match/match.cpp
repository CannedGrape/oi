#include<fstream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int d[100005];
int in[100005];
int in2[100005];
long count1,count2;
int main()
{
	freopen("match.in","r",stdin);
	ofstream fout("match.out");
	int n;
	scanf("%d",&n);
		int t1,t2;
		int reali=0;
	for(int i=1;i<=n;i++){
	scanf("%d",in+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",in2+i);
	}
	for(int i=1;i<=n;i++){
		if(in[i]!=in2[i]){
			++reali;
			a[reali]=c[reali]=in[i];
			b[reali]=d[reali]=in2[i];
		}
	}
	//count1 shengxu 
	int tmp;
	count1=count2=0;
	for(int i=1;i<=reali-1;i++){
		for(int j=i+1;j<=reali;j++){
			if(a[i]>a[j]){
				tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
				count1++;
			}
			if(b[i]>b[j]){
				tmp=b[i];
				b[i]=b[j];
				b[j]=tmp;
				count1++;
			}
			if(c[i]<c[j]){//jiangxu
				tmp=c[i];
				c[i]=c[j];
				c[j]=tmp;
				count2++;
			}
			if(d[i]<d[j]){
				tmp=d[i];
				d[i]=d[j];
				d[j]=tmp;
				count2++;
			}
		}
	}
	int min;
	min=(count1>count2?count2:count1);
	min=min%99999997;
	fout<<min;
	fclose(stdin);
	fout.close();
	return 0;
			
	
}
