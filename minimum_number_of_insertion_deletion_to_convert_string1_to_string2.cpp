#include <bits/stdc++.h>
using namespace std;

int transReq(string s1, string s2) {
  int n1 = s1.length();
  int n2 = s2.length();
  vector < vector < int > >dp(n1 + 1, vector < int >(n2 + 1, -1));
  for (int i = 0; i < n1 + 1; i++) {
    dp[i][0] = i;
  }

  for (int j = 0; j < n2 + 1; j++) {
    dp[0][j] = j;
  }

  for (int i = 1; i < n1 + 1; i++) {
    for (int j = 1; j < n2 + 1; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
      }
    }
  }

  return dp[n1][n2];
}

void indiOpr(string s1, string s2) {
  int n1 = s1.length();
  int n2 = s2.length();
  vector < vector < int > >dp(n1 + 1, vector < int >(n2 + 1, -1));
  for (int i = 0; i < n1 + 1; i++) {
    dp[i][0] = 0;
  }

  for (int j = 0; j < n2 + 1; j++) {
    dp[0][j] = 0;
  }

  for (int i = 1; i < n1 + 1; i++) {
    for (int j = 1; j < n2 + 1; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  int lcsLen = dp[n1][n2];
  printf("lcsLen %d\n",lcsLen );
  printf("Intertion requiered %d \n",n1 - lcsLen);
  printf("Deletion Required %d \n",n2 - lcsLen);

}



int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    cout<<transReq(s1, s2)<<endl;
    indiOpr(s1, s2);
  }
  return 0;
}
