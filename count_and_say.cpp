#include <bits/stdc++.h>
using namespace std;

string findNthSequence(int n) {
  int i = 1;
  string result = "1";
  string base = "1";
  while (i < n) {
    result = "";
    int j = 0;
    int k = 0;
    while (j < base.length()) {
      while (k < base.length() && base[j] == base[k]) {
        k++;
      }
      result += to_string(k - j);
      result += base[j];
      j = k;
    }
    base = result;
    i++;
  }
  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    cout<<findNthSequence(n)<<endl;
  }
  return 0;
}
