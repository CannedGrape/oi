#include "stdio.h"
#include "math.h"
#include "string.h"
#include "unistd.h"
#include "stdlib.h"

#define EVAL_OUTPUT_FILE "/tmp/_eval.score"

FILE *fpout, *fpans, *fpeval;
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
void open_files(char *out, char *ans, char *eval_output)
{
	if ((fpeval = fopen (eval_output, "w")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", EVAL_OUTPUT_FILE);
		output ("Can not open eval record file!", 0);
	}

	if ((fpout = fopen (out, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", out);
		output ("Can not open player's output file!", 0);
	}

	if ((fpans = fopen (ans, "r")) == NULL) {
		fprintf (stderr, "Can not open %s!\n", ans);
		output ("Can not open standard answer!", 0);
	}
}

int main (int argc, char *argv[])
{
	double d1 = -1, d2 = -1;
	int error;
		
	if (argc != 4) {
		fprintf (stderr, "Usage: cash_e <in> <out> <ans>\n");
		output ("Invalid Call!", 0);
	}

	open_files (argv[2], argv[3], EVAL_OUTPUT_FILE);


	/* Compare the contens */
        
	while (1) {
		d1 = d2 = -1;
		fscanf(fpout, "%lf", &d1);
		fscanf(fpans, "%lf", &d2);

		if (fabs(d1 - d2) > 0.00101) {
			error = 1;
			break;
		}

		if (feof(fpout) && feof(fpans)) {
			error = 0;
			break;
		}

	}

	/* Compare the contens */

	if (error)
		output ("Contestant's number differs with the answer!", 0);
	else
		output("Right output!!!", 10);

	return 0;
}
