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


int getNthFromLast(Node *head, int n)
{
	stack < int > st;
	Node *temp = head;

	while (temp != NULL) {
		st.push(temp->data);
		temp = temp->next;
	}

	int data;
	for (int i = 0; i < n; i++) {
		if (st.empty() != true) {
			data = st.top();
			st.pop();
		} else {
			data = -1;
		}
	}

	return data;


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
	cout<<getNthFromLast(head, k);
	return 0;
}
