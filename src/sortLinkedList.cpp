/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node * NODE;

void partitionSll(NODE head, NODE *left, NODE *right)
{
	NODE fastPtr = head, slowPtr;

	if ((head == NULL) || (head->next == NULL)){
		*left = head;
		*right = NULL;
		return;
	}
	else if (head->next->next == NULL){
		*left = head;
		*right = head->next;
		(*left)->next = NULL;
	}
	else {
		slowPtr = fastPtr;
		while ((fastPtr != NULL) && (fastPtr->next != NULL)){
			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;
		}

		*left = head;
		*right = slowPtr->next;
		slowPtr->next = NULL;
	}
	return;
}

NODE sortWhileMerge(NODE left, NODE right)
{
	NODE mergedList;

	if (left == NULL) return right;
	else if (right == NULL) return left;
	else{
		if (left->num <= right->num){
			mergedList = left;
			mergedList->next = sortWhileMerge(left->next, right);
		}
		else {
			mergedList = right;
			mergedList->next = sortWhileMerge(left, right->next);
		}
	}

	return mergedList;
}

void mergeSortSll(NODE* head)
{

	NODE headTemp = *head;
	if ((*head == NULL) || ((*head)->next == NULL))
		return;

	NODE left, right;
	partitionSll(headTemp, &left, &right);

	mergeSortSll(&left);
	mergeSortSll(&right);

	*head = sortWhileMerge(left, right);
	return;
}

struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	else if (head->next == NULL)
		return head;
	else {
		mergeSortSll(&head);
	}

	return head;
}





