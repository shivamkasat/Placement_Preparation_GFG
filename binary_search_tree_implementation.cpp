#include <bits/stdc++.h>

using namespace std;

typedef struct node {
	int data;
	struct node *left = NULL;
	struct node *right = NULL;
} Node;

Node* createNode(int data)
{
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;	
}

Node* insertNode (Node *root, Node *comingNode)
{
	if (root == NULL) {
		root = comingNode;
		return root;
	}

	if(comingNode->data < root->data) {
		root->left = insertNode(root->left, comingNode);
	} else {
		root->right = insertNode(root->right, comingNode);
	}
	
	return root;
}

void preOrder(Node *root)
{
	if (root == NULL) {
		return;
	}

	printf("%d ", root->data);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node *root)
{
	if (root == NULL) {
		return;
	}

	inOrder(root->left);
	printf("%d ", root->data);
	inOrder(root->right);
}

void levelOrder(Node *root) {
	if (root == NULL) {
		return;
	}

	queue < Node * > q1;
	q1.push(root);

	while (q1.empty() != true) {
		Node *elem = q1.front();
		q1.pop();

		if (elem->left != NULL) {
			q1.push(elem->left);
		}

		if (elem->right != NULL) {
			q1.push(elem->right);
		}

		printf("%d ",elem->data);
	}
}
int findMin(Node *root)
{
	if (root->left == NULL) {
		return root->data;
	}

	findMin(root->left);
}

Node* deleteNode(Node *root, int data)
{
	if (root == NULL) {
		return root;
	} else if (data < root->data) {
		root->left = deleteNode(root->left, data);
	} else if (data > root->data) {
		root->right = deleteNode(root->right, data);
	} else {
		if (root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		} else if (root->left == NULL) {
			Node *temp = root;
			root = root->right;
			free(temp);
			temp =  NULL;
		} else if (root->right == NULL) {
			Node *temp = root;
			root = root->left;
			free(temp);
			temp = NULL;
		} else {
			int min = findMin(root->right);
			root->data = min;
			root->right = deleteNode(root->right, min);
		}
	}
	return root;
}

int main()
{
	Node *root = NULL;
	int n;
	scanf("%d", &n);
	int data;
	Node *temp = NULL;
	for (int i = 0; i < n; i++) {
		scanf("%d", &data);
		temp = createNode(data);
		root = insertNode(root, temp);
	}
	
	printf("preOrder is as follows\n");
	preOrder(root);
	printf("\ninOrder is as follows\n");
	inOrder(root);
	printf("\nlevel order is as follows\n");
	levelOrder(root);
		//deleteNode(root,15);
	//inOrder(root);
	return 0;
}
