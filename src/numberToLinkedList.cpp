/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES: 

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node *NODE;

struct node * numberToLinkedList(int N) {
	NODE head = NULL;
	if (N < 0)
		N *= -1;
	
	if (N == 0){
		head = (NODE)malloc(sizeof(NODE));
		head->num = N;
		head->next = NULL;
	}
	else{
		while (N > 0){
			NODE temp = (NODE)malloc(sizeof(NODE));
			temp->num = N % 10;
			temp->next = head;
			N /= 10;
			head = temp;
		}
	}
	return head;
}