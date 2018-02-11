#include <cstdio>
#include <cassert>
#include <cstring>

#define MAXN 2000

#define MAXT 40000

struct Edge {
    int x, y;
    int invalid;
    
    int valid()
    {
        return !invalid;
    }
    
    int other_from(int u)
    {
        if (invalid) {
            return -1;
        }
        if (u==x) {
            return y;
        } else if (u==y) {
            return x;
        }

        return -1;
    }
};

enum Type {
    Hub,
    Ending,
    Internal,
    Midst
};

struct Info {
    Type type;
    int s;
    int av_start, av_end;
    Info * m_info;
};

struct Step {
    char cmd; // 'L' 'B' 'M'
    int u;
    int v;
};

int T; // number of steps
Step steps[MAXT+1];

int n;

int main_s_output;

int deg[MAXN+1];
Edge edges[MAXN+1];
Edge * graph[MAXN+1][MAXN+1];
int dist[MAXN+1][MAXN+1];

FILE * fout = fopen("catch.out", "w");

void genstep(char cmd, int u, int v)
{
    steps[T].cmd = cmd;
    steps[T].u = u;
    steps[T].v = v;
    ++T;
}

void output()
{
    fprintf(fout, "%d\n", T);
    for (int i=0; i<T; ++i) {
        switch (steps[i].cmd) {
            case 'L': fprintf(fout, "L %d\n", steps[i].u+1);
                      break;
            case 'B': fprintf(fout, "B %d\n", steps[i].u+1);
                      break;
            case 'M': fprintf(fout, "M %d %d\n", steps[i].u+1, steps[i].v+1);
                      break;
            default:  assert(0);
                      break;
        }
    }
    fclose(fout);
}

void dfs_find_dist(int src, int v, int d)
{
    dist[src][v] = d;
    for (int i=0; i<deg[v]; ++i) {
        int u = graph[v][i]->other_from(v);
        if (dist[src][u]<0) {
            dfs_find_dist(src, u, d+1);
        }
    }
}

void init()
{
    FILE * fin = fopen("catch.in", "r");

    memset(deg, 0, sizeof(deg));
    memset(edges, 0, sizeof(edges));

    fscanf(fin, "%d", &n);
    for (int i=0; i<n-1; ++i) {
        int u, v;
        fscanf(fin, "%d%d", &u, &v);
        --u;
        --v;
        edges[i].x = u;
        edges[i].y = v;
        edges[i].invalid = 0;

        graph[u][deg[u]++] = edges+i;
        graph[v][deg[v]++] = edges+i;
    }

    fclose(fin);
    
    main_s_output = 1;
    T = 0;
    
    for (int u=0; u<n; ++u) {
        for (int v=0; v<n; ++v) {
            dist[u][v] = -1;
        }
    }

    for (int u=0; u<n; ++u) {
        dfs_find_dist(u, u, 0);
    }
}

Info * re_root(Info * info_old, int root, int root_old)
{
    Info * info = new Info;
    
    info->s = info_old->s;
    info->av_start = info_old->av_start;
    info->av_end = info_old->av_end;

    switch (info_old->type) {
        case Hub:
        case Ending:
            info->type = Ending;
            break;
        case Internal:
            if (info->s==1) {
                info->type = Ending;
            } else {
                info->type = Midst;
                info->m_info = new Info;
                info->m_info->type = Ending;
                info->m_info->s = 1;
                info->m_info->av_start = root;
                info->m_info->av_end = root_old;
            }
            break;
        case Midst:
			// random cover
            info->type = Midst;
            info->m_info = re_root(info_old->m_info, root, root_old);
            break;
    }

    return info;
}

int farther(int u, int a, int b)
{
    if (dist[u][b]>dist[u][a]) {
        return b;
    } else {
        return a;
    }

    return -1;
}

Info * merge(Info * info1, Info * info2, int root)
{
    Info * info = new Info;

    info->s = -1;

    if (info1->s < info2->s || (info1->s==info2->s && info1->type>info2->type)) {
        Info * tmp = info1;
        info1 = info2;
        info2 = tmp;
    }

    if (info1->s == info2->s) {
        if (info1->type==Hub && info2->type==Hub) {
            // Case 1  nocover
            info->type = Hub;
            info->s = info1->s;
            info->av_start = info->av_end = root;
        } else if (info1->type==Hub && info2->type==Ending) {
            // Case 2 random cover
            info->type = Ending;
            info->s = info1->s;
            info->av_start = root;
            info->av_end = farther(root, info2->av_start, info2->av_end);
        } else if (info1->type==Ending && info2->type==Ending) {
            // Case 3
            info->type = Internal;
            info->s = info1->s;
            info->av_start = farther(root, info1->av_start, info1->av_end);
            info->av_end = farther(root, info2->av_start, info2->av_end);
        } else if (info1->type==Hub && info2->type==Internal) {
            // Case 4 nocover
            info->type = Internal;
            info->s = info1->s;
            info->av_start = info2->av_start;
            info->av_end = info2->av_end;
        } else {
            assert( (info1->type==Midst || info2->type==Midst) ||
                    (info1->type==Internal && info2->type==Internal) ||
                    (info1->type==Ending && info2->type==Internal) );
            // Case 5
            info->type = Hub;
            info->s = info1->s+1;
            info->av_start = info->av_end = root;
        }
    } else {
        assert(info1->s > info2->s);
        if (info1->type==Hub || info1->type==Ending || info1->type==Internal) {
            info->type = info1->type;
            info->s = info1->s;
            if (info->type==Hub || info->type==Internal) {
				// random cover
                info->av_start = info1->av_start;
                info->av_end = info1->av_end;
            } else {
                assert(info->type==Ending);
                info->av_start = farther(root, info1->av_start, info1->av_end);
                info->av_end = root;
            }
        } else {
            assert(info1->type == Midst);
            Info * tmp = merge(info1->m_info, info2, root);
            assert(tmp->s <= info1->s);
            if (tmp->s < info1->s) {
                info->type = Midst;
                info->s = info1->s;
                info->m_info = tmp;
                info->av_start = info1->av_start;
                info->av_end = info1->av_end;
            } else {
				// random cover
                info->type = Hub;
                info->s = info1->s+1;
                info->av_start = info->av_end = root;
            }
        }
    }

    assert(info->s>0);

    return info;
}

Info * calc_info(int root)
{
    int d = 0;
    int neighbor_index = -1;
    int neighbor;
    Info * info = NULL;
    for (int i=0; i<deg[root]; ++i) {
        if (graph[root][i]->valid()) {
            ++d;
            neighbor_index = i;
            neighbor = graph[root][i]->other_from(root);
        }
    }

    assert(d>0);

    if (d==1) {
        d = 0;
        for (int i=0; i<deg[neighbor]; ++i) {
            if (graph[neighbor][i]->valid()) {
                ++d;
            }
        }
        if (d>1) {
            info = re_root(calc_info(neighbor), root, neighbor);
        } else {
            info = new Info;
            info->type = Ending;
            info->s = 1;
            info->m_info = NULL;
            info->av_start = root;
            info->av_end = neighbor;
        }
    } else {
        ++graph[root][neighbor_index]->invalid;
        Info * info1 = calc_info(root);
        --graph[root][neighbor_index]->invalid;
        for (int i=0; i<neighbor_index; ++i) {
            ++graph[root][i]->invalid;
        }
        Info * info2 = calc_info(root);
        for (int i=0; i<neighbor_index; ++i) {
            --graph[root][i]->invalid;
        }
        info = merge(info1, info2, root);
    }

    return info;
}

void solve(int root)
{
    Info * info = calc_info(root);
    if (main_s_output) {
        main_s_output = 0;
        fprintf(fout, "%d\n", info->s);
    }
    int u = info->av_start;
    int v = info->av_end;

    genstep('L', u, 0);
    while (1) {
        int next = -1;
        if (u!=v) {
            for (int i=0; i<deg[u]; ++i) {
                if (graph[u][i]->valid()) {
                    int x = graph[u][i]->other_from(u);
                    if (dist[x][v]+1==dist[u][v]) {
                        ++graph[u][i]->invalid;
                        next = x;
                        break;
                    }
                }
            }
            assert(next>=0);
        }

        for (int i=0; i<deg[u]; ++i) {
            ++graph[u][i]->invalid;
        }

        for (int i=0; i<deg[u]; ++i) {
            --graph[u][i]->invalid;
            if (graph[u][i]->valid()) {
                solve(u);
            }
            ++graph[u][i]->invalid;
        }

        for (int i=0; i<deg[u]; ++i) {
            --graph[u][i]->invalid;
        }

        if (next<0) {
            break;
        } else {
            genstep('M', u, next);
            u = next;
        }
    }
    genstep('B', v, 0);
}

int main()
{
    init();
    solve(0);
    output();

    return 0;
}

