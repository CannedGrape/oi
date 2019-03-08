#include <cstdio>
#include <algorithm>
using namespace std;
const int MaxM = 10;
const int MaxN = 5;

int main(){
	freopen("truck.in","w",stdout);
	printf("%d %d\n", MaxN, MaxM);
	for (int i = 0; i < MaxM; i++){
		int x = rand()%MaxN + 1;
		int y = rand()%MaxN + 1;
		while (x == y){
			y = rand()% MaxN + 1;
		}
		printf("%d %d %d\n",x,y,rand()%100000 + 1);
	}
	printf("%d\n",30000);
	for (int i = 0; i < 30000; i++){
		int x = rand()%MaxN + 1;
		int y = rand()%MaxN + 1;
		while (x == y){
			y = rand()% MaxN + 1;
		}
		printf("%d %d\n",x,y);
	}
}
