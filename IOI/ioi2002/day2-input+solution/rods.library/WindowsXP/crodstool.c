#include <stdio.h>
#include "crectlib.h"


int main()
{
    int n;
    n=gridsize ();
    printf ("gridsize() = %d\n", n);   
    printf ("rect(3, 6, 3, 8) = %d\n", rect(3, 6, 3, 8)); 
    printf ("rect(1, 5, 1, 3) = %d\n", rect(1, 5, 1, 3)); 
    report (4, 3, 4, 8, 4, 4, 9, 4);
}
