#include <assert.h>
#include <stdio.h>
#include <memory.h>

typedef struct mp_t {
	unsigned int limb[50];
	unsigned len;
} MP;

void mp_init(struct mp_t *n);
void mp_add(const struct mp_t *a, const struct mp_t *b, struct mp_t *c);
void mp_mul(const struct mp_t *a, const int b, struct mp_t *c);
void mp_div(const struct mp_t *a, const int b, struct mp_t *c);

int g_k, g_w;

int main(int argc, char *argv[])
{
	FILE *fin, *fout;
	int i, j, k, l, x, y, m;
	struct mp_t r, a, b;
	
	fin = fopen("digital.in", "r");
	assert(fin != NULL);
	fscanf(fin, "%d %d", &g_k, &g_w);
	fclose(fin);
	
	if (g_w / g_k >= (1 << g_k)) {
		g_w = ((1 << g_k) - 1) * g_k;
	}

	mp_init(&r);
	m = (1 << g_k) - 1;
	a.len = 1;
	a.limb[0] = m;
	for (l = 2; l <= g_w / g_k; l++) {
		m--;
		mp_mul(&a, m, &a);
		mp_div(&a, l, &a);
		mp_add(&r, &a, &r);
	}
	
	l = g_w / g_k;
	if ((g_w % g_k) > 0) {
		k = (1 << (g_w % g_k)) - 1;
		x = (1 << g_k) - (1 << (g_w % g_k));
		y = x - l + 1;
		
		while (x < l) {
			x++;
			y++;
			k--;
		}
		m = x;
		
		a.len = 1;
		a.limb[0] = m;
		for (i = 1; i < l; i++) {
			m--;
			mp_mul(&a, m, &a);
		}
		for (i = 2; i <= l; i++) {
			mp_div(&a, i, &a);
		}
		mp_add(&r, &a, &r);
		
		k--;
		while (k > 0) {
			x++;
			mp_mul(&a, x, &a);
			mp_div(&a, y, &a);
			y++;
			mp_add(&r, &a, &r);
			k--;
		}
	}
	
	fout = fopen("digital.out", "w");
	fprintf(fout, "%d", r.limb[r.len - 1]);
	for (i = r.len - 2; i >= 0; i--) {
		fprintf(fout, "%04d", r.limb[i]);
	}
	fprintf(fout, "\n");
	fclose(fout);

    return 0;
}

void mp_init(struct mp_t *n)
{
	n->len = 1;
	n->limb[0] = 0;
}

void mp_add(const struct mp_t *a, const struct mp_t *b, struct mp_t *c)
{
	int k = 0;
	int i;
	
	for (i = 0; i < a->len && i < b->len; i++) {
		k += a->limb[i] + b->limb[i];
		c->limb[i] = k % 10000;
		k /= 10000;
	}
	while (i < b->len) {	/* we still have limbs in b */
		k += b->limb[i];
		c->limb[i] = k % 10000;
		k /= 10000;
		i++;
	}
	while (i < a->len) {	/* we still haev limbs in a */
		k += a->limb[i];
		c->limb[i] = k % 10000;
		k /= 10000;
		i++;
	}
	
	if (k != 0) {
		c->limb[i] = k;
		i++;
	}
	
	c->len = i;
}


void mp_mul(const struct mp_t *a, const int b, struct mp_t *c)
{
	int i, k;
	
	k = 0;
	for (i = 0; i < a->len; i++) {
		k += a->limb[i] * b;
		c->limb[i] = k % 10000;
		k /= 10000;
	}
	while (k != 0) {
		c->limb[i] = k % 10000;
		k /= 10000;
		i++;
	}
	c->len = i;
}

void mp_div(const struct mp_t *a, const int b, struct mp_t *c)
{
	int i, k;
	
	k = 0;
	for (i = a->len - 1; i >= 0; i--) {
		k *= 10000;
		k += a->limb[i];
		c->limb[i] = k / b;
		k = k % b;
	}
	i = a->len - 1;
	while (c->limb[i] == 0) i--;
	c->len = i + 1;
}
