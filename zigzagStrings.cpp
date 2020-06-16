#include <bits/stdc++.h>
using namespace std;

string zigzag(string s, int lines) {
  if (lines == 1) {
    return s;
  }
  vector < string > mat(lines);
  mat[0].push_back(s[0]);
  int n = s.length();
  int i = 1;
  while (i < n) {
    for (int j = 1;i < n && j < lines; j++, i++) {
      mat[j].push_back(s[i]);
    }

    for (int j = lines - 2;i < n && j >= 0; j--, i++) {
      mat[j].push_back(s[i]);
    }
  }

  string result = "";
  for (int i = 0; i < lines; i++) {
    result += mat[i];
  }

  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s;
    cin>>s;
    int lines;
    cin>>lines;
    cout<<zigzag(s, lines)<<endl;
  }
  return 0;
}
