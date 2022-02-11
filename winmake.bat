@echo off

set compiler= tcc
set output= sorth.exe
set sourceFiles= sorth.c stack.c filehandler.c

@echo on
%compiler% -o %output% %sourcefiles%

@echo off
echo _______________________________________________________________________
