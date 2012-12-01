#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct mylist
{
    int* myarray;
    int length;
} mylist_t;

/**
 * Resize a list to a newlength. 
 */
void resize(mylist_t* list, int newlength)
{
    int* oldarray = list->myarray;

    list->myarray = (int *) malloc(sizeof(int) * newlength);
    memcpy(list->myarray, oldarray, list->length * sizeof(int));

    list->length = newlength;

    free(oldarray);
}

void free_list(mylist_t* list)
{
    free(list->myarray);
}

void print_list(mylist_t* list)
{
    int i;
    for (i = 0; i < list->length; i++)
    {
		// This will print an unnecessary space for the last element of the
		// array. But it doesn't really matter, since we'll stick a newline
		// after it anyway.

        printf("%d ", list->myarray[i]);
    }

    printf("\n");
}

int main(int argv, char* argc[])
{
    mylist_t the_list;
    the_list.length = 10;
    the_list.myarray = (int *) malloc(sizeof(int) * 10);
    int i;

    printf("Give me 10 integers!\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", the_list.myarray + i);
    }

    printf("Your list now is ");
    print_list(&the_list);

    int new_size;
    int old_size;
    do {
		printf("What should we resize the list to? (enter a negative value to exit)\n");
        scanf("%d", &new_size);
        
        if (new_size >= 0)
        {
            resize(&the_list, new_size);
            if (old_size < new_size)
            {
                printf("Give me %d more ints\n", new_size - old_size);
                for (i = old_size; i < new_size; i++)
                {
                    scanf("%d", the_list.myarray+i);
                }
            }
            old_size = new_size;

            printf("The list is now ");
            print_list(&the_list);
        }
    } while (new_size >= 0);

    free_list(&the_list);

    return 0;
}
