#include <iostream.h>
#include <stdlib.h>

struct section
{
	int start;
	int end;
};

int cmp(const void* a, const void* b)
{
	section* aa = (section*)a;
	section* bb = (section*)b;
	if (aa->start != bb->start) return aa->start - bb->start;
	else return aa->end - bb->end;
}

int main()
{
	int length, n,last,sum;
	section a[10000];
	int i;
	cin>>length>>n;
	for (i=0;i<n;i++)
		cin>>a[i].start>>a[i].end;
	qsort(a,n,sizeof(section),cmp);
	last=-1;
	sum=0;
	for (i=0;i<n;i++)
	{
		if(a[i].start<=last)
			sum+=a[i].end-last>0?a[i].end-last:0;
		else
			sum+=a[i].end-a[i].start+1;
		if (a[i].end > last) last=a[i].end;
	}
	cout<<length+1-sum<<endl;
	return 0;
}
