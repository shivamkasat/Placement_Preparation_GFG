// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;

	Node(int x){
		data = x;
		left = right = NULL;
	}
};


void printSpiral(struct Node *root);

/* Driver program to test above functions*/
int main()
{
	int t;
	scanf("%d\n", &t);
	while (t--)
	{
		map<int, Node*> m;
		int n;
		scanf("%d\n",&n);
		Node *root = NULL;
		while (n--)
		{
			Node *parent;
			char lr;
			int n1, n2;
			scanf("%d %d %c", &n1, &n2, &lr);
			//  cout << n1 << " " << n2 << " " << (char)lr << endl;
			if (m.find(n1) == m.end())
			{
				parent = new Node(n1);
				m[n1] = parent;
				if (root == NULL)
					root = parent;
			}
			else
				parent = m[n1];

			Node *child = new Node(n2);
			if (lr == 'L')
				parent->left = child;
			else
				parent->right = child;
			m[n2]  = child;
		}

		printSpiral(root);
		cout<<endl;
	}
	return 0;
}

// } Driver Code Ends
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
   struct Node
   {
   int data;
   struct Node* left;
   struct Node* right;

   Node(int x){
   data = x;
   left = right = NULL;
   }
   }; */

void printSpiral(Node *root)
{
	if (root == NULL) {
		return;
	}

	stack < Node* > lrstack;
	stack < Node* > rlstack;

	printf("entered in printSpiral");
	printf("%d ", root->data);
	rlstack.push(root);

	while (rlstack.empty() != true || lrstack.empty() != true) {

		while (rlstack.empty() != true) {
			Node *temp = rlstack.top();
			rlstack.pop();

			if (temp->left != NULL) {
				printf("%d ", (temp->left)->data);
				lrstack.push(temp->left);
			}

			if (temp->right != NULL) {
				printf("%d ", (temp->right)->data);
				lrstack.push(temp->right);
			}
		}

		while (lrstack.empty() != true) {
			Node *temp = lrstack.top();
			lrstack.pop();

			if (temp->right != NULL) {
				printf("%d ", (temp->right)->data);
				rlstack.push(temp->right);
			}

			if (temp->left != NULL) {
				printf("%d ", (temp->left)->data);
				rlstack.push(temp->left);
			}
		}
	}
}

