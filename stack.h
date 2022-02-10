#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>

/*
 * Usage instructions:
 * - To create the stack, create a variable of type (s_atom*)
 * - To add an element to the stack, assign the output of insert()
 *   to the stack pointer
 * - To pop the top of the stack ensure that the return value
 *   is the popped number, and that input is of type (s_atom**)
*/


typedef struct stack_atom{
	int data;
	struct stack_atom *next;
} s_atom;

/* -- Base functions -- */
void print_stack(s_atom *top);
s_atom* insert(s_atom *current, int value);
s_atom* delete_top(s_atom **current);

/* -- Derived functions -- */
int pop(s_atom **h_atom);
s_atom* dup_top(s_atom *top);

#endif
