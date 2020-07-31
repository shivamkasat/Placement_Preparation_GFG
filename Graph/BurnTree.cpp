int Solution::solve(TreeNode *root, int B) {
  map < TreeNode *, TreeNode * > parent;
  parent[root] = NULL;
  queue < TreeNode * > q;
  q.push(root);
  TreeNode *current = NULL;
  TreeNode *burn = NULL;
  while (q.empty() != true) {
    current = q.front();
    if (current->val == B) {
      burn = current;
    }
    q.pop();
    if (current->left != NULL) {
      parent[current->left] = current;
      q.push(current->left);
    }

    if (current->right != NULL) {
      parent[current->right] = current;
      q.push(current);
    }
  }

  set < TreeNode * > hset;
  swap(q, queue < TreeNode * >);
  int timer = 1;

  q.push(burn);
  hset.insert(burn);
  if (burn->left != NULL) {
    hset.insert(burn->left);
    q.push(burn->left);
  }
  if (burn->right != NULL) {
    hset.insert(burn->right);
    q.push(burn->right);
  }
  if (parent[burn] != NULL) {
    hset.insert(parent[burn]);
    q.push(parent[burn]);
  }

  q.push(NULL);

  while (q.empty() != true) {
    current = q.front();
    q.pop();
    if (current == NULL) {
      timer++;
      if (q.size() == 0) {
        break;
      } else {
        q.push(NULL);
        continue;
      }
    }

    if (hset.find(parent[current]) == hset.end()) {
      q.push(parent[current]);
      hset.insert(parent[current]);
    }

    if (current->left != NULL && hset.find(current->left) == hset.end()) {
      q.push(current->left);
      hset.insert(current->left);
    }

    if (current->right != NULL && hset.find(current->right) == hset.end()) {
      q.push(current->right);
      hset.insert(current->right);
    }
  }

  return timer;

}
