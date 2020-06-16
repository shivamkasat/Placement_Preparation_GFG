#include <bits/stdc++.h>
using namespace std;

string add(string s1, string s2) {
  int n1 = s1.length();
  int n2 = s2.length();
  if (n1 > n2) {
    string add(n1 - n2 , '0');
    s2 = add + s2;
  } else if (n2 > n1) {
    string add(n2 - n1, '0');
    s1 = add + s1;
  }

  bool carry = 0;
  bool sum = 0;
  int len = max(n1, n2);
  string result(len, '0');
  int i = len - 1;
  while (i >= 0) {
    sum = carry ^ (s1[i] - '0') ^ (s2[i] - '0');
    carry = (carry & (s1[i] - '0')) | (carry & (s2[i] - '0')) | ((s1[i] - '0') & (s2[i] - '0'));
    result[i] = sum + '0';
    i--;
  }

  if (carry == 1) {
    result = "1" + result;
  }

  return result;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    cout<<add(s1,s2)<<endl;
  }
  return 0;
}
