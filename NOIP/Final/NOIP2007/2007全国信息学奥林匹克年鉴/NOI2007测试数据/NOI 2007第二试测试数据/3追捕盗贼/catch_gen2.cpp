#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
using namespace std;

#define MAXN 2000
#define MAXS 7

struct Tree {
    int n;
    int edge[MAXN+1][2];
    int deg[MAXN+1];
};

Tree tree[MAXS+1][2000];

void printtree(Tree * t)
{
    printf("%d\n", t->n);
    for (int i=0; i<t->n; ++i) {
        printf("%d ", t->deg[i]);
    }
    printf("\n");
    for (int i=0; i<t->n-1; ++i) {
       printf("%d %d  ", t->edge[i][0], t->edge[i][1]);
    }
    printf("\n");
}
 
void calc_deg(Tree * t)
{
    memset(&t->deg, 0, sizeof(t->deg));
    for (int i=0; i<t->n-1; ++i) {
        ++t->deg[t->edge[i][0]];
        ++t->deg[t->edge[i][1]];
    }
}

void combine(Tree * main, int joint, Tree * sub)
{
    assert(sub->n>=2);

    int sub_joints[MAXN+1];
    int subj_num = 0;
    for (int i=0; i<sub->n; ++i) {
        if (sub->deg[i]==1) {
            sub_joints[subj_num++] = i;
        }
    }

    if (subj_num<2) {
        printtree(sub);
    }
    assert(subj_num>=2);

    int sub_joint = sub_joints[rand()%subj_num];
    int trans[MAXN+1];
    trans[sub_joint] = joint;
    
    int index = main->n;
    for (int i=0; i<sub->n; ++i) {
        if (i != sub_joint) {
            trans[i] = index++;
        }
    }
/*    printf("trans:");
    for (int i=0; i<sub->n; ++i) {
        printf(" %d", trans[i]);
    }
    printf("tran\n");*/

    index = main->n-1;
    for (int i=0; i<sub->n-1; ++i) {
        main->edge[index][0] = trans[sub->edge[i][0]];
        main->edge[index][1] = trans[sub->edge[i][1]];
        ++index;
    }

    main->n += sub->n-1;

    // No calc_deg!
    // Remember to do final calc_deg when all sub-trees combined!
}

int maxsize[MAXS+1] =
{
    0,
    2,
    4,
    10,
    28,
    82,
    244,
    730
};

const int treenum[MAXS+1] =
{
    0,
    100,
    200,
    500,
    1000,
    1000,
    1000,
    2000
};

int minsize[MAXS+1];
   
void init()
{
    for (int i=0; i<treenum[1]; ++i) {
        int n = 2+rand()%(maxsize[1]-1);
        tree[1][i].n = n;
        for (int j=0; j<n-1; ++j) {
            tree[1][i].edge[j][0] = j;
            tree[1][i].edge[j][1] = j+1;
        }
        calc_deg(&tree[1][i]);
    }
}

Tree * pick(int size, int start, int end)
{
    Tree * t;
    assert(minsize[start]<=size);
    do {
        int i = start+rand()%(end-start+1);
        t = &tree[i][rand()%treenum[i]];
    } while (t->n>size);
    return t;
}

void check(Tree * t);

void gen(int s, Tree * t)
{
    Tree * sub;
    t->n = 1;
    for (int i=0; i<3; ++i) {
        sub = pick(maxsize[s-1], s-1, s-1);
        //printf("combining...\n");
        //printtree(sub);
        combine(t, 0, sub);
        //printtree(t);
        //check(t);
        //printf("combined\n");
        assert(t->n<=maxsize[s]);
    }

    int av_len = 1 + rand()%(maxsize[s]-t->n+1);
    int pos = rand()%av_len;
    int index = t->n-1;
    int joints[MAXN+1];
    
    int u, v;
    //printf("t->n=%d pos=%d\n", t->n, pos);
    for (int i=0; i<av_len-1; ++i) {
        if (i<pos) {
            u = t->n+i;
        } else if (i==pos) {
            u = 0;
        } else {
            u = t->n+i-1;
        }
        if (i+1<pos) {
            v = t->n+i+1;
        } else if (i+1==pos) {
            v = 0;
        } else {
            v = t->n+i;
        }
        joints[i]=u;

        t->edge[index][0] = u;
        t->edge[index][1] = v;
        ++index;
    }
    //printf("v=%d\n", v);
    if (av_len>1) {
        joints[av_len-1] = v;
    } else {
        joints[0] = 0;
    }
    /*printf("av: len=%d", av_len);
    for (int i=0; i<av_len; ++i) {
        printf(" %d", joints[i]);
    }*/

    //printf("\n");

    //printtree(t);

    t->n += av_len-1;
    assert(t->n<=maxsize[s]);

    int rest = rand()%(maxsize[s]-t->n+1);
    //printf("rest=%d\n", rest);
    while (rest>1) {
        int end = 0;
        for (int i=s-1; i>0; --i) {
            if (minsize[i]<=rest) {
                end = i;
                break;
            }
        }
        if (end==0) {
            break;
        }
        if (end<s-1) {
            ++end;
        }
        sub = pick(rest+1, 1, end);
        int joint = joints[rand()%av_len];
        
        //printf("joint=%d\n", joint);
        combine(t, joint, sub);
        //printtree(t);
        assert(t->n <= maxsize[s]);
        rest -= sub->n-1;
    }

    calc_deg(t);
    //printf("checking n=%d\n", t->n);
    //printtree(t);
    check(t);
    //printf("done\n");
}

int visit[MAXN+1];
int map[MAXN+1][MAXN+1];

void dfs(int u, int n)
{
    assert(!visit[u]);
    visit[u] = 1;
    for (int v=0; v<n; ++v) {
        if (map[u][v]) {
            map[u][v] = map[v][u] = 0;
            dfs(v, n);
        }
    }
}

void check(Tree * t)
{
    memset(visit, 0, sizeof(visit));
    memset(map, 0, sizeof(map));
    for (int i=0; i<t->n-1; ++i) {
        int u = t->edge[i][0];
        int v = t->edge[i][1];
        assert(u>=0 && u<t->n && v>=0 && v<t->n && u!=v);
        map[u][v] = map[v][u] = 1;
    }
    
    dfs(0, t->n);
    
    for (int i=0; i<t->n; ++i) {
        if (visit[i]==0) {
            printtree(t);
        }
        assert(visit[i]);
    }
}

void work(int maxs)
{
/*    maxsize[maxs] = 1000;
    for (int i=maxs-1; i>0; --i) {
        maxsize[i] = (maxsize[i+1]+2)/3;
    }*/
    init();
    for (int s=2; s<=maxs; ++s) {
        for (int i=0; i<treenum[s]; ++i) {
            gen(s, &tree[s][i]);
        }
        minsize[s] = tree[s][0].n;
        for (int i=1; i<treenum[s]; ++i) {
            if (tree[s][i].n < minsize[s]) {
                minsize[s] = tree[s][i].n;
            }
        }
        printf("minsize[%d]=%d\n", s, minsize[s]);
    }
}

void output(FILE * fout, int s)
{
    Tree * t = &tree[s][rand()%treenum[s]];
    fprintf(fout, "%d\n", t->n);
    for (int i=0; i<t->n-1; ++i) {
        fprintf(fout, "%d %d\n", t->edge[i][0]+1, t->edge[i][1]+1);
    }
    fclose(fout);
}

int main(int argc, char * argv[])
{
    srand(1110);

    FILE * fout = fopen(argv[1], "w");

    int s = atoi(argv[2]);
    work(s);
    output(fout, s);

    return 0;
}
