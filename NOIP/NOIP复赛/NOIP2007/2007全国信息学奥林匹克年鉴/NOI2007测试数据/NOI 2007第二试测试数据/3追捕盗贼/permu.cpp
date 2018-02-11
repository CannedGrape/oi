#include <cstdio>
#include <cstdlib>
using namespace std;

#define MAXN 20000

int permu[MAXN+1];

void gen_permu(int n)
{
    srand(1110);
    for (int i=0; i<n; ++i) {
        permu[i] = i;
    }
    
    for (int i=0; i<n-1; ++i) {
        int j = i+rand()%(n-i);
        if (j!=i) {
            int t = permu[i];
            permu[i] = permu[j];
            permu[j] = t;
        }
    }
}

void work(const char * inf, const char * outf)
{
    FILE * fin = fopen(inf, "r");
    FILE * fout = fopen(outf, "w");

    int n;

    fscanf(fin, "%d", &n);
    fprintf(fout, "%d\n", n);
    
    gen_permu(n);
    
    for (int i=0; i<n-1; ++i) {
        int u, v;
        fscanf(fin, "%d%d", &u, &v);
        --u;
        --v;
        fprintf(fout, "%d %d\n", permu[u]+1, permu[v]+1);
    }

    fclose(fin);
    fclose(fout);
}

int main(int argc, char * argv[])
{
    work(argv[1], argv[2]);

    return 0;
}

