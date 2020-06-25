TreeNode* constructTree(vector < int > &preorder, vector < int > &inorder, int &preIndex, int low, int high, unordered_map < int , int > &indexMap) {
  if (low > high) {
    return NULL;
  }

  int elem = preorder[preIndex];
  preIndex++;
  int inIndex = indexMap[elem];
  TreeNode *root = new TreeNode(elem);
  root->left = constructTree(preorder, inorder, preIndex, low, inIndex -1, indexMap);
  root->right = constructTree(preorder, inorder, preIndex, index + 1, high, indexMap);

  return root;
}

TreeNode *consTree(vector < int > &preorder, vector < int > &inorder) {
  int low = 0;
  int high = postOrder.size();
  int preIndex = 0;
  unordered_map < int, int > indexMap;
  for (int i = 0; i < high; i++) {
    indexMap[inorder[i]] = i;
  }

  TreeNode *root = NULL;
  root = constructTree(preorder, inorder, preIndex, low, high - 1, indexMap);

}
