#include <bits/stdc++.h>
using namespace std;

int dplcs(string s1, string s2) {
  int ans = -1;
  int n1 = s1.length();
  int n2 = s2.length();

  vector < vector < int > >dp(n1 + 1, vector < int >(n2 + 1, -1));

  for (int i = 0; i < n1; i++) {
    for (int j = 0; j < n2; j++) {
      if (i == 0 || j == 0) {
        dp[i][j] = 0;
        continue;
      }

      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        ans = max(ans, dp[i][j]);
      } else {
        dp[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < n1 + 1; i++) {
    for (int j = 0; j < n2 + 1; j++) {
      printf("%3d",dp[i][j]);
    }
    printf("\n");
  }
  
  return ans;
}

int findlcs(string s1, string s2, int n1, int n2, int &currentLength) {
  if (n1 == 0 || n2 == 0) {
    currentLength = 0;
    return 0;
  }

  int maxLength = 0;

  if (s1[n1 - 1] == s2[n2 - 1]) {
    maxLength = findlcs(s1, s2, n1 - 1, n2 - 1, currentLength);
    currentLength += 1;
    maxLength = max(maxLength, currentLength);
    return maxLength;
  } else {
    maxLength = max(findlcs(s1, s2, n1 - 1, n2, currentLength),  findlcs(s1, s2, n1, n2 - 1, currentLength));
    currentLength = 0;
    return maxLength;
  }

}

int lcs(string s1, string s2) {
  int n1 = s1.length();
  int n2 = s2.length();
  int maxLength = 0;
  int currentLength = 0;
  maxLength = findlcs(s1, s2, n1, n2, currentLength);
  cout<<"maxLength is normal "<<maxLength<<endl;
  int currentLengt = 0;
  cout<<"maxLength dp "<<dplcs(s1, s2)<<endl;
  return maxLength;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    string s2;
    cin>>s1>>s2;
    int result = lcs(s1, s2);
  }

  return 0;
}
