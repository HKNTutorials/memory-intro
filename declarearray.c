// Just declares an array... right?
#include <stdlib.h>
#define INT_MAX 0x7FFFFFFF

int main()
{
	int* array = malloc(INT_MAX * sizeof(int));
	array[0] = 0;
	free(array);
	return 0;
}
