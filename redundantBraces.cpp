#include <bits/stdc++.h>
using namespace std;

bool checkRedundantBraces(string exp) {
  int n = exp.length();
  stack < char > st;
  bool hasOperator = false;
  for (int i = 0; i < n; i++) {
    if (exp[i] == ')') {
      hasOperator = false;
      while (st.top() != '(') {
        if (st.top() == '+' || st.top() == '-' || st.top() == '/' || st.top() == '*') {
          hasOperator = true;
        }
        st.pop();
      }
      st.pop();
      if (hasOperator == false) {
        return true;
      }
    } else {
      st.push(exp[i]);
    }
  }

  return false;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string exp;
    cin>>exp;
    cout<<checkRedundantBraces(exp)<<endl;
  }
  return 0;
}
