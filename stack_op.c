#include "monty.h"

/**
*mul_nodes - Adds the top two elements of the stack.
*@stack: Pointer to a pointer pointing to top node of the stack.
*@Line_num: Interger representing the line number of of the opcode.
*/
void mul_nodes(stack_t **stack, unsigned int Line_num)
{
int sum;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
more_err(8, Line_num, "mul");

(*stack) = (*stack)->next;
sum = (*stack)->n * (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
* mod_nodes - return the reminder of division
* @stack: Pointer to a pointer pointing to the stack top node.
* @Line_num: Interger representing the line number of of the opcode.
*/
void mod_nodes(stack_t **stack, unsigned int Line_num)
{
int sum;

if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

more_err(8, Line_num, "mod");


if ((*stack)->n == 0)
more_err(9, Line_num);
(*stack) = (*stack)->next;
sum = (*stack)->n % (*stack)->prev->n;
(*stack)->n = sum;
free((*stack)->prev);
(*stack)->prev = NULL;
}
