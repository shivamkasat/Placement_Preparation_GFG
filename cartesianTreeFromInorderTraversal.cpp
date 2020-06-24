TreeNode* cartesianTree(vector < int > &nums, int low, int high) {
  if (low > high) {
    return NULL;
  }

  int maxElem = nums[low];
  int maxIndex = low;

  for (int i = low; i <= high; i++) {
    if (nums[i] > maxElem) {
      maxElem = nums[i];
      maxIndex = i;
    }
  }

  TreeNode *root = new TreeNode(maxElem);
  root->left = cartesianTree(nums, low, maxIndex - 1);
  root->right = cartesianTree(nums, maxIndex + 1, high);

  return root;


}
TreeNode* contructTree(vector < int > &nums) {
  return caretesianTree(nums, 0, nums.size() - 1);
}

  // Old solution
  //
  //
  // TreeNode* makeTree(vector < int > &nums, int startIndex, int endIndex, unordered_map < int , int > &indexMap) {
  //     if (startIndex > endIndex) {
  //         return NULL;
  //     }
  //     priority_queue < int > maxHeap(nums.begin() + startIndex, nums.begin() + endIndex + 1);
  //     int maxElem = maxHeap.top();
  //     int maxElemIndex = indexMap[maxElem];
  //     TreeNode *root = new TreeNode(maxElem);
  //     // root->val = maxElem;
  //     // cout<<"root val = "<<root->val<<endl;
  //     root->left = makeTree(nums, startIndex, maxElemIndex - 1, indexMap);
  //     root->right = makeTree(nums, maxElemIndex + 1, endIndex, indexMap);
  //     return root;
  // }
  // TreeNode* Solution::buildTree(vector<int> &A) {
  //     unordered_map < int , int > indexMap;
  //     for (int i = 0; i < A.size(); i++) {
  //         indexMap[A[i]] = i;
  //     }
  //
  //     return makeTree(A, 0, A.size() - 1, indexMap);
  // }
