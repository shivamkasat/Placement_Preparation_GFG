#include <bits/stdc++.h>
using namespace std;

string calcMulti(string &s1, int num) {
  string result = "0" + s1;
  cout<<"result string is "<<result<<endl;
  int carry = 0;
  int base = 0;
  char basech;
  for (int i = s1.length() - 1; i >= 0; i--) {
    // cout<<s1[i] - '0'<<"is the number"<<endl;
    base = (s1[i] - '0') * num + carry;
    // cout<<base<<"is the base"<<endl;
    result[i + 1] = char((base % 10)) + 48;
    cout<<char(base % 10) + 48 <<"will be stored"<<endl;
    carry = base / 10;
  }
  result[0] = char(carry) + 48;
  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    cin>>s1;
    int n;
    cin>>n;
    int num;
    for (int i = 0; i < n; i++) {
      cin>>num;
      cout<<calcMulti(s1, num)<<endl;
    }
  }
}
