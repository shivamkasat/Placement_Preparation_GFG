#include <bits/stdc++.h>
using namespace std;

vector < int > findPerm(const string s, int n) {
  int lower = 1;
  int upper = n;
  vector < int > result(n, 0);
  for (int i = n - 1; i > 0; i--) {
    if (s[i - 1] == 'D') {
      result[i] = lower++;
    } else {
      result[i] = upper--;
    }
  }
  result[0] = lower;
  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    string s1;
    cin>>s1;
    vector < int > result;
    result = findPerm(s1, n);
    for (int i = 0; i < result.size(); i++) {
      cout<<result[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
