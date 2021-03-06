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
	"push", "pop", "add", "ifeq", "printa", "dup", "jump",
	"print"
};


#define SORTH_INSTRUCTION_COUNT sizeof(sorth_instruction_set)/sizeof(sorth_instruction_set[0])
#define WHILE_EVAL ("while evaluating command \"%s\", line %d\n", cmd, eli)

char* get_arg_string(const char *cmd, int instlen);

void get_argument(const char *cmd);
void eval_command(const char *cmd);


#endif
