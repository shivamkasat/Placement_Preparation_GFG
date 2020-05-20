// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

bool isSumTree(struct Node* node);

/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}

void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     cout << isSumTree(root) << endl;
  }
  return 0;
}

bool isSumTree(Node *root)
{
	if (root == NULL) {
		return true;
	} else if (root->left == NULL && root->right == NULL) {
		return true;
	}

	bool leftDeci = isSumTree(root->left);
	bool rightDeci = isSumTree(root->right);
	
	if(!(leftDeci == true && rightDeci == true)) {
		return false;
	} else {
		if (root->left != NULL && root->right != NULL) {
			if ((root->left)->data + (root->right)->data == root->data){
				root->data *= 2;
				return true;
			} else {
				return false;
			}
		} else if (root->left == NULL && root->right != NULL) {
			if ((root->right)->data == root->data) {
				return true;
			} else {
				return false;
			}
		} else {
			if ((root->left)->data == root->data) {
				return true;
			} else {
				return false;
			}
		}
	}

}
