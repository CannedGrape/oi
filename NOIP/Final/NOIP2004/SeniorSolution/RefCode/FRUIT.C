#include <stdio.h>
void main()
{
	unsigned long Fruit[10005],temp,energy=0;
	int i,j,kind;
	FILE *fp,*fp2;

	fp=fopen("fruit.in","r");
	fscanf(fp,"%d",&kind);
	for (i=1;i<=kind;i++)
	{
		fscanf(fp,"%ld",&Fruit[i]);
	}
	fclose(fp);

///////////////////////////////////////////////////////////////////////

	for (i=1;i<=kind;i++)
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

//////////////////////////////////////////////////////////////////////

	for (i=2;i<=kind;i++)
	{
		Fruit[i]=Fruit[i]+Fruit[i-1];
		energy+=Fruit[i];
//		Fruit[i-1]=0;
		j=i;
		while (Fruit[j]>Fruit[j+1] && j<kind)
		{
			temp=Fruit[j+1];
			Fruit[j+1]=Fruit[j];
			Fruit[j]=temp;
			j++;
		}
	}

////////////////////////////////////////////////////////////////////////

	fp2=fopen("fruit.out","w");

//	for (i=1;i<=kind;i++)
//	{
//		fprintf(fp2,"%ld\n",/*energy*/Fruit[i]);
//	}
	fprintf(fp2,"%ld",energy);
	fclose(fp2);
}

