string serialize(Treenode *root) {
  queue < TreeNode * > q;
  string result = "";
  q.push(root);
  result += to_string(root->val);

  TreeNode *temp = NULL;

  while (q.empty() != true) {
    temp = q.front();
    q.pop();

    if (temp->left != NULL) {
      result += "_" + to_string(temp->left->val);
      q.push(temp->left);
    } else {
      result += "_N";
    }

    if (temp->right != NULL) {
      result += "_" + to_string(temp->right->val);
      q.push(temp->right);
    } else {
      result += "_N";
    }

  }
  int i = 0;
  for (i = result.size() - 1; i >= 0; i--) {
    if (result[i] != "N" || result[i] != "_") {
      break;
    }
  }

  result = s.substr(0, i);

  cout<<"result"<<endl;
  return result;
}

string findNextString(string &data) {
  for (int i = 0; i < data.size(); i++) {
    if (data[i] == '_') {
      break;
    }
  }

  string result = data.substr(0, j);
  if (j + 1 < data.size())
    data = data.substr(j + 1, data.size() - j);
  else {
    data = "";
  }
  return
}

TreeNode *deserialize(string data) {
  if (data.size() == 0) {
    return NULL;
  }
  string num = findNextString(data);

  TreeNode *root = new TreeNode (stoi(num));
  queue < TreeNode * > q;
  q.push(root);

  while (q.empty() != true) {
    temp = q.front();
    num = findNextString();
    q.pop();
    if (num == "N") {
      temp->left = NULL;
    } else {
      temp->left = new TreeNode (stoi(num));
      q.push(temp->left);
    }

    num = findNextString();
    if (num == "N") {
      temp->right = NULL;
    } else {
      temp->right = new TreeNode(stoi(num));
      q.push(temp->right);
    }
  }

  return root;

}
