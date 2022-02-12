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

s_atom *globalstack = NULL;


/* Returns the remainder of the command string which does not contain the instruction */
char* get_arg_string(const char *cmd, int instlen){
	/*
	 * Without a way to free the memory allocated to this, this statement
	 * *will* cause a memory leak.
	 * Also the "-instlen" was added as an optimizing procedure
	 * to reduce excessive byte allocation
	 */
	char *argstr = malloc(strlen(cmd) * sizeof(char) -instlen);
	if(argstr == NULL){
		printf("sorth.c: get_arg_string() is unable to allocate memory for operation\n");
		free(argstr);
		return NULL;
	}
	strcpy(argstr, cmd + instlen);
	return argstr;
}

void eval_command(const char *cmd){
	printf("evaluating: %s", cmd);
	int correct_instruction_found = 0;
	
	/* Checking what command is used */
	int inst_index = 0;
	for(inst_index = 0; inst_index < SORTH_INSTRUCTION_COUNT; inst_index++){
		char *instruction_in_cmd = (char*)strstr(cmd, sorth_instruction_set[inst_index]);
		if(instruction_in_cmd != NULL){
			correct_instruction_found = 1;
			break;
		}
	}

	/* Implement mechanism for dealing with syntax errors here */
	if(!correct_instruction_found){
		printf("eval_command(): syntax error in line: %s", cmd);
		return;
	}

	
	/* Implement command evaluation here */
	/* Design opportunity: either check for null pointer after stack operation, or not */
	if(0 == strcmp(sorth_instruction_set[0], sorth_instruction_set[inst_index])){
//		printf("push found\n");
		char *arg_string = get_arg_string(cmd, strlen(sorth_instruction_set[inst_index]));

		/*/
		 * In case stack seems to fill up with zeroes
		 * when having non integral input,
		 * atoi() (or related area) is to blame
		/*/
		int arguement = atoi(arg_string);
		printf("pushing %d into stack\n", arguement);
		globalstack = sorth_push(globalstack, arguement);
	}
	else if(0 == strcmp(sorth_instruction_set[1], sorth_instruction_set[inst_index])){
		//printf("pop found\n");
		globalstack = (s_atom*)sorth_pop(&globalstack); //warning: barely working implementation
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
	
	return;
}



s_atom* sorth_push(s_atom *globalstack, const int number){
	s_atom *output;
	output = insert(globalstack, number);
	if(output == NULL){
		printf("sorth.c: sorth_push() is unable to push %d onto stack\n");
		return NULL; /* Returning null as a means of error checking */
	}
	return output;
}

// modify return type for error chekcing
s_atom** sorth_pop(s_atom **globalstack){
	s_atom **sa = (s_atom**)delete_top(globalstack);
       	if(sa == NULL){
		printf("sorth.c: sorth_pop() is unable to pop topmost element ");
		printf("(%d) from stack\n", (*globalstack)->data);
		return NULL; /* Returning null as a means of error checking */
	}
	return sa;
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






int main(int argc, char *argv[]){
	printf("Starting sorth interpreter\n");

	
	char **filecontents = extract_to_string_array(argv[1]);
	int linecount = total_line_numbers("test.txt");

	printf("number of lines in file: %d\n", linecount);

	/* Main loop */
	for(long i = 0; i < total_line_numbers(argv[1]); i++){
		eval_command(filecontents[i]);
		printf("Contents of stack: ");
		print_stack(globalstack);
	}

	

	// Interactive mode, to be implemented later */
	//while(1){
	//	char command[513];
	//	printf(SORTH_PROMPT);
	//	gets(command);
	//	exec_command(command);
	//}
	
	return 0;
}

