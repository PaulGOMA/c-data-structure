#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack new_stack(void){
    return NULL;
}
/*====================================*/

bool is_empty_stack(Stack st)
{
    return st == NULL;
}
/*====================================*/

Stack push_stack(Stack st, void* value)
{
    StackElement* element = malloc(sizeof(StackElement));

    if(element == NULL)
    {
        fprintf(stderr, "ERROR ! memory allocation failed");
        exit(EXIT_FAILURE);
    }

    element->data = value;
    element->next = st;

    return element;
}
/*====================================*/

Stack pop_stack(Stack st)
{
    if(is_empty_stack(st))
        return new_stack();

    Stack temp = st;
    st = st->next;

    free(temp);
    return st;
}
/*====================================*/

Stack clear_stack(Stack st)
{
    while (st != NULL)
        st = pop_stack(st);

    return NULL;
}
/*====================================*/

void* peek_stack(Stack st)
{
    if(is_empty_stack(st))
        return NULL;

    return st->data;
}
/*====================================*/

size_t length_stack(Stack st)
{
    Stack temp = st;
    size_t length = 0;

    while(temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    return length;
}