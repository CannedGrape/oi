/////////////////////////////////////////////////////////////////////////////
//
//	Filter Program Format header file (IOI'2000,Beijing)
//
//		LOOSE VERSION
//
//	DESCRIPTION:
//
//		the Filter Program Format programs must include this file,
//		the compiled executable file should be run as follow syntax:
//
//			<executable file> <output_file> <standard_file>
//
//		output file is the file generated from contestant's program,
//		referred as OUTPUT hereafter,
//		standard file is provided by contest organisation including
//		information for corresponding filter, referred as STANDARD hereafter
//
//		for example:
//
//			my_fpf problem1_2.out problem1_2.std
//
//	Variables contained:
//
//		value -- the evaluation result
//
//	Functions contained:
//
//		init          -- init evaluation
//		finish        -- finish and print value  
//		getint_out    -- get integer from OUTPUT
//		getint_std    -- get integer from STANDARD
//		checkret_out  -- verify end-of-line in OUTPUT
//		checkret_std  -- verify end-of-line in STANDARD
//		checkeof_out  -- verify end-of-file in OUTPUT
//		iseoln_out    -- whether OUTPUT is end-of-line now
//		iseoln_std    -- whether STANDARD is end-of-line now
//		getchar_out   -- get single character from OUTPUT, not used yet
//		getchar_std   -- get single character from STANDARD
//
//	USAGE:
//
//		include this file first:
//
//			#include "fpf.h"
//
//		write a main program as follow:
//
//			int main(int argc, char **argv)
//			{
//				if (init(argc, argv))
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
//				value = xxx;
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
//			//correct answer
//			long nCorrect;
//
//			//OUTPUT's answer
//			long nForTest;
//
//			//read correct answer from STANDARD first, assuming it is well-formed
//			getint_std(&nCorrect);
//
//			//read from OUTPUT an integer
//			if (!getint_out(&nForTest))
//
//			//if failed to read, error message has been displayed
//			//however you can show your specific error here before quitting
//				return fprintf(stderr, "Data missing");
//
//			//comparison and evaluation
//			if (nForTest != nCorrect)
//
//			//if mismatch, show error and quit
//				return fprintf(stderr, "Data mismatch");
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
//			value = 10;
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

#include <stdio.h>
#include <stdlib.h>

#define ERR_PARAM      "Output and standard filenames required\n"
#define ERR_OPEN       "Cannot open file %s\n"

#define ERR_EOF        "Unexpected end-of-file at line %ld\n"
#define ERR_LINE_EXTRA "Extra character found in line %ld\n"
#define ERR_FILE_EXTRA "Extra lines found\n"

#define ERR_NON_DIGIT  "In line %ld, non-digital character is found before No.%ld integer\n"
#define ERR_LESS_INT   "In line %ld, the No.%ld integer is missing\n"
#define ERR_LESS_SPACE "In line %ld, space before the No.%ld integer is missing\n"
#define ERR_MORE_SPACE "In line %ld, extra space is found before the No.%ld integer\n"
#define ERR_TOO_BIG    "In line %ld, the No.%ld integer is overflow\n"

//////////////////////////////////////////////////////////////////////
//
//	value -- the evaluation mark
//
//	DESCRIPTION:
//
//		it is assign zero by default,
//		modify it in the evaluation or leave it as zero
//		the function 'finish' will automatically print it to stdin

int value;

////////////////////////////////////////////////////////////////
//
//	INTERNAL USE

//OUTPUT and STANDARD file
FILE *fpOut, *fpStd;

//the preread character of the two files
int cOut, cStd;

//structure to record the context of the two files
typedef struct FILECONTEXT_tag
{
	//whether it is at the beggining of a new line
	int bNewLine;
	//the line number
	long nLineCnt;
	//the index of integer of current line
	long nIntCnt;
} FILECONTEXT;
FILECONTEXT fcOut, fcStd;

///////////////////////////////////////////////////////////////
//
//	init -- open files and initialize
//
//		argc[IN] -- argument count from main
//		argv[IN] -- argument varlist from main
//
//	RETURN: non-zero when success, or zero when error found

int init(int argc, char **argv)
{
	value = 0;
	fpOut = fpStd = 0;
	if (argc != 3)
		fprintf(stderr, ERR_PARAM);
	else if (!(fpOut = fopen(argv[1], "rb")))
		fprintf(stderr, ERR_OPEN, argv[1]);
	else if (!(fpStd = fopen(argv[2], "rb")))
		fprintf(stderr, ERR_OPEN, argv[2]);
	else
	{
		cOut = fgetc(fpOut);
		fcOut.bNewLine = 1;
		fcOut.nLineCnt = 1;
		fcOut.nIntCnt = 1;

		cStd = fgetc(fpStd);
		fcStd.bNewLine = 1;
		fcStd.nLineCnt = 1;
		fcStd.nIntCnt = 1;

		return 1;
	}
	return 0;
}

///////////////////////////////////////////////////////////////
//
//	finish -- print result and close files

void finish()
{
	printf("%ld\n", value);
	if (fpOut)
		fclose(fpOut);
	if (fpStd)
		fclose(fpStd);
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
	while (*pChar == ' ' || *pChar == '\t' || *pChar == 13 || *pChar == 10)
	{
		nextchar(fpFile, pChar, pFC);
	}
	if (*pChar == EOF)
	{
		fprintf(stderr, ERR_LESS_INT, pFC->nLineCnt, pFC->nIntCnt);
		return 0;
	}
	if ((*pChar < '0' || *pChar > '9') && *pChar != '+' && *pChar != '-')
		fprintf(stderr, ERR_NON_DIGIT, pFC->nLineCnt, pFC->nIntCnt);
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
				fprintf(stderr, ERR_TOO_BIG, pFC->nLineCnt, pFC->nIntCnt);
				return 0;
			}
			*pInt = (*pInt) * 10 + (*pChar - '0');
			nextchar(fpFile, pChar, pFC);
		}
		if (nLen == 0)
			fprintf(stderr, ERR_NON_DIGIT, pFC->nLineCnt, pFC->nIntCnt);
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
//	getint_std -- get an intger from STANDARD
//
//		pInt[OUT] -- the integer variable
//
//	RETURN: non-zero when success, or zero when error found

int getint_std(long* pInt)
{	
	return getint(fpStd, &cStd, &fcStd, pInt);
}

///////////////////////////////////////////////////////////////
//
//	checkret_out -- verify and jump over a end-of-line in OUTPUT file
//
//		ignored in loose version

int checkret_out()
{
	if (cOut == 13 || cOut == 10)
	{
		nextchar(fpOut, &cOut, &fcOut);
		return 1;
	}
	else
	{
		return 1;
	}
}

///////////////////////////////////////////////////////////////
//
//	checkret_std -- verify and jump over a end-of-line in STANDARD file

int checkret_std()
{
	if (cStd == 13 || cStd == 10)
	{
		nextchar(fpStd, &cStd, &fcStd);
		return 1;
	}
	else
	{
		fprintf(stderr, ERR_LINE_EXTRA, fcStd.nLineCnt);
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
//	iseoln_std -- whether OUTPUT is end-of-line now

int iseoln_std()
{
	return (cStd == 13 || cStd == 10);
}

///////////////////////////////////////////////////////////////
//
//	checkeof_out -- verify the end-of-file in OUTPUT file
//
//		ignored in loose version

int checkeof_out()
{
	return 1;
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

///////////////////////////////////////////////////////////////
//
//	getchar_std -- read a character for STANDARD file

int getchar_std()
{
	int cChar = cStd;
	nextchar(fpStd, &cStd, &fcStd);
	return cChar;
}