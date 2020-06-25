//preorder traversal way
void findVerticalTraversal(TreeNode *root, int x, int y, int &maxLeft, int &maxRight, unordered_map < int, vector < pair < int, int > > &hmap) {
  if (root == NULL) {
    return;
  }

  hmap[x].push_back({y, root->val});
  if (maxLeft > x) {
    maxLeft = x;
  }

  if (maxRight < x) {
    maxRight = x;
  }


  findVerticalTraversal(root->left, x - 1, y + 1, maxLeft, maxRight, hmap);
  findVerticalTraversal(root->right, x + 1, y + 1, maxLeft, maxRight, hmap);
}

vector < vector < int > > verticalTraversal(TreeNode *root) {
  int maxLeft = 0;
  int maxRight = 0;
  unordered_map < int, vector < pair < int, int > > hmap;
  vector < vector < int > > result;
  if (root == NULL) {
    return result;
  }

  findVerticalTraversal(root, 0, 0, maxLeft, maxRight, hmap);
  vector < int > path;

  for (int i = maxLeft; i <= maxRight; i++) {
    sort(hmap[i].begin(), hmap[i].end());
    path.clear();
    for (int j = 0; j < hmap[i].size(); j++) {
      path.push_back(hmap[i][j].second);
    }
    result.push_back(path);
  }

  return result;
}

// level order traversal way
// incorrect and need lots of correction

vector < vector < int > > verticalorderTraversal(TreeNode *root) {
  vector < vector < int > > result;
  unordered_map < int, vector < int > > hmap;
  queue < TreeNode * > q1;
  queue < int > qr;

  if (root == NULL) {
    return result;
  }

  q1.push_back(root);
  qr.push_back(0);
  int maxLeft = 0;
  int maxRight = 0;

  TreeNode *temp = NULL;
  int rank = 0;

  while (q1.empty() != true) {
    temp = q1.front();
    rank = qr.front();
    maxLeft = min(maxLeft, rank);
    maxRight = max(maxRight, rank);

    path.push_back()
    q1.pop_front();
    qr.pop_front();

    if (temp->left != NULL) {
      q1.push_back(temp->left);
      qr.push_back(rank - 1);
    }

    if (temp->right != NULL) {
      q1.push_back(temp->right);
      qr.push_back(rank + 1);
    }
  }

  for (int i = maxLeft; i <= maxRight; i++) {
    result.push_back(hmap[i]);
  }



  return result;
}
