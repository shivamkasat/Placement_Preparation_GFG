#include <bits/stdc++.h>
using namespace std;

void increment(Node *root, int diff) {
  if (root->left != NULL) {
    root->left->val += diff;
    increment(root->left, diff);
  } else {
    root->right->val += diff;
    increment(root->right);
  }
}

void convert(TreeNode *root) {
  if (root == NULL || root->left == NULL && root->right == NULL) {
    return;
  }

  int leftVal = 0;
  int rightVal = 0;

  convert(root->left);
  convert(root->right);

  if (root->left != NULL) {
    leftVal = root->left->val;
  }

  if (root->right != NULL) {
    rightVal = root->right->val;
  }

  int diff = leftVal + rightVal - root->data;

  if (diff == 0) {
    return;
  } else if (diff > 0) {
    root->data += diff;
  } else {
    //increment the left child recursively
    // if left child doesn't exit increment the right child
    increment(root, -1 * diff);
  }
}

TreeNode* solve (TreeNode *root) {
  convert(root);
}
