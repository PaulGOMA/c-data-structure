#ifndef __STACK__H__
#define __STACK__H__

#include <stdbool.h> 

/*
* Stack definition
*/
    typedef struct StackElement {
        void* data;
        struct StackElement *next;
    }StackElement, *Stack;

    /*
    * Function prototypes
    */

    Stack new_stack(void);
    bool is_empty_stack(Stack st);
    Stack push_stack(Stack st, void* value);
    Stack pop_stack(Stack st);

#endif