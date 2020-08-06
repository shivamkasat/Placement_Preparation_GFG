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
  vector < vector < bool > >dp(s + 1, vector < bool >(p + 1, false));
  dp[0][0] = true;
  for (int i = 1; i < s + 1; i++) {
    dp[i][0] = false;
  }
  for (int j = 1; j <= p + 1; j++) {
    if (j == 1) {
      if (ptr[j - 1] == '*') {
        dp[0][j] = true;
      } else {
        dp[0][j] = false;
      }
    } else {
      if (ptr[j - 1] != '*') {
        dp[0][j] = false;
      } else if (ptr[j - 2] != '*') {
        dp[0][j] = false;
      } else {
        dp[0][j] = dp[0][j - 1];
      }
    }
  }

  for (int i = 1; i < s + 1; i++) {
    for (int j = 1; j < p + 1; j++) {
      if (str[i - 1] == ptr[j - 1] || ptr[j - 1] == '?') {
        dp[i][j] = dp[i - 1][j - 1];
      } else if (ptr[j - 1] == '*') {
        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
      }
    }
  }

  cout<<"printing dp table"<<endl;
  for (int i = 0; i < s + 1; i++) {
    for (int j = 0; j < p + 1; j++) {
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

  return dp[s][p];
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
