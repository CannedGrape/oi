#include <stdio.h>
int QuickSort(unsigned long a[], int low, int high)	//快速排序。
{
	int i = low, j = high;
	unsigned long temp = a[low];
	while(i < j)
	{
		while(j > i && temp <= a[j])
			j--;
		if(j > i)
		{
			a[i] = a[j];
			i++;
		}
		while(j > i && a[i] < temp)
			i++;
		if(j > i)
		{
			a[j] = a[i];
			j--;
		}
	}
	a[i] = temp;
	if(low < i) QuickSort(a, low, i - 1);
	if(i < high) QuickSort(a, j + 1, high);
return 0;
}

int main()
{
	unsigned long Fruit[10005], temp, energy = 0;
	int i, j, kind;
	FILE *fp, *fp2;
	fp = fopen("fruit.in", "r");	//文件输入。
	fscanf(fp, "%d", &kind);
	for(i = 1; i <= kind; i++)
		fscanf(fp, "%ld", &Fruit[i]);
	fclose(fp);

	QuickSort(Fruit, 1, kind);	//快速排序。
/*
	for (i=1;i<=kind;i++)	//冒泡排序，效率极差。
	{
		for (j=1;j<kind;j++)
		{
			if (Fruit[j]>Fruit[j+1])
			{
				temp=Fruit[j+1];
				Fruit[j+1]=Fruit[j];
				Fruit[j]=temp;
			}
		}
	}
*/
	for(i = 2; i <= kind; i++)	//计算最小能量。
	{
		Fruit[i] = Fruit[i] + Fruit[i - 1];
		energy += Fruit[i];
		j = i;
		while (Fruit[j] > Fruit[j + 1] && j < kind)
		{
			temp = Fruit[j + 1];
			Fruit[j + 1] = Fruit[j];
			Fruit[j] = temp;
			j++;
		}
	}//for.
	fp2 = fopen("fruit.out", "w");	//文件输出。
	fprintf(fp2, "%ld", energy);
	fclose(fp2);
return 0;
}
