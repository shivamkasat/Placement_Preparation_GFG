#include <bits/stdc++.h>
#define mod 10003
using namespace std;

int findAmazingCount(string s) {
  long long int count = 0;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'a' || s[i] == 'A' || s[i] == 'e' || s[i] == 'E' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U' ) {
      count = (count % mod + (n - i) % mod) % mod;
    }
  }

  return count % mod;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s;
    cin>>s;
    cout<<findAmazingCount(s)<<endl;
  }
  return 0;
}
