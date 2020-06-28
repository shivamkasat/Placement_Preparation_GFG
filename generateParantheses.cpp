#include <bits/stdc++.h>
using namespace std;

void makeParantheses(int n, int &left, int &right, vector < string > &result, string &path) {
  if (path.size() == 2 * n) {
    result.push_back(path);
    return;
  }

  if (left < n) {
    path.push_back('(');
    left++;
    makeParantheses(n, left, right, result, path);
    left--;
    path.pop_back();
  }

  if (right <= left) {
    path.push_back(')');
    right++;
    makeParantheses(n, left, right, result, path);
    right--;
    path.pop_back();
  }

}

vector < string > generateParantheses(int n) {
  vector < string > result;
  string path = "";
  int left = 0;
  int right = 0;
  makeParantheses(n, left, right, result, path);
  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < string > result;
    result = generateParantheses(n);
    for (int i = 0; i < result.size(); i++) {
      cout<<result[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
