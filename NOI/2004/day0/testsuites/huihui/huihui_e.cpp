#include <iostream>
#include <fstream>

using namespace std;

int a1, a2;

int main(int argc, char *argv[])
{
	ifstream fout(argv[2]);
	ifstream fans(argv[3]);
	if (!fout) {
		cout << "Can't open output file!\n0\n";
		return 0;
	}
	fout >> a1;
	fans >> a2;
	if (a1 != a2)
		cout << "Wrong Answer.\n0\n";
	else
		cout << "Correct!\n10\n";
	return 0;
}
