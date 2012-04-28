#include <stdio.h>
#include <stdlib.h>

typedef struct list_node
{
    int element;
    int is_head;
    struct list_node* next;
} list_node_t;

void* mark_head(list_node_t* head)
{
    head->is_head = 1;
    return head;
}

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
    list_node_t head;
    list_node_t* next_node = &head;
    int i;

    for (i=0; i < length; i++)
    {
        next_node->element = array[i];
        next_node->is_head = 0;
        if (i != length-1)
        {
            next_node->next = (list_node_t*) malloc(sizeof(list_node_t));
            next_node = next_node->next;
        }
        else
            next_node->next = NULL;
    }

    return mark_head(&head);
}

list_node_t* reverse_linked_list(list_node_t* head)
{
    list_node_t *last_node, *next_node, *new_next_node;

    if (head == NULL)
        return NULL;

    last_node = head;
    next_node = head->next;
    head->next = NULL;
    
    while (next_node != NULL)
    {
        new_next_node = next_node->next;
        next_node->next = last_node;

        last_node = next_node;
        next_node = new_next_node;
    }

    return last_node;
}

void print_linked_list(list_node_t* head)
{
    list_node_t* next_node = head;
    int i;

    for (i=0; next_node != NULL; i++)
    {
        printf("Element #%d: %d\n", i, next_node->element);
        next_node = next_node->next;
    }
}

/**
 * A simple routine which frees each noe of a linked list
 *
 * @param head the head of the linked list
 */
void free_linked_list(list_node_t* head)
{
    list_node_t* next_node = head;

    while (next_node != NULL)
    {
        list_node_t* temp = next_node;
        next_node = next_node->next;
        free(temp);
    }
}

int main()
{
    int myints[] = {3, 56, 2341, 90, 275, -24, 32, 64, 77, -125};
    int numints = 10;
    
    list_node_t* head = make_linked_list(myints, numints);
    head = reverse_linked_list(head);

    print_linked_list(head);
    fflush(stdout);

    free_linked_list(head);

    return 0;
}

