/////////////////////////////////////////////////////////////////////////////
//
//	Filter for problem POST (IOI'2000,Beijing)
//
//	STANDARD file format:
//
//		Line 1: V P N (number of villages, number of posts,
//		               minimum sum of distance)
//		Line 2: X[1] ... X[V]
//
//	OUTPUT file format:
//
//		Line 1: N'
//		Line 2: Y'[1] .. Y'[P]
//
//	Evaluation:
//
//		value = 10, N' / N == 1.0
//		         5, N' / N in (1.0, 1.1]
//		         4, N' / N in (1.1, 1.15]
//		         3, N' / N in (1.15, 1.2]
//		         2, N' / N in (1.2, 1.25]
//		         1, N' / N in (1.25, 1.3]
//		         0, otherwise
//
//	Errors detected:
//
//		ERR_NUM_MISS     -- no N'
//		ERR_NUM_LARGER   -- N' > N * 1.3
//		ERR_NUM_SMALLER  -- N' < N
//		ERR_POST_MISS    -- no Y'[i]
//		ERR_NOT_INCRE    -- Y'[1..N] is not increasing
//		ERR_OUT_VILL     -- not exist X[j], X[j] == Y'[i]
//		ERR_SUM_LARGER   -- calculated sum of distances > N'
//		ERR_SUM_SMALLER  -- calculated sum of distances < N'
//
//	STANDARD overflow:
//
//		ERR_VILL_OVER    -- N > MAX_VILL
//		ERR_TYPE_OVER    -- T > MAX_TYPE

#include <stdio.h>
#include <stdlib.h>
#include "fpf.h"

#define ERR_NUM_MISS    "The sum of distances is missing\n"
#define ERR_NUM_LARGER  "The sum of distances is too much larger than the correct one\n"
#define ERR_NUM_SMALLER "The sum of distances is smaller than the correct one\n"
#define ERR_POST_MISS   "The position of No.%ld post office is missing\n"
#define ERR_NOT_INCRE   "Sequence of post office positions is not increasing\n"
#define ERR_OUT_VILL    "No.%ld post offices is not built in any village\n"
#define ERR_SUM_LARGER  "The sum of distances according to your sequence is larger than reported\n"
#define ERR_SUM_SMALLER "The sum of distances according to your sequence is smaller than reported\n"

#define ERR_VILL_OVER   "Number of villages overflow largest possible\n"
#define ERR_POST_OVER   "Number of posts overflow largest possible\n"
#define ERR_POST_UNDER  "Number of posts overflow smallest possible\n"

#define MAX_VILL       (long)400
#define MAX_POST       (long)30

int evaluate()
{
	long xVillage[MAX_VILL], xPost[MAX_POST];
	long nVillage, nPost, xOutSum, xAnsSum;
	long i, j;
	long xDist, xAnotherDist, xSum;
	double fRatio;

	//read V, P, N
	getint_std(&nVillage);
	getint_std(&nPost);
	getint_std(&xAnsSum);
	checkret_std();

	//verify V <= MAX_VILL and P <= MAX_POST
	if (nVillage > MAX_VILL)
		return fprintf(stderr, ERR_VILL_OVER);
	if (nPost > MAX_POST)
		return fprintf(stderr, ERR_POST_OVER);
	if (nPost < 1)
		return fprintf(stderr, ERR_POST_UNDER);

	//read N'
	if (!getint_out(&xOutSum))
		return fprintf(stderr, ERR_NUM_MISS);
	if (!checkret_out()) return 0;

	//read X[1..V]
	for (i = 0; i < nVillage; i++)
		getint_std(&xVillage[i]);

	//read Y'[1..P], the post positions
	j = 0;
	for (i = 0; i < nPost; i++)
	{
		//read Y'[i+1]
		if (!getint_out(&xPost[i]))
			return fprintf(stderr, ERR_POST_MISS, i + 1);

		//check if increasing
		if (i != 0 && xPost[i] <= xPost[i - 1])
			return fprintf(stderr, ERR_NOT_INCRE);

		//search X[j+1] >= Y'[i+1]
		for (; j < nVillage && xVillage[j] < xPost[i]; j++);

		//check if built in any village
		if (xVillage[j] != xPost[i])
			return fprintf(stderr, ERR_OUT_VILL, i + 1);
	}

	//calculate xSum, the sum of distance according to post positions
	xSum = 0;
	j = 0;
	for (i = 0; i < nVillage; i++)
	{
		//calculate xDist, distance from village (i+1) to the nearest post
		for (; j < nPost && xPost[j] < xVillage[i]; j++);
		if (j != nPost)
			xDist = abs(xPost[j] - xVillage[i]);
		else
			xDist = abs(xVillage[i] - xPost[nPost - 1]);
		if (j != 0 && (xAnotherDist = abs(xVillage[i] - xPost[j - 1])) < xDist)
			xDist = xAnotherDist;

		//accumulate to xSum
		xSum += xDist;
	}

	//compare xSum and N'
	if (xSum > xOutSum)
		return fprintf(stderr, ERR_SUM_LARGER);
	else if (xSum < xOutSum)
		return fprintf(stderr, ERR_SUM_SMALLER);

	//check extra data
	if (!checkret_out()) return 0;
	if (!checkeof_out()) return 0;

	//assign value
	//compare N' and N
	if (xSum < xAnsSum)
		return fprintf(stderr, ERR_NUM_SMALLER);
	else if (xSum == xAnsSum)
		value = 10;
	else
	{
		fRatio = xSum * 1.0 / xAnsSum;
		if (fRatio <= 1.1)
			value = 5;
		else if (fRatio <= 1.15)
			value = 4;
		else if (fRatio <= 1.2)
			value = 3;
		else if (fRatio <= 1.25)
			value = 2;
		else if (fRatio <= 1.3)
			value = 1;
		else
			return fprintf(stderr, ERR_NUM_LARGER);
	}

	return 1;
}

int main(int argc, char **argv)
{
	if (init(argc, argv))
		evaluate();
	finish();
	return 0;
}
