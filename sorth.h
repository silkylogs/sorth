#ifndef SORTH_H
#define SORTH_H

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define SORTH_PROMPT "$ "
#define SORTH_INSTRUCTION_COUNT sizeof(sorth_instruction_set)/sizeof(sorth_instruction_set[0])

const char *sorth_instruction_set[] = {
	"push", "pop", "add", "ifeq", "print", "dup"
};

s_atom* sorth_push(s_atom *globalstack, int number);
void sorth_pop(s_atom *globalstack);
void sorth_add(s_atom *globalstack);
void sorth_ifeq();
void sorth_print();
void sorth_dup();
void eval_command(const char *cmd);

#endif
