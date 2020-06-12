#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
  // if first character non-interger or is not(+/-/.)
  int i = 0;
  int n = s.length();
  if (!((s[i] >= '0' && s[i] <= '9') || (s[i] == '+') || (s[i] == '-') || (s[i] == '.'))) {
    return false;
  }

  if (s[i] == '+' || s[i] == '-') {
    i++;
  }

  if (n == 1 && s[0] == '.') {
    return false;
  }

  if (i == n) {
    return false;
  }

  int dotCount = 0;

  // now we are expecting integers to occur if something other than integer or . occurs break
  // not more than one dot should appear
  while ((i < n) && ((s[i] >= '0' && s[i] <= '9') || (s[i] == '.' && dotCount < 1))) {
    if (s[i] == '.') {
      dotCount++;
    }
    i++;
  }

  if (i == n) {
    return true;
  }

  if (i < n && s[i] != 'e') {
    return false;
  } else if (i < n && s[i] == 'e' && i == n - 1) {
    return false;
  }

  i++;

  if ((i < n) && !((s[i] >= '0' && s[i] <= '9') || (s[i] == '+') || (s[i] == '-'))) {
    return false;
  }

  if ((i < n) && (s[i] == '+' || s[i] == '-')) {
    i++;
  }

  while ((i < n)) {
    if (!(s[i] >= '0' && s[i] <= '9')) {
      return false;
    }
    i++;
  }

  return true;





  // check the break point if it is something other than e return false
  // if it is e
  // the next char can be a +/- or an integer
  // now keep interating if something other than integer occurs return false
  // return true at last
}

int main() {
  int test;
  cin>>test;
  string newline;
  getline(cin, newline);
  while (test--) {
    string str;
    // cin>>str;
    getline(cin,str);
    cout<<isValid(str)<<endl;
  }
  return 0;
}
