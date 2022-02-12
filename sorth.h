#ifndef SORTH_H
#define SORTH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


/*/
 * To define new syntax, add an instruction here,
 * then add another entry to the else if ladder.
/*/

const char *sorth_instruction_set[] = {
	"push", "pop", "add", "ifeq", "print", "dup"
};



#define SORTH_PROMPT "$ "
#define SORTH_INSTRUCTION_COUNT sizeof(sorth_instruction_set)/sizeof(sorth_instruction_set[0])

char* get_arg_string(const char *cmd, int instlen);

void get_argument(const char *cmd);
void eval_command(const char *cmd);
//void eval_command(const char *cmd, s_atom *globalstack);
s_atom* sorth_push(s_atom *globalstack, int number);
//void sorth_pop(s_atom *globalstack);
s_atom** sorth_pop(s_atom **globalstack);
void sorth_add(s_atom *globalstack);
void sorth_ifeq();
void sorth_print();
void sorth_dup();

#endif
