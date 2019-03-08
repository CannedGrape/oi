#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;

#define MAXN 2000

int n;

int visit[MAXN+1];
int map[MAXN+1][MAXN+1];

void dfs(int u)
{
    assert(!visit[u]);
    visit[u] = 1;
    for (int v=0; v<n; ++v) {
        if (map[u][v]) {
            map[u][v] = map[v][u] = 0;
            dfs(v);
        }
    }
}

void check(const char * file)
{
FILE * fin = fopen(file, "r");
fscanf(fin, "%d", &n);

    memset(visit, 0, sizeof(visit));
    memset(map, 0, sizeof(map));
    for (int i=1; i<n; ++i) {
	int u, v;
	fscanf(fin, "%d%d", &u, &v);
	--u;
	--v;
        assert(u>=0 && u<n && v>=0 && v<n && u!=v);
        map[u][v] = map[v][u] = 1;
    }
    
    dfs(0);
    
    for (int i=0; i<n; ++i) {
        assert(visit[i]);
    }
}

int main(int argc, char * argv[])
{
check(argv[1]);
printf("OK\n");
    return 0;
}
