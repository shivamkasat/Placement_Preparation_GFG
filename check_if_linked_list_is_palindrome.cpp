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

Node * reverseList(Node *headRef)
{
	Node *before = NULL;
	Node *current = NULL;
	Node *after = NULL;

	current = headRef;
	after = current->next;

	while (current->next != NULL) {
		current->next = before;
		before = current;
		current = after;
		after = after->next;
	}

	current->next = before;

	return current;
}

bool isPalindrome(Node *head)
{
	Node *temp = head;
	float count= 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}

	if (count == 1) {
		return true;
	}

	Node *middle = NULL;

	int n = ceil((float) (count/2));
	middle = head;
	while (n != 1) {
		middle = middle->next;
		n--;		
	}
	
	middle->next = reverseList(middle->next);

	/*
	printf("\nlets check\n");
	
	temp = head;
	while (temp != NULL) {
		printf("%d->", temp->data);
		temp = temp->next;
	}
	cout<<endl;	
	*/
	Node *first = head;
	Node *second = middle->next;


	while (second->next != NULL && first->next != NULL) {
		cout<<"{"<<first->data<<", "<<second->data<<"}"<<endl;
		if (first->data != second->data) {
			return false;
		}

		first = first->next;
		second = second->next;

	}
	
	
	if (first->data != second->data) {
		return false;
	}

	/*
	do {
		if (first->data == second->data) {
			return false;	
		}

		first = first->next;
		second = second->next;
	} while (first->next != NULL && second->next != NULL);

	*/


	return true;

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

	//printf("before reversing the list\n");
	//printList(headRef);
	bool result = isPalindrome(*headRef);
	cout<<result<<endl;
	return 0;
}
