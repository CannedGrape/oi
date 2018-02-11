//////////////////////////////////////////////////////////////////////////////
//
//	Checker for problem PALIN (IOI'2000,Beijing)
//
//	OUTPUT file format:
//
//		Line 1: N'
//
//		ERR_NUM_MISS      -- no N'
//		ERR_NUM_LARGER    -- N' > MAX_INSERT (= MAX_NUM - 1)
//		ERR_NUM_SMALLER   -- N' < 0

#include <stdio.h>
#include <stdlib.h>
#include "fpf.h"

#define ERR_NUM_MISS     "Minimum number is missing\n"
#define ERR_NUM_LARGER   "Your number is larger than max possible value, 4999\n"
#define ERR_NUM_SMALLER  "Your number is smaller than zero\n"

#define MAX_NUM      (long)5000

#define MAX_INSERT   (MAX_NUM - 1)

int evaluate()
{
	long nData;

	//read N'
	if (!getint_out(&nData))
		return printf(ERR_NUM_MISS);

	//check 0 <= N' <= MAX_INSERT
	if (nData > MAX_INSERT)
		return printf(ERR_NUM_LARGER, MAX_INSERT);
	else if (nData < 0)
		return printf(ERR_NUM_SMALLER, 0);

	//check extra data
	if (!checkret_out()) return 0;
	if (!checkeof_out()) return 0;

	//assign value
	ok = 1;
	return 1;
}

int main(int argc, char **argv)
{
	if (init(argc, argv, "PALIN"))
		evaluate();
	finish();
	return 0;
}
