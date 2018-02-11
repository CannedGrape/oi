#include <iostream>
#include <fstream>
#define MAXN	100000

using namespace std;

int r, n, k, mink;
int x[MAXN], y[MAXN], cx[MAXN], cy[MAXN];

int checked(int xx, int yy)
{
	for(int i = 0; i < k; i++)
		if((cx[i] - xx)*(cx[i] - xx) + (cy[i] - yy)*(cy[i] - yy) <= r*r) return 1;
	return 0;
}

int main(int argc, char *argv[])
{
	int i;
	ifstream fin(argv[1]);
	ifstream fout(argv[2]);
	ifstream fans(argv[3]);
	if (!fout) {
		cout << "Can't open output file!\n0\n";
		return 0;
	}
	fin >> r >> n;
	fans >> mink;
	for(i = 0; i < n; i++)
		fin >> x[i] >> y[i];

	fout >> k;
	for(i = 0; i < k; i++)
		fout >> cx[i] >> cy[i];

	int ok = 1;
	for(i = 0; i < n; i++)
		if(!checked(x[i], y[i])){
			ok = 0;
			break;
		}

	if (!ok) {
		cout << "We still cannot find Jiajia ~~~>_<~~~.\n0\n";
		return 0;
	}	
	else {
		int score = 1 + int((double)mink / k * 9);
		cout << "Jiajia was found ^__^ Your k is " << k << " , Our k is " << mink << endl << score << endl;
	}
	return 0;
}
