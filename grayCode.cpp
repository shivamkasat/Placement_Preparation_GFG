#include <bits/stdc++.h>
using namespace std;

void findNums(int n, vector < int > &result, string &path, bool &alt) {
  if (path.length() == n) {
    result.push_back(stoi(path, nullptr, 2));
    return;
  }

  if (alt == true) {
    path.push_back('0');
    findNums(n, result, path, true);
    path.pop_back();
    path.push_back('1');
    findNums(n, result, path, false);
    path.pop_back();
  } else if (alt == false ) {
    path.push_back('1');
    findNums(n, result, path, true);
    path.pop_back();
    path.push_back('0');
    findNums(n, result, path, false);
    path.pop_back();
  }

}


vector < int > findGrayOrder(int n) {
  vector < int > result;
  string path = "";
  bool alt = true;
  findNums(n, result, path, alt);
  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > result;
    result = findGrayOrder(n);
    for (auto x : result) {
      cout<<x<<" ";
    }
    cout<<endl;
  }
  return 0;
}
