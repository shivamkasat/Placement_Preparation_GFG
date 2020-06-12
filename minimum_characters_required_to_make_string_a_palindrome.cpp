#include <bits/stdc++.h>
using namespace std;

bool isPalin(string &s, int i , int j) {
  if (i > j) {
    return true;
  } else if (s[i] != s[j]) {
    return false;
  }

  return isPalin(s, i + 1, j - 1);
}

int findMinInsertion(string &s) {
  int n = s.length();
  int j = n - 1;
  while (j >= 0) {
    if (isPalin(s, 0, j)) {
      break;
    }
    j--;
  }
  return n - j - 1;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string str;
    cin>>str;
    cout<<findMinInsertion(str)<<endl;

  }
  return 0;
}
