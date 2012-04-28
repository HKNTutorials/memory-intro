// What happens when we don't free our dynamic memory?

#include <stdlib.h>

int main()
{
	int* array = malloc(123456789 * sizeof(int));
	array[0] = 0;
	return 0;
}
