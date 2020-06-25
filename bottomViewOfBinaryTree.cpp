// can also be solved using preorder traversal but level order traversel way is more easier.
#include<bits/stdc++.h>
using namespace std;

// Tree node class
struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
};

// Method that prints the bottom view.
void bottomView(Node *root);

Node* make_tree()
{
	int n;
	cin>>n;


	Node* head=NULL;
	queue <Node*> q;

	for( ; n>0 ; n-- )
	{
		int a,b;
		char c;
		cin>> a >> b >> c;

        if(!head)
		{
			head = new Node(a);
			q.push(head);
		}

        Node* pick = q.front();
		q.pop();

		if(c == 'L')
		{
			pick->left = new Node(b);
			q.push( pick->left );
		}

		n--;
		if(!n) break;

		cin>> a >> b >> c;

		if(c == 'R')
		{
			pick->right = new Node(b);
			q.push( pick->right );
		}
	}
	return head;
}

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {

     Node* root = make_tree();
     bottomView(root);
     cout << endl;
  }
  return 0;
}

// } Driver Code Ends
/* Tree node class

struct Node
{
    int data; //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    Node(int key)
    {
        data = key;
        left = right = NULL;
    }
}; */

// Method that prints the bottom view.
void bottomView(Node *root)
{
   // Your Code Here
   map < int, int > mmap;
	queue < Node * > qn;
	queue < int > qr;

	qn.push(root);
	qr.push(0);

	while (qn.empty() != true) {
		Node *temp = qn.front();
		int rank = qr.front();

		if (temp->left != NULL) {
			qn.push(temp->left);
			qr.push(rank - 1);
		}

		if (temp->right != NULL) {
			qn.push(temp->right);
			qr.push(rank + 1);
		}

		mmap[rank] = temp->data;


		qn.pop();
		qr.pop();
	}


	for (auto itr = mmap.begin(); itr != mmap.end(); itr++) {
	       printf("%d ", (itr->second));
	}
}
