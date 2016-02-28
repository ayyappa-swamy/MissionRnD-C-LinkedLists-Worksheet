/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

typedef struct node * NODE;

NODE getKthNode(NODE startNode, int K)
{
	if (startNode == NULL)
		return NULL;
	NODE temp = startNode;
	while ((K > 1) && (temp != NULL)){
		temp = temp->next;
		K--;
	}
	return temp;
}

struct node * removeEveryKthNode(struct node *head, int K) {
	NODE temp = head;
	
	if ((K <= 1) || (head == NULL))
		return NULL;
	else {
		while (temp != NULL){
			temp = getKthNode(temp, K - 1);
			if (temp == NULL)
				return head;
			else if (temp->next == NULL)
				return head;
			else {
				temp->next = (temp->next)->next;
				temp = temp->next;
			}
		}
	}
	return head;
}