#include <bits/stdc++.h>
using namespace std;

int checkMatch(const string &str,const string &ptr, int s, int p, vector < vector < int > > &dp) {
  if (s == 0 && p == 0) {
    return 1;
  } else if (s != 0 && p == 0) {
    return 0;
  } else if (s == 0 && p != 0) {
    if (p == 1) {
      if (ptr[p - 1] == '*') {
        return 1;
      } else {
        return 0;
      }
    } else {
      if (ptr[p - 1] != '*') {
        return 0;
      } else if (ptr[p - 2] != '*') {
        return 0;
      } else {
        return checkMatch(str, ptr, s, p - 1, dp);
      }
    }
  }

  if (dp[s][p] != -1) {
    return dp[s][p];
  }

  if (str[s - 1] == ptr[p - 1] || ptr[p - 1] == '?') {
    dp[s][p] = checkMatch(str, ptr, s - 1, p - 1, dp);
  } else if (ptr[p - 1] == '*') {
    bool first = checkMatch(str, ptr, s - 1, p, dp);
    bool second = checkMatch(str, ptr, s, p - 1, dp);
    dp[s][p] = (first == 1 || second == 1) ? 1 : 0;
  } else {
    dp[s][p] = 0;
  }

  return dp[s][p];

}

bool isMatch(const string str, const string ptr) {
  int s = str.length();
  int p = ptr.length();
  vector < vector < int > >dp(s + 1, vector < int >(p + 1, -1));
  int res = checkMatch(str, ptr, s, p, dp);
  return res == 1;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string str;
    string ptr;
    cin>>str;
    cin>>ptr;
    cout<<isMatch(str, ptr)<<endl;
  }
  return 0;
}
