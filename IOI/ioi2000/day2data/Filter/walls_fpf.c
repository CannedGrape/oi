/////////////////////////////////////////////////////////////////////////////
//
//	Filter for problem WALLS (IOI'2000,Beijing)
//
//	STANDARD file format:
//
//		Line 1: N (minimum number of walls)
//		Line 2: M (number of solutions)
//		Line 3..(M+2): P (optimal area for each solution)
//
//	OUTPUT file format:
//
//		Line 1: N'
//		Line 2: P'
//
//	Evaluation:
//
//		value = 10 or 0
//
//	Errors detected:
//
//		ERR_NUM_MISS    -- no N'
//		ERR_NUM_LARGER  -- N' > N
//		ERR_NUM_SMALLER -- N' < N
//		ERR_AREA_MISS   -- no P'
//		ERR_NO_MATCH    -- (all P in STANDARD) P != P', namely P' is a wrong area

#include <stdio.h>
#include <stdlib.h>
#include "fpf.h"

#define ERR_NUM_MISS    "The number of walls is missing\n"
#define ERR_NUM_LARGER  "The number of walls is larger than the minimum one\n"
#define ERR_NUM_SMALLER "The number of walls is smaller than the minimum one\n"
#define ERR_AREA_MISS   "Optimal area label is missing\n"
#define ERR_NO_MATCH    "Your area is not match to any possible solution\n"

int evaluate()
{
	long nNumber, nSolNum;
	long nStd, nOut;
	int bMatch;
	long i;

	//read N
	getint_std(&nNumber);
	checkret_std();

	//read N'
	if (!getint_out(&nOut))
		return fprintf(stderr, ERR_NUM_MISS);
	if (!checkret_out()) return 0;

	//compare N and N'
	if (nOut > nNumber)
		return fprintf(stderr, ERR_NUM_LARGER);
	else if (nOut < nNumber)
		return fprintf(stderr, ERR_NUM_SMALLER);

	//read P'
	if (!getint_out(&nOut))
		return fprintf(stderr, ERR_AREA_MISS);

	//read M
	getint_std(&nSolNum);
	checkret_std();

	//find match solution
	bMatch = 0;
	for (i = 0; i < nSolNum; i++)
	{
		//read P of line (i+1)
		getint_std(&nStd);
		checkret_std();

		//compare P and P'
		if (nStd == nOut)
		{
			bMatch = 1;
			break;
		}
	}

	//not match
	if (!bMatch)
		return fprintf(stderr, ERR_NO_MATCH);

	//check extra data
	if (!checkret_out()) return 0;
	if (!checkeof_out()) return 0;

	//assign value
	value = 10;
	return 1;
}

int main(int argc, char **argv)
{
	if (init(argc, argv))
		evaluate();
	finish();
	return 0;
}
