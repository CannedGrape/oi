#include <stdio.h>
void main()
{
	int MoneyOut[12];
	int i,mum=0,ii=0,save=0;
	FILE *fp,*fp2;
	fp=fopen("save.in","r");
	for (i=1;i<=12;i++)
	{
		fscanf(fp,"%d",&MoneyOut[i]);
	}
	fclose(fp);
	for (i=1;i<=12;i++)
	{
		save=save+300-MoneyOut[i];
		if (save>=0)
		{
			if (save>=100) {mum+=save-save%100;}
			save%=100;
		}
		else
		{
			ii=i;
			goto prnt;
		}
	}
prnt:
	save=save+mum+mum*2/10;
	fp2=fopen("save.out","w");
	if (ii==0)
	{
		fprintf(fp2,"%d",save);
	}
	else
	{
		fprintf(fp2,"-%d",ii);
	}
	fclose(fp2);
}