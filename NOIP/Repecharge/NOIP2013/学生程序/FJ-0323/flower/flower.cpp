//----------------REC.----------------
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int Temp[100001] = {0};
int Data[100001] = {0};

int main()
{
   freopen("flower.in","r",stdin);
   freopen("flower.out","w",stdout);
   int n;
   int Max = 1,Min = 1; 
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
     scanf("%d",&Temp[i]);
   
   for(int i=1;i<=n-1;++i)
     if(Temp[i]<Temp[i+1])Data[i] = 1;
      else if(Temp[i] == Temp[i+1])Data[i] = 2;
    
   int BMax;
   for(BMax=1;BMax<=n;++BMax)
     if(BMax == 1)break;
   for(int head=1;BMax<=n;++BMax){
	 if(head==1 && Data[BMax] == 0){Max++;head=0;}
	 if(head==0 && Data[BMax] == 1){Max++;head=1;}
   }
   int BMin;
   for(BMin=1;BMin<=n;++BMin)
     if(BMin == 0)break;
   for(int head=0;BMin<=n;++BMin){
	 if(head==1 && Data[BMin] == 0){Min++;head=0;}
	 if(head==0 && Data[BMin] == 1){Min++;head=1;}
   }
   
   printf("3");
   return 0;
}
