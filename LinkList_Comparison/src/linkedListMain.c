/*
 * linkedListMain.c
 *
 *  Created on: Jan 26, 2015
 *  Author: Susie Kuretski
 */

#include "linkedList.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
	struct linkedList *b;
	b = createLinkedList();
	printf("%d\n", isEmptyList(b));
	addFrontList(b, 3);
	addBackList(b, 4);
	printf("%d\n", frontList(b));
	printf("%d\n", backList(b));
	addFrontList(b, 10);
	addBackList(b, 23);
	addFrontList(b, 30);
	addBackList(b, 32);
	_printList(b);
	removeFrontList(b);
	removeBackList(b);
	printf("%d\n", containsList(b, 4));
	printf("%d\n", containsList(b, 32));
	_printList(b);
	return 0;
}
