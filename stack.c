#include "stack.h"


/* -- Base functions -- */

/*
 * Given a pointer to a particular element, keep printing data
 * until a null pointer is reached 
*/
void print_stack(s_atom *top){
	s_atom *cp = top;
	
	printf("[");
	while(cp != NULL){
		printf("%d", cp->data);

		if(cp->next != NULL) { printf(", "); }
		cp = cp->next;
	}
	printf("]\n");

	return;	
}

/*
 * Given a pointer to the current head of the stack, inserts a new
 * integer to the stack
*/
s_atom* insert(s_atom *current, int value){
	s_atom *new_atom = (s_atom*)(malloc(sizeof(s_atom)));

	if(new_atom == NULL){
		printf("stack.c: insert() failed to allocate memory\n");
		return NULL;
	}
	new_atom->data = value;
	new_atom->next = current;
	return new_atom;
}

/*
 * Given a pointer to the pointer to the top of the stack,
 * frees it and returns a pointer to its immediate successor.
*/
s_atom* delete_top(s_atom **current){
	if(*current == NULL){
		printf("stack.c: delete_top() attempted to delete ");
		printf("null pointer. Perhaps there is nothing ");
		printf("on the top of the stack to delete?\n");
		return NULL;
	}
	s_atom *new_head = (*current)->next;
	free(*current);
	return new_head;
}

/* -- Derived functions -- */

/*
 * Given a pointer to the pointer to the top of the stack,
 * returns its value, moves the input pointer to the next
 * element in the stack, and deletes the topmost atom
 *
 * potentially dangerous, use delete_top() instead
*/
int pop(s_atom **h_atom){
	if(*h_atom == NULL){
		printf("stack.c: pop() attempted to pop null pointer. ");
		printf("Perhaps there is nothing in the stack to pop?\n");
		return 0;
	}
	int i = (*h_atom)->data;
	s_atom *new_atom = delete_top(h_atom);
	if(new_atom == NULL){
		printf("Additional error from derived function pop(): ");
		printf("Unable to allocate memory\n");
		return 0xdeadbeef;
	}
	*h_atom = new_atom;

	return i;
}

/*
 * Given a pointer to the top of the stack, duplicates the top element
 * and returns a pointer to it
*/
s_atom* dup_top(s_atom *top){
	if(top == NULL){
		printf("stack.c: dup_top() attempted to duplicate a ");
		printf("null pointer. Maybe make sure the pointer is ");
		printf("pointing to a stack?\n");
		return NULL;
	}
	int d_data = top->data;
	s_atom *d_atom = insert(top, d_data);
	if(d_atom == NULL){
		printf("Additional error from derived function dup_top(): ");
		printf("Unable to allocate memory\n");
		return NULL;
	}
	return d_atom;
}
/*int main(){
	s_atom *head = NULL;
	head = insert(head, 9);
	head = insert(head, 6);
	head = insert(head, 345);

	printf("currently at top: %d\n", pop(&head));
	print_stack(head);
	head = delete_top(&head);
	print_stack(head);
	head = delete_top(&head);
	print_stack(head);
	head = delete_top(&head);
	pop(&head);
	print_stack(head);
	head = dup_top(head);

	head = insert(head, 6);
	head = dup_top(head);
	head = dup_top(head);
	print_stack(head);
	
	return 0;
}*/

