/*By Gyula Horvath
  Build a "heap" from half (N/2+1) of the items.
  The heap is a sorted list of sorted buckets (of size 8).
  Buckets are sorted according to their least items. Now, the first item in
  the first bucket has exactly N/2 larger items.
  Insert the rest of the items one by one into the heap, and delete
  the least item.
  First insert the next item into the first bucket, the least overflows,
  then insert this bucket into the rest of the sorted bucket list.
  At the end the first item in the first bucket has exactly N/2 larger
  items overall. Therefore, this item is the median of all items.
*/
#include <stdlib.h>

#ifndef DEVICE_H
#include "device.h"
#endif

#define MaxN            3000           /*max. # elements*/
#define BSize           8              /*bucket size*/
#define MaxB            (MaxN / BSize) /*max. # buckets*/

typedef int Bucket[BSize];

static int N;             /*# elements*/
static Bucket T[MaxB];
static int S[MaxB];       /*sorted sequence of buckets:S[1]...S[NB]*/
static int M;             /*solution*/
static unsigned int NB;   /*# buckets*/
static unsigned int MB;   /*# elements in the possible non-full bucket*/


static int BFindPos(int *B, int M, int X)
{  /*FindPos*/
  /*Finds position of X by ternary search in bucket B having M elements */
  int Result, L, R, Lm, Rm, Xm, x1, x2, d;

  if (M == 1)
  {  /*bucket contains a single item*/
    x1 = B[0];
    x2 = X;
    Lm = Med3(1, 2, x1);   /*establish orientation of x1 and x2 w.r.t 1->2*/
    Rm = Med3(1, x1, x2);
    if (Lm == 1 && Rm == x1 || Lm != 1 && Rm != x1)
      return 0;
    else
      return 1;
  }

  L = 0;
  R = M + 1;
  while (L + 2 < R) {
    d = (R - L) / 3;
    if ((R - L) % 3 == 2) {  /*ternary partition size:(d+1)-d-(d+1) */
      Lm = L + d + 1;
      Rm = R - d - 1;
    } else {                 /*ternary partition size:d-(d+1)-d */
      Lm = L + d;
      Rm = R - d;
    }
    Xm = Med3(B[Lm - 1], B[Rm - 1], X);
    if (Xm == B[Lm - 1])
      R = Lm;
    else if (Xm == B[Rm - 1])
      L = Rm;
    else {
      L = Lm;
      R = Rm;
    }
  }

  if (R != L + 2)
    return L;
  if (L == 0)   /*handle extremal cases*/
    L = 1;
  R = L + 1;
  Xm = Med3(B[L - 1], B[R - 1], X);
  if (Xm == B[L - 1])
    L--;
  else if (Xm == B[R - 1])
    L = R;
  return L;
}


static int LFindPos(int L0, int R0, int X)
{
  /*Finds position of X by ternary search in the bucket list S[L0..R0] */
  int Result;
  int L, R, Lm, Rm, Xm, x1, x2, d;

  L = L0 - 1;
  R = R0 + 1;
  if (L0 == R0)
  {  /*list contains a single item*/
    x1 = T[S[L0 - 1] - 1][0];
    x2 = X;              /*establish orientation of x1 and x2 w.r.t 1->2*/
    if (x1 == 1) {
      Xm = Med3(1, 2, X);
      if (X == 2 || Xm != 1)
	return L0;
      else
	return L;
    } else if (x1 == 2) {
      Xm = Med3(1, 2, X);
      if (X == 1 || Xm != 2)
	return L;
      else
	return L0;
    } else {
      Lm = Med3(1, 2, x1);
      Rm = Med3(1, x1, x2);
      if (Lm == 1 && Rm == x1 || Lm != 1 && Rm != x1)
	return L;
      else
	return L0;
    }
  }

  while (L + 2 < R) {
    d = (R - L) / 3;
    if ((R - L) % 3 == 2) {  /*ternary partition size:(d+1)-d-(d+1) */
      Lm = L + d + 1;
      Rm = R - d - 1;
    } else {                 /*ternary partition size:d-(d+1)-d */
      Lm = L + d;
      Rm = R - d;
    }
    Xm = Med3(T[S[Lm - 1] - 1][0], T[S[Rm - 1] - 1][0], X);
    if (Xm == T[S[Lm - 1] - 1][0])
      R = Lm;
    else if (Xm == T[S[Rm - 1] - 1][0])
      L = Rm;
    else {
      L = Lm;
      R = Rm;
    }
  }

  if (R != L + 2)
    return L;
  if (L == L0 - 1)   /*handle extremal cases*/
    L = L0;
  R = L + 1;
  Xm = Med3(T[S[L - 1] - 1][0], T[S[R - 1] - 1][0], X);
  if (Xm == T[S[L - 1] - 1][0])
    L--;
  else if (Xm == T[S[R - 1] - 1][0])
    L = R;
  return L;
}

static void Build(unsigned int N)
{
  /*Builds bucket-list containing items 1..N*/
  int i, j, k, X0, X, Xm, FORLIM, FORLIM1;

  NB = (N + BSize - 1) / BSize;
  MB = N & (BSize - 1);
  if (MB == 0)
    MB = BSize;
  S[0] = 1;
  FORLIM = NB;
  for (i = 0; i < FORLIM; i++)
  {  /*fill bucket T[i]*/
    X0 = i * BSize;
    if (i + 1 == NB)
      M = MB;
    else
      M = BSize;
    FORLIM1 = M;
    for (j = 1; j <= FORLIM1; j++) {   /*for j*/
      if (i + 1 == 1 && j < 3) {
	T[i][j - 1] = j;
	continue;
      }
      X = X0 + j;
      Xm = BFindPos(T[i], j - 1, X);
      for (k = j; k >= Xm + 2; k--)
	T[i][k - 1] = T[i][k - 2];
      T[i][Xm] = X;
    }

    Xm = LFindPos(1, i, T[i][0]);
    for (j = i + 1; j >= Xm + 2; j--)
	  /*insert bucket T[i] according to its least element*/
	    S[j - 1] = S[j - 2];
    S[Xm] = i + 1;
  }
}

static void Replace(int X)
{
  /*Inserts item X into the bucket-list and discards the smallest item*/
  int i, j, M, Xm;

  /*Replace*/
  /*Invariant: There are N/2 items largest then T[S[1],1]*/
  i = S[0];   /*bucket T[S1]] contains the least item*/
  if (i == NB)
    M = MB;
  else
    M = BSize;
  Xm = BFindPos(T[i - 1], M, X);
  if (Xm == 0)
    return;

  for (j = 2; j <= Xm; j++)   /*insert X into the first bucket T[i]*/
    T[i - 1][j - 2] = T[i - 1][j - 1];
  /*the least item overflows!*/
  T[i - 1][Xm - 1] = X;
  /*insert first bucket T[i] into the list S[2..NB]*/
  Xm = LFindPos(2, NB, T[i - 1][0]);
  if (Xm == 1)
    return;
  for (j = 2; j <= Xm; j++)
    S[j - 2] = S[j - 1];
  S[Xm - 1] = i;
}

static int Compute(void)
{
  int x, Mi, FORLIM;

  Mi = N / 2 + 1;

  Build(Mi);
  FORLIM = N;
  /*There are N/2 items largest then T[S[1],1]*/
  for (x = Mi + 1; x <= FORLIM; x++)
    Replace(x);

  return (T[S[0] - 1][0]);
}

void main()
{
  N = GetN();
  M = Compute();
  Answer(M);
  exit(0);
}
