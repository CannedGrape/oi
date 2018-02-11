#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define EVAL_OUTPUT_FILE "/tmp/_eval.score"

FILE *fpout, *fpin, *fpans, *fpeval;
const			int				Limit				=			1000;

double A[Limit][Limit], max = 0;
int B[Limit][Limit];
int C, D, N, M;

/* Output message and exit */
void output (char *s, int d)
{
	if (fpeval) {
		fprintf (fpeval, "%s\n%d\n", s, d);
		fclose (fpeval);
	}
	exit(d != 0);
}

/* Open files and check */
void open_files(char *in, char *out, char *ans, char *eval_output)
{
	if ((fpin = fopen (in, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", in);
		output ("Can not open input file!", 0);
	}

	if ((fpeval = fopen (eval_output, "w")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", EVAL_OUTPUT_FILE);
		output ("Can not open eval record file!", 0);
	}

	if ((fpout = fopen (out, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", out);
		output ("Can not open contestant's output file!", 0);
	}

	if ((fpans = fopen (ans, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", ans);
		output ("Can not open standard answer!", 0);
	}
}

void work()
{
	if (C == 1)
	{
		for (int i = 0; i < N; i++)
		{
			double tmp = 0;
			for (int j = 0; j < M; j++)
			{
				tmp += A[i][j] - B[i][j];
			}
			if (tmp < 0) tmp = -tmp;
			if (tmp > max) max = tmp;
		}
		for (int j = 0; j < M; j++)
		{
			double tmp = 0;
			for (int i = 0; i < N; i++)
			{
				tmp += A[i][j] - B[i][j];
			}
			if (tmp < 0) tmp = -tmp;
			if (tmp > max) max = tmp;
		}
	}
	else
	{
		for (int i = 1; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				double tmp = B[i][j] + B[i][j - 1] + B[i - 1][j] + B[i - 1][j - 1]
						 - A[i][j] - A[i][j - 1] - A[i - 1][j] - A[i - 1][j - 1];
				if (tmp < 0) tmp = -tmp;
				if (tmp > max) max = tmp;
			}
		}
	}
}

double f_max(double a, double b)
{
	if (a < b)
		return b;
	else
		return a;
}

int main (int argc, char *argv[])
{
		
	if (argc != 4) {
		fprintf (stderr, "Usage: matrix_e <in> <out> <ans>\n");
		output ("Invalid Call!", 0);
	}

	open_files (argv[1], argv[2], argv[3], EVAL_OUTPUT_FILE);


	/* Compare the contens */
        
	fscanf(fpin, "%d%d%d%d", &C, &D, &N, &M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int tmp;
			fscanf(fpin, "%d", &tmp);
			A[i][j] = tmp * 1.0 / D;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (fscanf(fpout, "%d", &B[i][j]) != 1)
			{
				output("Invalid output file format: not enough integers", 0);
			}
			if (B[i][j] != 0 && B[i][j] != 1)
			{
				output("Invalid output file format: not a 0-1 matrix", 0);
			}
		}
	}

	work();

	char s[1000];
	sprintf(s, "Correct answer, p_%d = %.6lf", C, max);

	int score;
	if (C == 1)
	{
		score = int(round(fmax(1.5 - fmax(max, 1), 0) * 20));
	}
	else
	{
		score = int(round(fmax(2 - fmax(max, 1.5), 0) * 20));
	}

	output(s, score);
	return 0;
}
