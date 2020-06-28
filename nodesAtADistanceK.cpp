/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
  queue < TreeNode * > q;
  unordered_map < TreeNode *, vector < TreeNode * > > hmap;
  q.push(root);
  TreeNode *temp = NULL;

  while (q.empty() != true) {
    temp = q.front();
    q.pop();

    if (temp->left != NULL) {
      hmap[temp].push_back(temp->left);
      hmap[temp->left].push_back(temp);
      q.push(temp->left);
    }

    if (temp->right != NULL) {
      hmap[temp].push_back(temp->right);
      hmap[temp->right].push_back(temp);
      q.push(temp->right);
    }
  }


  unordered_set < TreeNode * > prev;
  unordered_set < TreeNode * > current;
  unordered_set < TreeNode * > next;

  current.insert(target);

  for (int i = 0; i < K; i++) {
    for (auto x : current) {
      for (auto y : hmap[x]) {
        if (prev.find(y) == prev.end()) {
          next.insert(y);
        }
      }
    }
    prev = current;
    current = next;
    next.clear();

  }

  vector < int > result;
  for (auto x : current) {
    result.push_back(x->val);
  }

  return result;
    }
};
