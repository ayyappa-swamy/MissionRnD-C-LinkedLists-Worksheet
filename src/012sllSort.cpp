/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

typedef struct node* NODE;

void countSort(NODE head, int num1, int num2, int num3)
{
	NODE temp = head; 
	int countOfNum1 = 0, countOfNum2 = 0, countOfNum3 = 0;

	int i = 0;

	while (temp != NULL){
		if (temp->data == num1)
			countOfNum1++;
		else if (temp->data == num2)
			countOfNum2++;
		else if (temp->data == num3)
			countOfNum3++;

		temp = temp->next;
	}

	temp = head;
	
	for (i = 0; i < countOfNum1; i++, temp = temp->next){
		temp->data = num1;
	}
	for (i = 0; i < countOfNum2; i++, temp = temp->next){
		temp->data = num2;
	}
	for (i = 0; i < countOfNum3; i++, temp = temp->next){
		temp->data = num3;
	}

	return;
}

void sll_012_sort(struct node *head)
{
	countSort(head, 0, 1, 2);
	return;
}