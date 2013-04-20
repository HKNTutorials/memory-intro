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

    /* allocate space for a new array */
    list->myarray = (int *) malloc(sizeof(int) * newlength);
    /* copy over the old values to the new array */
    memcpy(list->myarray, oldarray, list->length * sizeof(int));

    list->length = newlength;

    /* cleanup the old memory */
    free(oldarray);
}

/**
 * Initialize a my_list_t struct (assumes list->myarray is uninitialized
 * and thus does not need to be freed)
 */
void init_list(my_list_t* list, int length)
{
    list->length = length;
    list->myarray = (int *) malloc(sizeof(int) * length);
}

/**
 * This function frees the internal memory used by a mylist_t struct.
 * It is generally a good design pattern to offer functions that look
 * like this, so the user of the struct doesn't have to worry about
 * the struct's internal details.
 */
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
    int i;
    
    // initialize the_list
    init_list(&the_list, 10);

    // ask for initial user input of 10 ints, to fill the_list
    printf("Give me 10 integers!\n");
    for (i = 0; i < 10; i++)
    {
        scanf("%d", the_list.myarray + i);
    }

    // print out the_list
    printf("Your list now is ");
    print_list(&the_list);

    // now the program continually asks to resize the_list, and if the
    // new size is larger, for more input to fill up the_list; if
    // the new size is smaller, the_list is truncated to the smaller
    // size.
    int new_size;
    int old_size;
    do {
        // ask for a new size for the_list
        printf("What should we resize the list to? (enter a negative value to exit)\n");
        scanf("%d", &new_size);
        
        if (new_size >= 0)
        {
            // resize the_list and, if necessary, fill it with new input
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

    // cleanup allocated memory
    free_list(&the_list);

    return 0;
}
