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

bool hasPathSum(Node *, int );

/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     if(n==1)
     {
        int a;
        cin>>a;
        cout<<a<<endl;
     }else{
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

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     int a;
     cin>>a;

     cout<<hasPathSum(root,a)<<endl;

  }
  }
  return 0;
}
// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


/*you are required to 
complete this function */
bool hasPathSum(Node *root, int sum)
{
	if (root->left == NULL && root->right == NULL && sum == root->data) {
		return true;
	} else if (root == NULL && root->right == NULL && sum != root->data) {
		return false;
	}

	bool leftDeci;
	bool rightDeci;
	
	if (root->left != NULL)
		leftDeci = hasPathSum(root->left, sum - root->data);
	if (root->right != NULL)
		rightDeci = hasPathSum(root->right, sum - root->data);

	if (root->left != NULL && root->right != NULL) {
		if (leftDeci == true || rightDeci == true) {
			return true;
		} else {
			return false;
		}

	} else if (root->left != NULL && root->right == NULL) {
		if (leftDeci == true) {
			return true;
		} else {
			return false;
		}
	} else if (root->right != NULL && root->left == NULL) {
		if (rightDeci == true) {
			return true;
		} else {
			return false;
		}
	}
}
