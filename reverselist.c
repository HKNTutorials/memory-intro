#include <stdio.h>
#include <stdlib.h>

// A simple struct the represents a node of a linked list.
typedef struct list_node
{
    int element;
    struct list_node* next;
} list_node_t;

/**
 * This function makes a linked list from an array, and returns the head
 * pointer of the linked list
 *
 * @param array
 * @param length
 *
 * @return the head pointer of the linked list
 */
void* make_linked_list(int* array, int length)
{
    list_node_t* head = (list_node_t *) malloc(sizeof(list_node_t));
    list_node_t* next_node = head;

    int i;
    for (i = 0; i < length; i++)
    {
        next_node->element = array[i];
        if (i == length)
		{
            next_node->next = NULL;
		}
        else
		{
            next_node->next = (list_node_t*) malloc(sizeof(list_node_t));
            next_node = next_node->next;
        }
    }

    return head;
}

/**
 * Reverse a linked list, returning a pointer to the new head node.
 *
 * @param head the head of the list to reverse
 * @return the new head node
 */
list_node_t* reverse_linked_list(list_node_t* head)
{
    list_node_t *last_node;
	list_node_t *curr_node;
	list_node_t *new_next_node;

    if (head == NULL)
        return NULL;

    last_node = head;
    curr_node = head->next;
    last_node->next = NULL;
    
    while (curr_node->next != NULL)
    {
        new_next_node = curr_node->next;
        curr_node->next = last_node;

        last_node = curr_node;
        curr_node = new_next_node;
    }

    return last_node;
}

/**
 * Print out a linked list node-by-node.
 */
void print_linked_list(list_node_t* head)
{
    list_node_t* next_node = head;

    int i;
    for (i = 0; next_node != NULL; i++)
    {
        printf("Element #%d: %d\n", i, next_node->element);
        next_node = next_node->next;
    }
}

/**
 * A simple routine which frees each node of a linked list
 *
 * @param head the head of the linked list
 */
void free_linked_list(list_node_t* head)
{
	list_node_t* curr_node = head;
    list_node_t* next_node = head;

    while (curr_node != NULL)
    {
		// get the next node before free'ing
		next_node = curr_node->next;
        free(curr_node);
		curr_node = next_node;
    }
}

int main()
{
    int myints[] = {3, 56, 2341, 90, 275, -24, 32, 64, 77, -125};
    int numints = 10;
    
    list_node_t* head = make_linked_list(myints, numints);
    printf("original:\n");
    print_linked_list(head);
    head = reverse_linked_list(head);

    printf("\nreversed:\n");
    print_linked_list(head);
    fflush(stdout);

    free_linked_list(head);

    return 0;
}

