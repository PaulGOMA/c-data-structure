#ifndef __STACK__H__
#define __STACK__H__

#include <stdbool.h>
#include <stdint.h>

/*======================================================================
 * Stack — Generic Stack (LIFO) Implementation
 *
 * This module provides a lightweight, non‑owning stack structure.
 * The stack stores pointers (`void*`) without copying or freeing the
 * underlying data. Only the stack nodes themselves are allocated and
 * freed by the library.
 *
 * Characteristics:
 *   - Generic: stores any pointer type (int*, struct*, etc.)
 *   - Non‑owning: user manages the lifetime of the pointed data
 *   - Singly linked list implementation
 *   - Push/Pop in O(1)
 *   - Length computation in O(n)
 *====================================================================*/

/*--------------------------------------------------------------
 * StackElement
 *
 * Represents a single node in the stack.
 *
 * Fields:
 *   data — pointer to user‑provided data (not owned by the stack)
 *   next — pointer to the next element in the stack
 *
 * Stack:
 *   A stack is represented by a pointer to the top StackElement.
 *--------------------------------------------------------------*/
typedef struct StackElement {
    void* data;
    struct StackElement* next;
} StackElement, *Stack;

/*======================================================================
 * Function Prototypes
 *====================================================================*/

/*--------------------------------------------------------------
 * new_stack
 *
 * Creates an empty stack.
 *
 * Return:
 *   NULL — representing an empty stack.
 *--------------------------------------------------------------*/
Stack new_stack(void);

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
bool is_empty_stack(Stack st);

/*--------------------------------------------------------------
 * push_stack
 *
 * Pushes a new element onto the stack.
 * The stack does not take ownership of the data pointer.
 *
 * Parameters:
 *   st    — current top of the stack.
 *   value — pointer to the data to store.
 *
 * Return:
 *   New top of the stack.
 *--------------------------------------------------------------*/
Stack push_stack(Stack st, void* value);

/*--------------------------------------------------------------
 * pop_stack
 *
 * Removes the top element from the stack.
 * Frees the node but not the data it points to.
 *
 * Parameters:
 *   st — current top of the stack.
 *
 * Return:
 *   New top of the stack.
 *   NULL if the stack was empty.
 *--------------------------------------------------------------*/
Stack pop_stack(Stack st);

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
Stack clear_stack(Stack st);

/*--------------------------------------------------------------
 * peek_stack
 *
 * Returns the data stored at the top of the stack without removing it.
 *
 * Parameters:
 *   st — current top of the stack.
 *
 * Return:
 *   Pointer to the data at the top.
 *   NULL if the stack is empty.
 *--------------------------------------------------------------*/
void* peek_stack(Stack st);

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
size_t length_stack(Stack st);

#endif /* __STACK__H__ */
