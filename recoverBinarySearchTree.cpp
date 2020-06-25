void findNodes(TreeNode *root, TreeNode *first, TreeNode *last, TreeNode *prev) {
  if (root == NULL) {
    return;
  }

  findNodes(root->left, first, last, prev);
  if (first == NULL && prev->val > root->val) first = prev;
  if (first != NULL && prev-> > root->val) last = root;
  prev = root;
  findNodes(root->right, first, last, prev);
}

vector < int > recoverBST(TreeNode *root) {
  TreeNode *first = NULL;
  TreeNode *last = NULL;
  TreeNode *prev = new TreeNode(INT_MIN);
  // int prev = INT_MIN;

  findNodes(root, first, last, prev);
  // vector < int > result = {first->val, last->val};
  swap(first->val , last->val);
  return result;
}
