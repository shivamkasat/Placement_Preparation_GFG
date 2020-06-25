// solution using preorder traversal but can also be solved using level order traversal and is more easier the other way.
void findBottomView(Node *root, int x, int y, int &maxLeft, int &maxRight, unordered_map  < int, pair < int, int > >  &hmap) {
  if (root == NULL) {
    return;
  }

  if (hmap.find(x) == hmap.end()) {
    hmap[x] = {y, root->val};
  } else {
    if (y >= hmap[x].first) {
      hmap[x] = {y, root->val}
    }
  }
  maxLeft = min(maxLeft, x);
  maxRight = max(maxRight, x);
  findBottomView(root->left, x - 1, y + 1, maxLeft, maxRight, hmap);
  findBottomView(root->right, x + 1, y + 1, maxLeft, maxRight, hmap);

}

vector < int > bottomView(Node *root) {
  unordered_map < int, pair < int , int > > hmap;
  int maxLeft = 0;
  int maxRight = 0;

  findBottomView(root, 0, 0, maxLeft, maxRight, hmap);
  for (int i = maxLeft; i <= maxRight; i++) {
    result.push_back(hmap[i].second);
  }

  return result;

}
