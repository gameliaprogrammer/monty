#include "monty.h"

/**
*str_err - handles errors.
*@err: The error codes are the following:
*(10) ~> The number inside a node is outside ASCII bounds.
*(11) ~> The stack is empty.
*/
void str_err(int err, ...)
{
va_list arg_list;
int Line_num;

va_start(arg_list, err);
Line_num = va_arg(arg_list, int);
switch (err)
{
case 10:
fprintf(stderr, "L%d: can't pchar, value out of range\n", Line_num);
break;
case 11:
fprintf(stderr, "L%d: can't pchar, stack empty\n", Line_num);
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}

/**
*more_err - handles errors.
*@err: The error codes are the following:
*(6) => When the stack it empty for pint.
*(7) => When the stack it empty for pop.
*(8) => When stack is too short for operation.
*(9) => Division by zero.
*/
void more_err(int err, ...)
{
va_list arg_list;
char *func_ptr;
int Line_num;

va_start(arg_list, err);
switch (err)
{
case 6:
fprintf(stderr, "L%d: can't pint, stack empty\n",
va_arg(arg_list, int));
break;
case 7:
fprintf(stderr, "L%d: can't pop an empty stack\n",
va_arg(arg_list, int));
break;
case 8:
Line_num = va_arg(arg_list, unsigned int);
func_ptr = va_arg(arg_list, char *);
fprintf(stderr, "L%d: can't %s, stack too short\n", Line_num, func_ptr);
break;
case 9:
fprintf(stderr, "L%d: division by zero\n",
va_arg(arg_list, unsigned int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}

/**
*err - Prints appropiate error messages determined by their error code.
*@err: The error codes are the following:
*(1) => The user does not give any file or more than one file to the program.
*(2) => The file provided is not a file that can be opened or read.
*(3) => The file provided contains an invalid instruction.
*(4) => When the program is unable to malloc more memory.
*(5) => When the parameter passed to the instruction "push" is not an int.
*(6) => When the stack it empty for pint.
*(7) => When the stack it empty for pop.
*(8) => When stack is too short for operation.
*/
void err(int err, ...)
{
va_list arg_list;
char *func_ptr;
int Line_num;

va_start(arg_list, err);
switch (err)
{
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n",
va_arg(arg_list, char *));
break;
case 3:
Line_num = va_arg(arg_list, int);
func_ptr = va_arg(arg_list, char *);
fprintf(stderr, "L%d: unknown instruction %s\n", Line_num, func_ptr);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg_list, int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}
