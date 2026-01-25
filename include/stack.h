#ifndef __STACK__H__
#define __STACK__H__

#include <stddef.h>
#include <stdbool.h> 

/*
* Stack definition
*/
    typedef struct StackElement {
        void* data;
        struct StackElement *next;
        size_t size;
    }StackElement, *Stack;

    /*
    * Function prototypes
    */

    Stack new_stack(void);
    bool is_empty_stack(Stack st);
    // void push_stack(Stack st, &value);


#endif