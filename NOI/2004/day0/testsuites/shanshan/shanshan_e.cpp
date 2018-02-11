#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream fout(argv[2]);
	if (!fout) {
		cout << "Can't open output file!\n0\n";
		return 0;
	}
	int count;
	fout >> count;
	if (count == -1)
		cout << "Wrong answer.\n0\n";
	else if(count == -2)
		cout << "Invalid function call.\n0\n";
	else if(count == -3)
		cout << "Too many calls.\n0\n";
	else
		cout << "You called " << count << " times.\n10\n";
	return 0;
}
