#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string s) {
  // cout<<"string s = "<<s<<endl;
  int i = 0;
  int n = s.length();
  int j = n - 1;

  while (i < j) {
    while (i < j && !((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))) {
      i++;
    }

    while (j > i && !((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z') || (s[j] >= '0' && s[j] <= '9'))) {
      j--;
    }

    // cout<<"comparing i = "<<i<<" "<<s[i]<<" and j = "<<j<<"and "<<s[j]<<endl;
    if ((s[i] == s[j]) || (s[i] == s[j] + 32) || (s[i] == s[j] - 32)) {
      i++;
      j--;
    } else {
      return 0;
    }

  }

  return 1;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s;
    getline(cin, s);
    cout<<isPalindrome(s)<<endl;
  }
  return 0;
}
