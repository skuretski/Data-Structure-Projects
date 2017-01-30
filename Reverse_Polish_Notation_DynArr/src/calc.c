/* CS261-400, Winter 2015
 * Author: Susan Kuretski (kuretsks@onid.oregonstate.edu)
 * Date: 1/20/15
 * Description: Implementation of a Reverse Polish Notation
 * calculator with the use of a stack
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include "dynamicArray.h"

#define PI 	3.14159265
#define E	2.7182818

/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else
	{
		returnNum = strtod(s, &end);
		/* If there's anything in end, it's bad input */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}
/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their sum is pushed back onto the stack.
*/
void add(struct DynArr *stack)
{
	//Ensuring there are at least two elements
	if(sizeDynArr(stack) >= 2)
	{
		double sum, num1, num2 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		num2 = topDynArr(stack);
		popDynArr(stack);
		sum = num1 + num2;
		pushDynArr(stack, sum);
	}
	else if(sizeDynArr(stack) < 2)
	{
		printf("%s\n","Too few numbers for addition.");
	}
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 2)
	{
		double diff, num1, num2 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		num2 = topDynArr(stack);
		popDynArr(stack);
		diff = num1 - num2;
		pushDynArr(stack, diff);
	}
	else if(sizeDynArr(stack) < 2)
	{
		printf("%s\n","Too few numbers for subtraction.");
	}
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 2)
	{
		double quot, num1, num2 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		num2 = topDynArr(stack);
		popDynArr(stack);
		quot = num1/num2;
		pushDynArr(stack, quot);
	}
	else if(sizeDynArr(stack) < 2)
	{
		printf("%s\n","Too few numbers for division.");
	}
}
/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their product is pushed back onto the stack.
*/
void mult(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 2)
	{
		double prod, num1, num2 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		num2 = topDynArr(stack);
		prod = num1 * num2;
		pushDynArr(stack, prod);
	}
	else if(sizeDynArr(stack) < 2)
	{
		printf("%s\n","Too few numbers for multiplication.");
	}
}
/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped, x^y is calculated,
	and their resulting number is pushed back onto the stack.
*/
void power(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 2)
	{
		double power, num1, num2 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		num2 = topDynArr(stack);
		popDynArr(stack);
		power = pow(num1, num2);
		pushDynArr(stack, power);
	}
	else if(sizeDynArr(stack) < 2)
	{
		printf("%s\n","Too few numbers to calculate the power.");
	}
}
/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped, the square is
	calculated and then pushed back onto stack
*/
void squared(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 1)
	{
		double square, num1 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		square = num1 * num1;
		pushDynArr(stack, square);
	}
	else if(sizeDynArr(stack) < 1)
	{
		printf("%s\n","Too few numbers to find the square.");
	}
}
/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped, its cube is calculated
	and then pushed back onto stack
*/
void cubed(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 1)
	{
		double cube, num1 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		cube = num1 * num1 * num1;
		pushDynArr(stack, cube);
	}
	else if(sizeDynArr(stack) < 1)
	{
		printf("%s\n","Too few numbers to find the cube.");
	}
}
/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped, its absolute value
	is calculated and then pushed back onto the stack
*/
void abvalue(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 1)
	{
		double abvalue, num1 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		abvalue = abs(num1);
		pushDynArr(stack, abvalue);
	}
	else if(sizeDynArr(stack) < 1)
	{
		printf("%s\n","Too few numbers to find absolute value.");
	}
}
/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped off the stack,
	its square root is calculated and then pushed
	back onto stack
*/
void squareRoot(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 1)
	{
		double root, num1 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		root = sqrt(num1);
		pushDynArr(stack, root);
	}
	else if(sizeDynArr(stack) < 1)
	{
		printf("%s\n","Too few numbers to find the square root.");
	}
}
/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped off the stack,
	its exponent is calculated and then pushed
	back onto stack
*/
void exponent(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 1)
	{
		double expo, num1 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		expo = exp(num1);
		pushDynArr(stack, expo);
	}
	else if(sizeDynArr(stack) < 1)
	{
		printf("%s\n","Too few numbers to find the exponent.");
	}
}
/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped off the stack,
	its natural log is calculated and then pushed
	back onto stack
*/
void naturalLog(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 1)
	{
		double nat, num1 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		nat = log(num1);
		pushDynArr(stack,nat);
	}
	else if(sizeDynArr(stack) < 1)
	{
		printf("%s\n","Too few numbers to find natural log.");
	}
}
/*	param: stack the stack being manipulated
	pre: the stack contains at least one element
	post: the top element is popped off the stack,
	its common log is calculated and then pushed
	back onto stack
*/
void commonLog(struct DynArr *stack)
{
	if(sizeDynArr(stack) >= 1)
	{
		double common, num1 = 0;
		num1 = topDynArr(stack);
		popDynArr(stack);
		common = log10(num1);
		pushDynArr(stack, common);
	}
	else if(sizeDynArr(stack) < 1)
	{
		printf("%s\n","Too few numbers to find common log.");
	}
}
/*	param: num of input tokens (# command line args) and
	inputString (actual command line arg)
	pre: command line arguments
	post: takes in command line arguments in Reverse Polish
	Notation and calculates the results
	Notes: will flag errors for inaccurate input
*/
double calculate(int numInputTokens, char **inputString)
{
	int i;
	double *number;
	double zero = 0;
	number = &zero;
	double result = 0.0;
	char *s;
	struct DynArr *stack;
	int errorFlag = 0;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++)
	{
		s = inputString[i];
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			mult(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			squared(stack);
		else if(strcmp(s, "^3") == 0)
			cubed(stack);
		else if(strcmp(s, "abs") == 0)
			abvalue(stack);
		else if(strcmp(s, "sqrt") == 0)
			squareRoot(stack);
		else if(strcmp(s, "exp") == 0)
			exponent(stack);
		else if(strcmp(s, "ln") == 0)
			naturalLog(stack);
		else if(strcmp(s, "log") == 0)
			commonLog(stack);
		else
		{
			double num;
			if(isNumber(s, number) == 1)
			{
				num = *number;
				pushDynArr(stack, num);
			}
			else if(strcmp(s, "pi") == 0)
			{
				num = PI;
				pushDynArr(stack, num);
			}
			else if(strcmp(s, "e") == 0)
			{
				num = E;
				pushDynArr(stack, num);
			}
			else if(isNumber(s, number) == 0)
			{
				errorFlag = 1;
				printf("%s", s);
				printf("%s\n"," is an invalid operator/operand/format");
			}
		}
	}	//end for

	/*
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
	if(errorFlag != 0)
	{
		printf("%s\n", "Cannot produce results due to errors.");
		printf("%s\n", "Result will be zero by default.");
		return 0;
	}
	else if(sizeDynArr(stack) > 1)
	{
		printf("%s\n", "Too many numbers inputted.");
		printf("%s\n", "Result will be zero by default.");
		return 0;
	}
	else if(sizeDynArr(stack) < 1)
	{
		printf("%s\n", "Too few numbers inputted.");
		printf("%s\n", "Result will be zero by default.");
		return 0;
	}
	else
	{
		result = topDynArr(stack);
		popDynArr(stack);
		return result;
	}
}

int main(int argc , char** argv)
{
	int numOp = 0;
	double result;
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;
	if(argc > 1)
	{
		numOp = argc;
	}

	result = calculate(numOp,argv);
	printf("%s\n","The result: ");
	printf("%f\n", result);
	return 0;
}
