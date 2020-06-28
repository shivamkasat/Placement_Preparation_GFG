#include <bits/stdc++.h>
using namespace std;

void makeCombs(int n, int k, vector < vector < int > > &combs, vector < int > &path, int index) {
  if (path.size() == k) {
    combs.push_back(path);
    return;
  } else if (index > n) {
    return;
  }

  path.push_back(index);
  makeCombs(n, k, combs, path, index + 1);
  path.pop_back();

  makeCombs(n, k, combs, path, index + 1);


}

vector < vector < int > > findCombs(int n, int k) {
  vector < vector < int > > combs;
  vector < int > path;
  makeCombs(n, k, combs, path, 1);
  return combs;
}


int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector < vector < int > > combs;

    combs = findCombs(n, k);

    for (int i = 0; i < combs.size(); i++) {
      for (int j = 0; j < combs[i].size(); j++) {
        cout<<combs[i][j]<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
