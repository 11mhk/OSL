#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	int prn;
	struct node* next;
};
struct node* head;

void create(struct node* head)
{
	struct node* temp, * curr;
	int choice;
	temp = head;
	do
	{
		curr = (struct node*)malloc(sizeof(struct node*));
		printf("Enter prn fort the node: ");
		scanf_s("^%d", &curr->prn);
		curr->next = NULL;

		if (temp == NULL)
		{
			head = curr;
		}
		else
		{
			temp->next = curr;

		}



	}



}