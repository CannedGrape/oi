#include <stdio.h>
#include <string.h>

#define SCORE_FILE "/tmp/_eval.score"

#define MAXN 2000

int n;
int adj[MAXN+1][MAXN+1], map[MAXN+1][MAXN+1], deg[MAXN+1], clear[MAXN+1][MAXN+1];
int s, count[MAXN+1];

int standard, score;
char message[1024];

void dfs_corrupt(int v)
{
    for (int i=0; i<n; ++i) {
        int u = map[v][i];
        if (clear[v][u]) {
            clear[u][v] = clear[v][u] = 0;
            if (count[u] == 0) {
                dfs_corrupt(u);
            }
        }
    }
}

void init(const char * fin_name, const char * fans_name)
{
    FILE * fscore = fopen(SCORE_FILE, "w");
    fprintf(fscore, "Internal Error\n");
    fprintf(fscore, "0\n");
    fclose(fscore);

    FILE * fin = fopen(fin_name, "r");
    memset(deg, 0, sizeof(deg));
    memset(adj, 0, sizeof(adj));
    memset(clear, 0, sizeof(clear));
    memset(count, 0, sizeof(count));

    fscanf(fin, "%d", &n);
    for (int i=0; i<n-1; ++i) {
        int u, v;
        fscanf(fin, "%d%d", &u, &v);
        --u;
        --v;
        adj[u][v] = adj[v][u] = 1;
        map[u][deg[u]++] = v;
        map[v][deg[v]++] = u;
    }
    fclose(fin);

    s = 0;
    score = 0;

    FILE * fans = fopen(fans_name, "r");
    fscanf(fans, "%d", &standard);
    fclose(fans);
}

void move(int u, int v)
{
    --count[u];
    if (v>=0) {
        ++count[v];
    }
    
    if (count[u]>0) {
        if (v>=0) {
            clear[u][v] = clear[v][u] = 1;
        }
    } else {
        int flag = 0;
        for (int i=0; i<deg[u]; ++i) {
            int w = map[u][i];
            if (w!=v && !clear[u][w]) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            dfs_corrupt(u);
        } else {
            if (v>=0) {
                clear[u][v] = clear[v][u] = 1;
            }
        }
    }
}

int getchar(FILE * fout, char * ch)
{
    int c;
    do {
        c = fgetc(fout);
    } while (!feof(fout) && !(c>='a' && c<='z' || c>='A' && c<='Z'));
    if (c>='a' && c<='z' || c>='A' && c<='Z') {
        *ch = c;
        return 1;
    }

    return 0;
}

void check(const char * fout_name)
{
    score = 0;
    
    FILE * fout = fopen(fout_name, "r");

    if (!fout) {
        score = 0;
        strcpy(message, "No Output!");
        return;
    }

    int S, T;
    int maxs = 0;
    
    if (fscanf(fout, "%d", &S)!=1 || S<1) {
        strcpy(message, "Output format error on S!");
        return;
    }

    if (fscanf(fout, "%d", &T)!=1 || T<0) {
        strcpy(message, "Output format error on T!");
        return;
    }

    if (T>20000) {
        strcpy(message, "Output error! Too many steps");
        return;
    }

    for (int step=1; step<=T; ++step) {
        char cmd;
        int u, v;
        if (!getchar(fout, &cmd) ||
            (cmd!='L' && cmd!='B' && cmd!='M')) {
            sprintf(message, "Output format error on step %d!", step);
            return;
        }
        switch(cmd) {
            case 'L':
                if (fscanf(fout, "%d", &u)!=1 || u<1 || u>n) {
                    sprintf(message, "Output format error on step %d!", step);
                    return;
                }
                --u;
                ++count[u];
                ++s;
                if (s>maxs) {
                    maxs = s;
                }
                break;
            case 'B':
                if (fscanf(fout, "%d", &u)!=1 || u<1 || u>n) {
                    sprintf(message, "Output format error on step %d!", step);
                    return;
                }
                --u;
                if (count[u]>0) {
                    move(u, -1);
                    --s;
                } else {
                    sprintf(message, "Command error on step %d! City %d has no detective to back off", step, u+1);
                    return;
                }
                break;
            case 'M':
                if (fscanf(fout, "%d%d", &u, &v)!=2 || 
                    u<1 || u>n || v<1 || v>n) {
                    sprintf(message, "Output format error on step %d!", step);
                    return;
                }
                --u;
                --v;
                if (count[u]>0 && adj[u][v]) {
                    move(u,v);
                } else {
                    sprintf(message, "Command error on step %d! Can't move from City %d to City %d", step, u+1, v+1);
                    return;
                }
                break;
            default:
                strcpy(message, "Internal error!");
                return;
        }
    }

    if (maxs>S) {
        strcpy(message, "Wrong Answer! More than S detectives must be used (Are you cheating?)");
        return;
    }

    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if (adj[i][j] && !clear[i][j]) {
                sprintf(message, "Wrong Answer! Frank may be on road between City %d and %d", i+1, j+1);
                return;
            }
        }
    }

    if (S<standard) {
        strcpy(message, "Fatastic!");
        score = 12;
        return;
    } else if (S==standard) {
        strcpy(message, "Excellent!");
        score = 10;
    } else if (S<=standard+2) {
        strcpy(message, "Good!");
        score = 6;
    } else if (S<=standard+4) {
        strcpy(message, "Good!");
        score = 4;
    } else if (S<=standard+8) {
        strcpy(message, "Good!");
        score = 2;
    } else {
        strcpy(message, "Pass!");
        score = 1;
    }
}

void output(const char * fscore_name)
{
    FILE * fscore = fopen(fscore_name, "w");

    fprintf(fscore, "%s\n%d\n", message, score);

    fclose(fscore);
}

int main(int argc, char * argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s input output answer\n", argv[0]);
        return 1;
    }

    init(argv[1], argv[3]);
    check(argv[2]);
    output(SCORE_FILE);

    return 0;
}

