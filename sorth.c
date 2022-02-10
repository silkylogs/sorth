/*
 * Current syntax list
 *
 * push <num> # push a number on to the stack
 * pop # pop off the first number on the stack
 * add # pop off the top 2 items on the stack and push their sum on to the stack.
 * ifeq <lineno> # check top of stack, if it's 0, continue, else, jump to <lineno>
 * jump <lineno> # jump to a line number
 * print # print the value at the top of the stack
 * dup # push a copy of what's at the top of the stack back onto the stack.
 */

#include <stdio.h>
#include "stack.h"
#include "filehandler.h"

/* Global options - best to put these in a seperate header file */
#define SORTH_PROMPT "$ "



/* Commands */
void sorth_push(s_atom *globalstack, int number){
	;
}

void sorth_pop(s_atom *globalstack){
	;
}

void sorth_add(s_atom *globalstack){
	;
}

void sorth_ifeq(){
	;
}

void sorth_print(){
	;
}

void sorth_dup(){
	;
}




void exec_command(const char *command){

	;
}

int main(int argc, char **argv){
	printf("Sorth interpreter... working\n");

	char **filecontents = extract_to_string_array(argv[1]);
	int linecount = total_line_numbers("test.txt");

	printf("%d\n", linecount);
	for(long i = 0; i < total_line_numbers(argv[1]); i++){
		printf("%s", filecontents[i]);
	}


	/* Interactive mode, to be implemented l8r */
	/*while(1){
		char command[513];
		printf(SORTH_PROMPT);
		gets(command);
		exec_command(command);
	}*/
	
	return 0;
}
