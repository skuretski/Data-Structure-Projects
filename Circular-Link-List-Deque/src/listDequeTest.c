/*
 *  listDequeTest.c
 *
 *  Created on: Jan 26, 2015
 *  Author: Susan Kuretski (kuretsks@onid.oregonstate.edu)
 *  CS261-400, Assignment 3
 *  Description: Tests out circular linked list as a deque
 *  implementation
 */

#include "cirListDeque.h"
#include <stdio.h>

int main(){
	struct cirListDeque* q = createCirListDeque();
	addBackCirListDeque(q, (TYPE)1);
	addBackCirListDeque(q, (TYPE)2);
	addBackCirListDeque(q, (TYPE)3);
	addFrontCirListDeque(q, (TYPE)4);
	addFrontCirListDeque(q, (TYPE)5);
	addFrontCirListDeque(q, (TYPE)6);
	printCirListDeque(q);
	printf("%g\n", frontCirListDeque(q));
	printf("%g\n", backCirListDeque(q));
	removeFrontCirListDeque(q);
	removeBackCirListDeque(q);
	printCirListDeque(q);
	reverseCirListDeque(q);
	printCirListDeque(q);
	return 0;
}

