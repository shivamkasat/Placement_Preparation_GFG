// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}




// } Driver Code Ends
//Structure of binary tree
/*struct Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/
// function should print the topView of the binary tree
void topView(struct Node *root)
{
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
		
		if (mmap.find(rank) == mmap.end()) {
			mmap[rank] = temp->data;
		}

		qn.pop();
		qr.pop();
	}


	for (auto itr = mmap.begin(); itr != mmap.end(); itr++) {
	       printf("%d ", (itr->second));	
	}
}



