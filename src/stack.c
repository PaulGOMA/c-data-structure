#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*--------------------------------------------------------------
 * new_stack
 *
 * Creates and returns an empty stack.
 * Since the stack is represented by a pointer to the top node,
 * an empty stack is simply represented by NULL.
 *
 * Return:
 *   NULL — representing an empty stack.
 *--------------------------------------------------------------*/
Stack new_stack(void)
{
    return NULL;
}

/*--------------------------------------------------------------
 * is_empty_stack
 *
 * Checks whether the stack is empty.
 *
 * Parameters:
 *   st — pointer to the top of the stack.
 *
 * Return:
 *   true  — if the stack is empty.
 *   false — otherwise.
 *--------------------------------------------------------------*/
bool is_empty_stack(Stack st)
{
    return st == NULL;
}

/*--------------------------------------------------------------
 * push_stack
 *
 * Pushes a new element onto the stack.
 * The stack is non‑owner of the data: it stores the pointer
 * as-is without copying or freeing it.
 *
 * Parameters:
 *   st    — current top of the stack.
 *   value — pointer to the data to store.
 *
 * Return:
 *   New top of the stack.
 *
 * Notes:
 *   - Exits the program if memory allocation fails.
 *--------------------------------------------------------------*/
Stack push_stack(Stack st, void* value)
{
    StackElement* element = malloc(sizeof(StackElement));
    if (element == NULL)
    {
        fprintf(stderr, "ERROR: memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    element->data = value;
    element->next = st;

    return element;
}

/*--------------------------------------------------------------
 * pop_stack
 *
 * Removes the top element from the stack.
 * The stack is non‑owner of the data: only the node is freed,
 * not the data it points to.
 *
 * Parameters:
 *   st — current top of the stack.
 *
 * Return:
 *   New top of the stack.
 *   NULL if the stack was empty.
 *--------------------------------------------------------------*/
Stack pop_stack(Stack st)
{
    if (is_empty_stack(st))
        return NULL;

    Stack temp = st;
    st = st->next;

    free(temp);
    return st;
}

/*--------------------------------------------------------------
 * clear_stack
 *
 * Removes all elements from the stack.
 * Frees all nodes but does not free the data they reference.
 *
 * Parameters:
 *   st — current top of the stack.
 *
 * Return:
 *   NULL — representing an empty stack.
 *--------------------------------------------------------------*/
Stack clear_stack(Stack st)
{
    while (st != NULL)
        st = pop_stack(st);

    return NULL;
}

/*--------------------------------------------------------------
 * peek_stack
 *
 * Returns the data stored at the top of the stack without
 * removing the element.
 *
 * Parameters:
 *   st — current top of the stack.
 *
 * Return:
 *   Pointer to the data at the top.
 *   NULL if the stack is empty.
 *--------------------------------------------------------------*/
void* peek_stack(Stack st)
{
    if (is_empty_stack(st))
        return NULL;

    return st->data;
}

/*--------------------------------------------------------------
 * length_stack
 *
 * Computes the number of elements in the stack.
 * Complexity: O(n)
 *
 * Parameters:
 *   st — current top of the stack.
 *
 * Return:
 *   Number of elements in the stack.
 *--------------------------------------------------------------*/
size_t length_stack(Stack st)
{
    size_t length = 0;
    for (Stack temp = st; temp != NULL; temp = temp->next)
        length++;

    return length;
}
