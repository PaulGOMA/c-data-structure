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
    Stack temp = st;

    if(is_empty_stack(st))
    {
        printf("The stack is empty");
        return new_stack();
    }

    st = st->next;
    temp->next = NULL;

    free(temp);
    return st;
}