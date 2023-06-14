#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	struct _Node* next;
	int data;
}Node;

int InsertFirst(Node* start, int val);
int InsertLast(Node* start, int val);
int InsertAfter(Node* start, int after, int val);
int DeleteNode(Node* start, int val);
int ViewList(Node* start);

int main(void) {
	Node* head = malloc(sizeof(Node));
	if (head == NULL) return -1;

	head->next = NULL;

	int op1, op2, after, val;
	int length = 0;

	printf("==================================\n");
	printf("1: Insert, 2: Delete, 0: Terminate\n");
	printf("==================================\n");



	for (;;) {
		ViewList(head);

		printf("Select an operation: ");
		scanf_s("%d", &op1);

		switch (op1) {
		case 1:
			printf("Choose a value to insert: ");
			scanf_s("%d", &val);

			printf("1: Insert first, 2: Insert last, 3: Insert after\n");
			printf("Select an insertion operation: ");
			scanf_s("%d", &op2);

			if (op2 == 1) InsertFirst(head, val);
			else if (op2 == 2) InsertLast(head, val);

			else if (op2 == 3) {
				printf("Choose a node to insert after: ");
				scanf_s("%d", &after);
				InsertAfter(head, after, val);
			}
			else printf("Invalid operation!!\n");

			break;

		case 2:
			printf("Choose a value to delete: ");
			scanf_s("%d", &val);

			DeleteNode(head, val);
			break;

		case 0:
			return 0;
		}
	}

}

int InsertLast(Node* start, int val) {
	Node* ptr = start;
	Node* NewNode = malloc(sizeof(Node));
	if (NewNode == NULL) return -1;

	while (ptr->next != NULL) {
		ptr = ptr->next;
	}

	NewNode->data = val;
	NewNode->next = NULL;

	ptr->next = NewNode;

	return 0;
}

int InsertAfter(Node* start, int after, int val) {
	Node* ptr = start,* preptr = ptr;
	Node* NewNode = malloc(sizeof(Node));
	int state = 0;

	if (NewNode == NULL) return -1;

	while (preptr->data != val && ptr != NULL) {
		preptr = ptr;
		ptr = ptr->next;
		state = 1;
	}

	if (state == 1) {
		preptr->next = NewNode;

		NewNode->data = val;
		NewNode->next = ptr;
	}
	else if (state == 0) {
		printf("Invalid operation!!\n");
	}


	return 0;
}

int InsertFirst(Node* start, int val) {
	Node* ptr = start->next,* preptr = start;
	Node* NewNode = malloc(sizeof(Node));
	if (NewNode == NULL) return -1;

	NewNode->data = val;
	NewNode->next = ptr;
	preptr->next = NewNode;
	return 0;
}

int ViewList(Node* start) {
	Node* ptr = start->next;

	printf("Current Linked List: ");

	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");

	return 0;
}

int DeleteNode(Node* start, int val) {
	Node* ptr = start->next,* preptr = ptr;
	int state = 0;

	while (ptr != NULL && ptr->data != val) {
		preptr = ptr;
		ptr = ptr->next;
	}

	if (ptr == NULL) {
		printf("Invalid operation!!\n");
	}
	else {
		preptr->next = ptr->next;

		if (ptr == start->next) {
			start->next = ptr->next;
		}

		free(ptr);
	}

	return 0;
}