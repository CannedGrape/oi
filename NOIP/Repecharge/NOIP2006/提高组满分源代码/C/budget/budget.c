#include <assert.h>
#include <stdio.h>

typedef struct object_t {
	int price;
	int weight;
	int sub;
	int sub_price[2];
	int sub_weight[2];
	int total;
} OBJECT;

int p = 0;
int g_N;
int f[60][3201];
struct object_t objs[60];

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	int i, j, k, l, m, n; /* m also used as max */
	int index[60];
	
	fin = fopen("budget.in", "r");
	assert(fin != NULL);
	
	fscanf(fin, "%d", &g_N);
	g_N /= 10;
	fscanf(fin, "%d", &m);
	for (i = 0; i < m; i++) {
		fscanf(fin, "%d %d %d", &j, &k, &l);
		if (l == 0) {	/* main object */
			objs[p].price = j / 10;
			objs[p].weight = j / 10 * k;
			objs[p].sub = 0;
			objs[p].sub_price[0] = objs[p].sub_price[1] = 0;
			objs[p].sub_weight[0] = objs[p].sub_weight[1] = 0;
			objs[p].total = j / 10;
			index[i] = p;
			p++;
		}
		else {
			l--;
			objs[index[l]].sub_price[objs[index[l]].sub] = j / 10;
			objs[index[l]].sub_weight[objs[index[l]].sub] = j / 10 * k;
			objs[index[l]].total += j / 10;
			objs[index[l]].sub++;
		}
	}
	for (i = 0; i < p; i++) objs[p].sub = 2;	
	fclose(fin);
	
	for (i = 0; i <= g_N; i++) {
		if (i >= objs[0].total) {
			m = objs[0].weight;
			if (objs[0].sub >= 1) m += objs[0].sub_weight[0];
			if (objs[0].sub == 2) m += objs[0].sub_weight[1];
			for (j = i; j <= g_N; j++) {
				f[0][j] = m;				
			}
			break;
		}
		
		if (i < objs[0].price) {
			f[0][i] = 0;
			continue;
		}

		m = 0;
		for (j = 0; j <= 3; j++) {
			k = objs[0].sub_weight[0] * (j >> 1) + objs[0].sub_weight[1] * (j & 1);
			if ((k > m) && (objs[0].sub_price[0] * (j >> 1) + objs[0].sub_price[1] * (j & 1) + objs[0].price <= i)) {
				m = k;
			}
		}
		f[0][i] = objs[0].weight + m;
	}
	
	for (l = 1; l < p; l++) {
		for (i = 0; i <= g_N; i++) {
			m = f[l - 1][i];

			for (j = 0; j <= 3; j++) {
				n = objs[l].sub_price[0] * (j >> 1) + objs[l].sub_price[1] * (j & 1) + objs[l].price;
				if (n > i) continue;
				k = objs[l].sub_weight[0] * (j >> 1) + objs[l].sub_weight[1] * (j & 1) + objs[l].weight + f[l - 1][i - n];		
				if (k > m) m = k;
			}
								
			f[l][i] = m;
		}
	}
	
	fout = fopen("budget.out", "w");
	fprintf(fout, "%d\n", f[p - 1][g_N] * 10);
	fclose(fout);
	
	return 0;
}
