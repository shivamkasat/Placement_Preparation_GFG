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

Node * rotate(Node *head, int k)
{
	int count = 0;
	Node *temp = head;

	while (temp != NULL) {
		count++;
		temp = temp->next;
	}

	k = k % count;

	if (k == 0) {
		return head;
	}
	
	Node *newHead = NULL;
	Node *newEnd = NULL;
	Node *End = NULL;

	int mover = k;

	newEnd = head;
	End = head;

	//cout<<"mover = "<<mover<<endl;

	while (mover != 1) {
		newEnd = newEnd->next;
		mover--;
	}

	while (End->next != NULL) {
		End = End->next;
	}	

	newHead = newEnd->next;
	
	End->next = head;
	head = newHead;
	newEnd->next = NULL;
	
	return head;
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

	int k;
	cin>>k;

	head = rotate(head, k);

	printList(&head);
	return 0;
}
