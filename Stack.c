#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Node {
	struct _Node* next;
	int data;
}Node;

int push(Node* start, int val);
int pop(Node* start);
int view(Node* start);
int peek(Node* start);
int init(Node* start);

int main(void) {
	Node* head = malloc(sizeof(Node));
	if (head == NULL) return -1;

	int op ,val;
	bool state = true;

	head->next = NULL;

	printf("==============================================\n");
	printf("==1: push, 2: pop, 3: peek, 4: init, 0: exit==\n");
	printf("==============================================\n");

	while (state == true) {
		view(head);

		printf("Choose an operation: ");
		scanf_s("%d", &op);

		switch (op) {
		case 1:
			printf("Choose a value to insert: ");
			scanf_s("%d", &val);

			push(head, val);
			break;

		case 2:
			pop(head);
			break;

		case 3:
			peek(head);
			break;
		
		case 4:
			init(head);
			break;

		case 0:
			state = false;
			break;

		default:
			printf("Invalid operation!\n");
			break;
		}
	}

	return 0;
}

int view(Node* start) {
	Node* ptr = start->next;

	printf("Current stack: ");

	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");

	return 0;
}

int push(Node* start, int val) {
	Node* ptr = start;
	Node* newnode = malloc(sizeof(Node));
	if (newnode == NULL) return -1;

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	ptr->next = newnode;

	newnode->data = val;
	newnode->next = NULL;

	return 0;
}

int pop(Node* start) {
	Node* ptr = start,* preptr = ptr;

	if (ptr->next == NULL) {
		printf("Stack underflow!!\n");
		return 0;
	}

	while (ptr->next != NULL) {
		preptr = ptr;
		ptr = ptr->next;
	}

	preptr->next = NULL;
	free(ptr);

	return 0;
}

int peek(Node* start) {
	Node* ptr = start;

	if (ptr->next == NULL) {
		printf("Stack is empty!!\n");
	}

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	printf("Top element: %d", ptr->data);

	return 0;
}

int init(Node* start) {
	Node* temp = start->next, * lst = NULL;

	while (temp != NULL) {
		lst = temp->next;
		free(temp);
		temp = lst;
	}

	start->next = NULL;

	return 0;
}