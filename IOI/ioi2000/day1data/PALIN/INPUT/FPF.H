/////////////////////////////////////////////////////////////////////////////
//
//	Filter Program Format header file (IOI'2000,Beijing)
//
//		FORMAT CHECKER VERSION
//
//	DESCRIPTION:
//
//		the Format Checker programs must include this file,
//		the compiled executable file should be run as follow syntax:
//
//			<executable file> <output_file>
//
//		output file is the file generated from contestant's program,
//		referred as OUTPUT hereafter,
//
//		for example:
//
//			my_fpf problem1_2.out
//
//	Variables contained:
//
//		ok -- evaluate result, whether OUTPUT is ok
//
//	Functions contained:
//
//		init          -- init evaluation
//		finish        -- finish and print value  
//		getint_out    -- get integer from OUTPUT
//		checkret_out  -- verify end-of-line in OUTPUT
//		checkeof_out  -- verify end-of-file in OUTPUT
//		iseoln_out    -- whether OUTPUT is end-of-line now
//		getchar_out   -- get single character from OUTPUT, not used yet
//
//	USAGE:
//
//		include this file first:
//
//			#include "fpf.h"
//
//		write a main program as follow:
//		where "DUMMY" is your problem's name in the title
//
//			int main(int argc, char **argv)
//			{
//				if (init(argc, argv, "DUMMY"))
//					evaluate();
//				finish();
//				return 0;
//			}
//
//		then write a function named 'evaluate' before main
//
//			int evaluate()
//			{
//				//manipulation
//				...
//
//				//verify the OUTPUT has no extra data
//				if (!checkeof_out()) return 0;
//
//				//assign value the evaluation result
//				ok = 1;
//
//				//return
//				return 1;
//			}
//
//		the following is an example for evaluation where you
//		can learn some basic skills for using the header file
//
//		int evaluate()
//		{
//			//OUTPUT's answer
//			long nForTest;
//
//			//read from OUTPUT an integer
//			if (!getint_out(&nForTest))
//
//			//if failed to read, error message has been displayed
//			//however you can show your specific error here before quitting
//				return printf("Data missing");
//
//			//check the range of the integer
//			if (nForTest < 1 || nForTest > 10000)
//
//			//if out-of-range, show error and quit
//				return printf("Data out of range");
//
//			//verify that there should be a 'return' after the number in OUTPUT
//			if (!checkret_out())
//
//			//error has already been shown, just quit here
//				return 0;
//
//			//verify the OUTPUT has no extra data
//			if (!checkeof_out()) return 0;
//
//			//give the mark
//			ok = 1;
//
//			//return
//			return 1;
//		}
//
//	Errors detecting:
//
//		ERR_PARM        -- OUTPUT and STANDARD file name is missing
//		ERR_OPEN        -- OUTPUT or STANDARD file cannot be read
//
//		ERR_EOF         -- end-of-file reached when reading data
//		ERR_LINE_EXTRA  -- more data after expected in a line
//		ERR_FILL_EXTRA  -- more lines after expected in a file
//
//		ERR_NON_DIGIT   -- non-digital character is found when reading number
//		ERR_LESS_INT    -- less integer than expected in a line
//		ERR_LESS_SPACE  -- lack of space between two elements
//		ERR_MORE_SPACE  -- more than one space when only one is required
//		ERR_TOO_BIG     -- integer exceed the maximum integer value
//
//	Infomation string:
//
//		INFO_HELP       -- help information
//		INFO_PASS       -- message shown when successfully passed all checking


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERR_PARAM      "Output filename required\n"
#define ERR_OPEN       "Cannot open file %s\n"

#define ERR_EOF        "Unexpected end-of-file at line %d\n"
#define ERR_LINE_EXTRA "Extra character found in line %d\n"
#define ERR_FILE_EXTRA "Extra lines found\n"

#define ERR_NON_DIGIT  "In line %d, non-digital character is found before No.%d integer\n"
#define ERR_LESS_INT   "In line %d, the No.%d integer is missing\n"
#define ERR_LESS_SPACE "In line %d, space before the No.%d integer is missing\n"
#define ERR_MORE_SPACE "In line %d, extra space is found before the No.%d integer\n"
#define ERR_TOO_BIG    "In line %d, the No.%d integer is overflow\n"

#define INFO_HELP      "\nUSAGE:\n    %s_F [-h] <filename>\nARGUMENTS:\n    -h         Display this help and exit\n    <filename> Output file to check\n"
#define INFO_PASS      "PASSED ..\nREMEMBER : THIS DOES NOT MEAN THAT YOUR SOLUTION IS CORRECT!\n"

//////////////////////////////////////////////////////////////////////
//
//	ok -- the evaluation mark
//
//	DESCRIPTION:
//
//		it is assign zero by default,
//		modify it in the evaluation or leave it as zero
//		the function 'finish' will show 'successful' information
//		if ok is not zero

int ok;

////////////////////////////////////////////////////////////////
//
//	INTERNAL USE

//OUTPUT
FILE *fpOut;

//the preread character of the file
int cOut;

//structure to record the context of the file
typedef struct FILECONTEXT_tag
{
	//whether it is at the beggining of a new line
	int bNewLine;
	//the line number
	int nLineCnt;
	//the index of integer of current line
	int nIntCnt;
} FILECONTEXT;
FILECONTEXT fcOut;

///////////////////////////////////////////////////////////////
//
//	init -- open files and initialize
//
//		argc[IN] -- argument count from main
//		argv[IN] -- argument varlist from main
//		szProblem[IN] -- the problem name in title
//
//	RETURN: non-zero when success, or zero when error found

int init(int argc, char **argv, char *szProblem)
{
	printf("IOI 2000 - Beijing China\n");
	printf("Output checker for problem %s\n\n", szProblem);
	ok = 0;
	fpOut = 0;
	if (argc != 2)
	{
		printf(ERR_PARAM);
		printf(INFO_HELP, szProblem);
	}
	else if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "-H"))
		printf(INFO_HELP, szProblem);
	else if (!(fpOut = fopen(argv[1], "rb")))
		printf(ERR_OPEN, argv[1]);
	else
	{
		cOut = fgetc(fpOut);
		fcOut.bNewLine = 1;
		fcOut.nLineCnt = 1;
		fcOut.nIntCnt = 1;

		return 1;
	}
	return 0;
}

///////////////////////////////////////////////////////////////
//
//	finish -- print result and close files

void finish()
{
	if (ok)
		printf(INFO_PASS);
	if (fpOut)
		fclose(fpOut);
}

///////////////////////////////////////////////////////////////
//
//	nextchar -- get single character from file
//
//	INTERNAL USE

void nextchar(FILE *fpFile, int *pChar, FILECONTEXT *pFC)
{
	switch (*pChar)
	{
	case EOF:
		break;
	case 13:
		*pChar = fgetc(fpFile);
		if (*pChar == 10)
			*pChar = fgetc(fpFile);	// for CRLF
		pFC->bNewLine = 1;
		pFC->nLineCnt++;
		pFC->nIntCnt = 1;
		break;
	case 10:
		*pChar = fgetc(fpFile);	// for LINUX
		pFC->bNewLine = 1;
		pFC->nLineCnt++;
		pFC->nIntCnt = 1;
		break;
	default:
		*pChar = fgetc(fpFile);
		pFC->bNewLine = 0;
		break;
	}
}

///////////////////////////////////////////////////////////////
//
//	getint -- get an intger from a file
//
//	INTERNAL USE

int getint(FILE *fpFile, int *pChar, FILECONTEXT *pFC, long *pInt)
{
	if (!pFC->bNewLine)
	{
		if (*pChar == ' ')
		{
			nextchar(fpFile, pChar, pFC);
		}
		else
		{
			if (*pChar == 13 || *pChar == 10)
				printf(ERR_LESS_INT, pFC->nLineCnt, pFC->nIntCnt);
			else if (*pChar == EOF)
				printf(ERR_EOF, pFC->nLineCnt);
			else if (*pChar >= '0' && *pChar <= '9')
				printf(ERR_LESS_SPACE, pFC->nLineCnt, pFC->nIntCnt);
			else
				printf(ERR_NON_DIGIT, pFC->nLineCnt, pFC->nIntCnt);
			return 0;
		}
	}
	if (*pChar == '\n' || *pChar == '\r')
		printf(ERR_LESS_INT, pFC->nLineCnt, pFC->nIntCnt);
	else if (*pChar == EOF)
		printf(ERR_EOF, pFC->nLineCnt);
	else if (*pChar == ' ')
		printf(ERR_MORE_SPACE, pFC->nLineCnt, pFC->nIntCnt);
	else if ((*pChar < '0' || *pChar > '9') && *pChar != '+' && *pChar != '-')
		printf(ERR_NON_DIGIT, pFC->nLineCnt, pFC->nIntCnt);
	else
	{
		int iSign, nLen;
		if (*pChar == '-')
		{
			iSign = -1;
			nextchar(fpFile, pChar, pFC);
		}
		else
		{
			iSign = 1;
			if (*pChar == '+')
				nextchar(fpFile, pChar, pFC);
		}
		*pInt = 0;
		nLen = 0;
		while (*pChar >= '0' && *pChar <= '9')
		{
			nLen++;
			if (nLen > 10)
			{
				printf(ERR_TOO_BIG, pFC->nLineCnt, pFC->nIntCnt);
				return 0;
			}
			*pInt = (*pInt) * 10 + (*pChar - '0');
			nextchar(fpFile, pChar, pFC);
		}
		if (nLen == 0)
			printf(ERR_NON_DIGIT, pFC->nLineCnt, pFC->nIntCnt);
		else
		{
			if (iSign < 0) *pInt = -*pInt;
			pFC->nIntCnt++;
			return 1;
		}
	}
	return 0;
}

///////////////////////////////////////////////////////////////
//
//	getint_out -- get an intger from OUTPUT
//
//		pInt[OUT] -- the integer variable
//
//	RETURN: non-zero when success, or zero when error found

int getint_out(long* pInt)
{	
	return getint(fpOut, &cOut, &fcOut, pInt);
}

///////////////////////////////////////////////////////////////
//
//	checkret_out -- verify and jump over a end-of-line in OUTPUT file

int checkret_out()
{
	if (cOut == 13 || cOut == 10)
	{
		nextchar(fpOut, &cOut, &fcOut);
		return 1;
	}
	else
	{
		printf(ERR_LINE_EXTRA, fcOut.nLineCnt);
		return 0;
	}
}

///////////////////////////////////////////////////////////////
//
//	iseoln_out -- whether OUTPUT is end-of-line now

int iseoln_out()
{
	return (cOut == 13 || cOut == 10);
}

///////////////////////////////////////////////////////////////
//
//	checkeof_out -- verify the end-of-file in OUTPUT file

int checkeof_out()
{
	if (cOut == EOF)
		return 1;
	else
	{
		printf(ERR_FILE_EXTRA);
		return 0;
	}
}

///////////////////////////////////////////////////////////////
//
//	getchar_out -- read a character for OUTPUT file
//
//  DESCRIPTION: not used yet, it's made for extension

int getchar_out()
{
	int cChar = cOut;
	nextchar(fpOut, &cOut, &fcOut);
	return cChar;
}
