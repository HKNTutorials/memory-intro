/*
 * This example is meant to show the limits of what Valgrind can and can't
 * do.  The code obviously is wrong (accessing outside the array bounds).
 *
 * Run valgrind on this code, and also try uncommenting the alternate
 * definition of array and see how the behavior (and valgrind's ability to
 * detect errors) changes.
 */

#include <stdio.h>
#include <stdlib.h>

int array[4];
char* ptr = "pass!\n";

int main()
{
    /* 
     * Uncomment this next line if you want to see how using the heap
     * changes valgrind's ability to detect the errors.
     */

    //int* array = malloc(4*sizeof(int));
    
    array[-8] = 1; //this causes trouble

    //out of bounds array access isn't detected by valgrind
    printf("%d\n", array[5]); 
    puts(ptr); //should print "pass\n"

    return 0;
}
