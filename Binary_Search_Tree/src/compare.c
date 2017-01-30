/*
 * compare.c
 *
 *  Created on: Feb 10, 2015
 *  Author: Susie Kuretski
 */
#include <stdio.h>
#include <assert.h>
#include "bst.h"
#include "structs.h"

/*----------------------------------------------------------------------------
 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

int compare(TYPE left, TYPE right)
{
	struct data *a, *b;
	a = (struct data *) left;
	b = (struct data *) right;
    if(a->number < b->number) return -1;
    if(a->number > b->number) return 1;
	return 0;
}

/* Prints value of TYPE by type casting. */
void print_type(TYPE curval)
{
	struct data *num = (struct data *)curval;
	printf("%d ", num->number);
}




