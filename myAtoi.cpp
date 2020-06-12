#include <bits/stdc++.h>
using namespace std;

int myAtoi(string s) {
  //ignore all possible white spaces
  int i = 0;
  int n = s.length();

  while (i < n && s[i] == ' ') {
    i++;
  }

  if (i >= n) {
    return 0;
  }

  //check if first non-whitespace character is +/- or interger
  //if not return zero

  if (!(s[i] == '+' || s[i] == '-' || (s[i] >= '0' && s[i] <= '9'))) {
    return 0;
  }

  bool isNeg = false;
  if (s[i] == '-') {
    isNeg = true;
    i++;
  } else if (s[i] == '+') {
    i++;
  }

  long long int num = 0;
  long long int intmin = (long long int )INT_MAX;
  intmin += 1;
  long long int intmax = (long long int) INT_MAX;

  while ((s[i] >= '0' && s[i] <= '9')) {
    num = num * 10 + (s[i] - '0');
    if (isNeg == true && num > intmin) {
      return INT_MIN;
    } else if (isNeg == false && num > intmax) {
      return INT_MAX;
    }
    i++;
  }

  if (isNeg == true) {
    num *= -1;
  }

  return num;

}

int main() {
  int test;
  cin>>test;
  cout<<endl;
  while(test--) {
    string str;
    getline(cin, str);
    cout<<myAtoi(str)<<endl;
  }
  return 0;
}
