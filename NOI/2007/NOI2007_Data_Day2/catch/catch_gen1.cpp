#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

int n;

FILE * fout;

void gen()
{
    fprintf(fout, "%d\n", n);
    for (int u=1; u<n; ++u) {
        int v = rand()%u;
        fprintf(fout, "%d %d\n", u+1, v+1);
    }
}

int main(int argc, char * argv[])
{
	srand(time(0));
    n = atoi(argv[1]);
    fout = fopen(argv[2], "w");
    gen();
    fclose(fout);

    return 0;
}

