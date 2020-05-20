#include <bits/stdc++.h>

using namespace std;

typedef struct node {
	int data;
	struct node *next;
} Node;

Node * createNode(int data)
{
	Node *newNode = NULL;
	newNode = (Node *) malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void insertNode (Node **headRef, Node *comingNode)
{
	if (*headRef == NULL) {
		*headRef = comingNode;
		return;
	}

	Node *temp = *headRef;

	while (temp->next != NULL) {
		temp = temp->next;
	}

	temp->next = comingNode;
	return;
}

void printList(Node **headRef)
{
	Node *temp = *headRef;
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void reverseList(Node **headRef)
{
	Node *before = NULL;
	Node *current = NULL;
	Node *after = NULL;

	current = *headRef;
	after = current->next;

	while (current->next != NULL) {
		current->next = before;
		before = current;
		current = after;
		after = after->next;
	}

	current->next = before;

	*headRef = current;
}

int main()
{
	Node *temp = NULL;
	Node *head = NULL;
	Node **headRef = &head;

	int n;
	cin>>n;
	int data;
	for (int i = 0; i < n; i++) {
		cin>>data;
		temp = createNode(data);
		insertNode(headRef, temp);
	}

	printf("before reversing the list\n");
	printList(headRef);
	printf("\nafter reversing the list\n");
	reverseList(headRef);
	printList(headRef);
	return 0;
}
