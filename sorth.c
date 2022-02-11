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
#include "sorth.h"
#include "stack.h"
#include "filehandler.h"



/* Commands */
s_atom* sorth_push(s_atom *globalstack, const int number){
	globalstack = insert(globalstack, number);
	if(globalstack == NULL){
		printf("sorth.c: sorth_push() is unable to push %d onto stack\n");
		return NULL; /* Returning null as a means of error checking */
	}
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




void eval_command(const char *cmd){
	printf("evaluating: %s", cmd);
	int correct_instruction_found = 0;
	
	/* Checking what command is used */
	int inst_index = 0;
	for( inst_index = 0; inst_index < SORTH_INSTRUCTION_COUNT; inst_index++){
		char *instruction_in_cmd = strstr(cmd, sorth_instruction_set[inst_index]);
		if(instruction_in_cmd != NULL){
			//printf("found\n");
			correct_instruction_found = 1;
			break;
		}
	}

	/* Implement mechanism for dealing with syntax errors here */
	if(!correct_instruction_found){
		printf("eval_command(): syntax error in line: %s", cmd);
		return;
	}
	//printf("found instruction: %s\n", sorth_instruction_set[inst_index]);


	/* Implement command evaluation here */
	if(0 == strcmp(sorth_instruction_set[0], sorth_instruction_set[inst_index])){
		printf("push found\n");
	}
	else if(0 == strcmp(sorth_instruction_set[1], sorth_instruction_set[inst_index])){
		printf("pop found\n");
	}
	else if(0 == strcmp(sorth_instruction_set[2], sorth_instruction_set[inst_index])){
		printf("add found\n");
	}
	else if(0 == strcmp(sorth_instruction_set[3], sorth_instruction_set[inst_index])){
		printf("ifeq found\n");
	}
	else if(0 == strcmp(sorth_instruction_set[4], sorth_instruction_set[inst_index])){
		printf("print found\n");
	}
	else if(0 == strcmp(sorth_instruction_set[5], sorth_instruction_set[inst_index])){
		printf("dup found\n");
	}
	else{
		printf("sorth.c: eval_command() encountered an else condition in command evaluation\n");
		return;
	}
	

}

int main(int argc, char *argv[]){
	printf("Sorth interpreter... working\n");

	s_atom *globalstack = NULL;
	char **filecontents = extract_to_string_array(argv[1]);
	int linecount = total_line_numbers("test.txt");

	printf("number of lines in file: %d\n", linecount);
	for(long i = 0; i < total_line_numbers(argv[1]); i++){
		eval_command(filecontents[i]);
	}

	

	/* Interactive mode, to be implemented later */
	/*while(1){
		char command[513];
		printf(SORTH_PROMPT);
		gets(command);
		exec_command(command);
	}*/
	
	return 0;
}
