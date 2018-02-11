#include <assert.h>
#include <stdio.h>
#include <limits.h>
#include <malloc.h>

typedef struct timegap_t {
	int start, end;
	struct timegap_t * next;
} TIMEGAP;

struct timegap_t * mtime[20];
int last[20];
int proc[20][20][2];	/* (machine, time) */
int curr[20];	/* current proc */
int seq[400];
int m, n;

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	int i, j;
	struct timegap_t *p, *tmp;
	
	fin = fopen("jsp.in", "r");
	fscanf(fin, "%d %d", &m, &n);
	for (i = 0; i < m * n; i++) {
		fscanf(fin, "%d", &seq[i]);
		seq[i]--;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			fscanf(fin, "%d", &proc[i][j][0]);
			proc[i][j][0]--;
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			fscanf(fin, "%d", &proc[i][j][1]);
		}
	}
	fclose(fin);
	
	/* initialize */
	for (i = 0; i < m; i++) {
		mtime[i] = malloc(sizeof(struct timegap_t));
		mtime[i]->start = 0;
		mtime[i]->end = INT_MAX;
		mtime[i]->next = NULL;
	}
	for (i = 0; i < n; i++) {
		curr[i] = 0;
		last[i] = 0;
	}
	
	/* simulate */
	for (i = 0; i < m * n; i++) {
		/* current obj = seq[i] */
		/* current proc = curr[seq[i]] */
		/* machine = proc[seq[i]][curr[seq[i]]][0] */
		/* time = proc[seq[i]][curr[seq[i]]][1] */
		
		/* find the 1st suitable time gap */
		p = mtime[proc[seq[i]][curr[seq[i]]][0]];
		do {
			if (p->start == p->end) {
				p = p->next;
				continue;
			}			
			if (p->start >= last[seq[i]] && p->end - p->start >= proc[seq[i]][curr[seq[i]]][1]) {
				break;
			}			
			if (p->start < last[seq[i]] && p->end - last[seq[i]] >= proc[seq[i]][curr[seq[i]]][1]) {
				break;
			}						
			p = p->next;
		} while (p != NULL);
		assert (p != NULL);
		
		/* separate the time gap */
		if (p->start >= last[seq[i]]) {
			p->start += proc[seq[i]][curr[seq[i]]][1];

			last[seq[i]] = p->start;
			curr[seq[i]]++;
		}
		
		if (p->start < last[seq[i]]) {
			tmp = malloc(sizeof(struct timegap_t));
			tmp->start = last[seq[i]] + proc[seq[i]][curr[seq[i]]][1];
			tmp->end = p->end;
			tmp->next = p->next;
			p->next = tmp;
			p->end = last[seq[i]];

			last[seq[i]] += proc[seq[i]][curr[seq[i]]][1];
			curr[seq[i]]++;
		}
	}
	
	j = 0;
	for (i = 0; i < n; i++) {
		if (last[i] > j) j = last[i];
	}
	
	fout = fopen("jsp.out", "w");
	fprintf(fout, "%d\n", j);
	fclose(fout);
	
	/* free all links */
	for (i = 0; i < m; i++) {
		p = mtime[i];
		while (p != NULL) {
			tmp = p;
			p = p->next;
			free(tmp);
		}
	}

    return 0;
}
