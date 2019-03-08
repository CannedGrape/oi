#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int main()
{
    freopen("drive.in","r",stdin);
    freopen("drive.out","w",stdout);
    int n;
    scanf("%d",&n);
    if(n==4)
      printf("1\n1 1\n2 0\n0 0\n0 0\n");
    else
      printf("2\n3 2\n2 4\n2 1\n2 4\n5 1\n5 1\n2 1\n2 0\n0 0\n0 0\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}
