/////////////////////////////////////////////////////////////////////////////
//
//	Filter for problem BLOCKS (IOI'2000,Beijing)
//
//	STANDARD file format:
//
//		Line 1: N (minimum number of blocks)
//		Line 2: M (number of solutions)
//		Line 3..(M+2): P[1] ... P[N] (sequence of blocks for each solution)
//
//	OUTPUT file format:
//
//		Line 1: N'
//		Line 2: P'[1] ... P'[N] (unnecessary to be non-decreasing)
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
//		ERR_LESS_BLOCK  -- no P'[i]
//		ERR_MORE_BLOCK  -- exist P'[N+1]
//		ERR_NO_MATCH    -- (all P in STANDARD) P != P', namely P' is a wrong solution
//
//	STANDARD overflow:
//
//		ERR_NUM_OVER    -- N > MAX_NUM

#include <stdio.h>
#include <stdlib.h>
#include "fpf.h"

#define ERR_NUM_MISS    "The number of blocks is missing\n"
#define ERR_NUM_LARGER  "The number of blocks is larger than the minimum one\n"
#define ERR_NUM_SMALLER "The number of blocks is smaller than the minimum one\n"
#define ERR_LESS_BLOCK  "Less blocks in the sequence\n"
#define ERR_MORE_BLOCK  "More blocks in the sequence\n"
#define ERR_NO_MATCH    "Your solution is not match to any possible solution\n"

#define ERR_NUM_OVER    "Minimum number of blocks overflows largest possible\n"

#define MAX_NUM	(long)50

int evaluate()
{
	long nNumber, nSolNum;
	long nStd, nOut;
	long aOutSeq[MAX_NUM];
	int bMatch;
	long i, j;

	//read N
	getint_std(&nNumber);
	checkret_std();

	//verify N <= MAX_NUM
	if (nNumber > MAX_NUM)
		return fprintf(stderr, ERR_NUM_OVER);

	//read N'
	if (!getint_out(&nOut))
		return fprintf(stderr, ERR_NUM_MISS);
	if (!checkret_out()) return 0;

	//compare N and N'
	if (nOut > nNumber)
		return fprintf(stderr, ERR_NUM_LARGER);
	else if (nOut < nNumber)
		return fprintf(stderr, ERR_NUM_SMALLER);

	//read OUTPUT sequence P'
	for (i = 0; i < nNumber; i++)
	{
		//read P'[i+1]
		if (!getint_out(&nOut))
			return fprintf(stderr, ERR_LESS_BLOCK);
		aOutSeq[i] = nOut;
	}

	//sort sequence P'
	for (i = 0; i < nNumber - 1; i++)
	for (j = i + 1; j < nNumber; j++)
	if (aOutSeq[i] > aOutSeq[j])
	{
		nOut = aOutSeq[i];
		aOutSeq[i] = aOutSeq[j];
		aOutSeq[j] = nOut;
	}

	//read M
	getint_std(&nSolNum);
	checkret_std();

	//find match solution in P of STANDARD
	for (i = 0; i < nSolNum; i++)
	{
		//check if P match the line (i+1)
		bMatch = 1;
		for (j = 0; j < nNumber; j++)
		{
			//read P[j+1]
			getint_std(&nStd);

			//if P[j+1] != P'[j+1], stop matching this line
			if (nStd != aOutSeq[j])
			{
				bMatch = 0;
				break;
			}
		}

		//skip STANDARD line
		while (!iseoln_std())
			getchar_std();
		checkret_std();

		//matched
		if (bMatch)
			break;
	}

	//not match
	if (!bMatch)
		return fprintf(stderr, ERR_NO_MATCH);

	//check extra data
	if (!checkret_out())
		return fprintf(stderr, ERR_MORE_BLOCK);
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
