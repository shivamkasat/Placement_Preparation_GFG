// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


int maxDiff(Node *root);

// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if(currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if(currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ;
        getline(cin, s);
        Node* root = buildTree(s);
        
        cout<<maxDiff(root)<<endl;
    }
    return 0;
}

// } Driver Code Ends
/* A binary tree node

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
 */

/* Your are required to 
complete this method*/

int findMaxDiff(Node *root, int &maxiDiff) {
	if (root == NULL) {
		return INT_MIN;
	}

	if (root->left == NULL && root->right == NULL) {
		return INT_MIN;
	}

	int leftSum, rightSum, currentLeft, currentRight, leftDiff, rightDiff, diff;
	leftSum = rightSum = currentLeft = currentRight = leftDiff = rightDiff = diff = INT_MIN;

	leftSum = findMaxDiff(root->left, maxiDiff);

	if (root->left != NULL) {
		leftDiff = root->data - root->left->data;

		if (leftSum != INT_MIN) {
			currentLeft = leftSum + leftDiff;
		} else {
			currentLeft = leftDiff;
		}
	}

	rightSum = findMaxDiff(root->right, maxiDiff);

	if (root->right != NULL) {
		rightDiff = root->data - root->right->data;
		if (rightSum != INT_MIN) {
			currentRight = rightSum + rightDiff;
		} else {
			currentRight = rightDiff;
		}
	}

	diff = max(max(currentLeft, leftDiff), max(currentRight, rightDiff));
	maxiDiff = max(maxiDiff, diff);
	return diff;
}

int maxDiff(Node* root)
{
	//try solving using kadane's algorithm
	int maxiDiff = INT_MIN;
	int ri= findMaxDiff(root, maxiDiff);
	return maxiDiff;	
}

