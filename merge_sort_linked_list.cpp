#include<bits/stdc++.h>

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

void insertNode(Node **headRef, Node *comingNode)
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
}

void printList(Node **headRef) {
	Node *temp = *headRef;
	while (temp != NULL) {
		cout<<temp->data<<" ";
		temp = temp->next;
	}

	cout<<endl;
}

void merge(Node **headRef, Node *low, Node *mid, Node *high) 
{
	Node *temp1 = low;
	Node *temp2 = mid->next;
	vector < int > vec;
	while (temp1 != mid->next && temp2 != NULL) {
		if (temp1->data <= temp2->data) {
			vec.push_back(temp1->data);
			temp1 = temp1->next;
		} else {
			vec.push_back(temp2->data);
			temp2 = temp2->next;
		}
	}

	while (temp1 != mid->next) {
		vec.push_back(temp1->data);
		temp1 = temp1->next;
	}

	while (temp2 != NULL) {
		vec.push_back(temp2->data);
		temp2 = temp2->next;
	}

	Node *temp = low;
	for (int i = 0; i < vec.size(); i++) {
		temp->data = vec[i];
		temp = temp->next;
	}
}

void merge_sort(Node **headRef, Node *low, Node *high)
{
	if (low == high) {
		return;
	}

	Node *singlePtr = low;
	Node *doublePtr = low;

	while (doublePtr != high && (doublePtr->next) != high) {
		singlePtr = singlePtr->next;
		doublePtr = (doublePtr->next)->next;
	}

	Node *mid = singlePtr;

	merge_sort(headRef, low, mid);
	merge_sort(headRef, mid->next , high);
	merge(headRef, low, mid, high);
}

int main()
{
	int n;
	cin>>n;
	int data;
	Node *temp = NULL;
	Node *head = NULL;

	for (int i = 0; i < n; i++) {
		cin>>data;
		temp = createNode(data);
		insertNode(&head, temp);
	}

	Node *high = NULL;

	high = head;

	while (high->next != NULL) {
		high = high->next;
	}

	printf("before sorting\n");
	printList(&head);
	
	printf("after sorting\n");
	merge_sort(&head, head, high);
	printList(&head);
	
	return 0;
}
