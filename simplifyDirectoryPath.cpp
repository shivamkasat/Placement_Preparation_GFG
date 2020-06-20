#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string &s) {
  stack < string > st;
  int n = s.length();
  int i = 0;
  int j = 1;
  string temp = "";
  while (i != n) {
    j = i + 1;
    while (j < n && s[j] != '/') {
      j++;
    }

    if (i + 1 == j) {
      i = i + 1;
      continue;
    }

    temp = s.substr(i, j - i);
    // cout<<"i = "<<i<<" j = "<<j<<" temp = "<<temp<<endl;

    if (temp == "/.") {
      i = j;
      continue;
    } else if (temp == "/..") {
      if (st.empty() != true) {
        st.pop();
      }
    } else {
      st.push(temp);
    }

    i = j;

  }

  stack < string > st2;
  string result = "";
  while (st.empty() != true) {
    st2.push(st.top());
    st.pop();
  }

  while (st2.empty() != true) {
    result += st2.top();
    st2.pop();
  }

  // reverse(result.begin(), result.end());

  // cout<<reuslt;

  if (result == "") {
    result += "/";
  }
  return result;



}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s;
    cin>>s;

    cout<<simplifyPath(s)<<endl;

  }
  return 0;
}
