# Sorth
Sorth is an interpreted, stack based, typeless language implemented from a [stackoverflow answer](https://stackoverflow.com/questions/6887471/how-would-i-go-about-writing-an-interpreter-in-c), alongside some extra features  
Current status: `development in progress`


## Syntax
The language has a stack and 8 instructions:  
`push <num>` push a number on to the stack  
`pop` pop off the first number on the stack  
`add` pop off the top 2 items on the stack and push their sum on to the stack.  
`ifeq <lineno>` examine the top of the stack, if it's 0, continue, else, jump to line number  
`jump <lineno>` jump to a line number  
`print` print the value at the top of the stack  
`printa` print the ascii equivalent of the value at the top of the stack  
`dup` push a copy of what's at the top of the stack back onto the stack  

Comments can be added via prepending the `#` symbol before a single line comment
