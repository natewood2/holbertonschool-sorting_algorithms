#include "sort.h"

/**
 * 
 * 
 * 
 * 
*/
void swap_node(listint_t **list, listint_t *node, listint_t *node_two)
{
    listint_t *temp;

    if (node->next == node_two) 
    {
        temp = node_two->next;
        node_two->next = node;
        node->next = temp;

        temp = node->prev;
        node->prev = node_two;
        node_two->prev = temp;
    } 
    else 
    {
        node->next = node_two->next;
        node_two->next = node;

        temp = node->prev;
        node->prev = node_two->prev;
        node_two->prev = temp;
    }
    if (node->next != NULL) 
    {
        node->next->prev = node;
    }
    if (node_two->prev != NULL) 
    {
        node_two->prev->next = node_two;
    }
    if (node_two->prev == NULL) 
    {
        *list = node_two;
    }
}


/**
 * 
 * 
 * 
 * 
*/
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *insert;

    if (list == NULL || *list == NULL)
    {
        return;
    }

    current = (*list)->next;

    while (current != NULL)
    {
        insert = current->prev;
        while (insert != NULL && current->n < insert->n)
        {
            swap_node(list, insert, current);
            print_list(*list);
            insert = current->prev;
        }
        current = current->next;
    }
}
