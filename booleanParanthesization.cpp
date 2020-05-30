#include <bits/stdc++.h>
#define mod 1003
using namespace std;

int findWays(string &s, int i, int j, bool isTrue, unordered_map < string , int > &hmap) {
  if (i == j) {
    if(isTrue == true) {
      if (s[i] == 'T') {
        return 1;
      } else {
        return 0;
      }
    } else {
      if (s[i] == 'F') {
        return 1;
      } else {
        return 0;
      }
    }
  }

  string key = to_string(i) + "_" + to_string(j) + "_" + to_string(isTrue);

  if (hmap.find(key) != hmap.end()) {
    return hmap[key];
  }


  int ans = 0;
  for (int k = i + 1; k < j; k += 2) {
    int leftTrue = findWays(s, i, k - 1, true, hmap);
    int leftFalse = findWays(s, i, k - 1, false, hmap);
    int rightTrue = findWays(s, k + 1, j, true, hmap);
    int rightFalse = findWays(s, k + 1, j, false, hmap);

    if (s[k] == '|') {
      if (isTrue == true) {
        ans += leftTrue * rightFalse + rightTrue * leftFalse + leftTrue * rightTrue;
      } else {
        ans += leftFalse * rightFalse;
      }
    } else if (s[k] == '&') {
      if (isTrue == true) {
        ans += leftTrue * rightTrue;
      } else {
        ans += leftFalse * rightTrue + leftTrue * rightFalse + leftFalse * rightFalse;
      }
    } else if (s[k] == '^') {
      if (isTrue == true) {
        ans += leftTrue * rightFalse + rightTrue * leftFalse;
      } else {
        ans += leftTrue * rightTrue + leftFalse * rightFalse;
      }
    }
  }

  hmap[key] = ans;
  return hmap[key];

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string exp;
    cin>>exp;
    int i = 0;
    int j = exp.length() - 1;
    unordered_map < string , int > hmap;
    cout<<findWays(exp, i, j, true, hmap)<<endl;
  }
}
