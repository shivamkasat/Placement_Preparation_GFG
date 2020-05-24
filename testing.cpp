#include <bits/stdc++.h>
using namespace std;

int main() {
  int leftVal = 0;
  int rightVal = 3;
  int val = -1;

  if (leftVal != 0 && rightVal != 0) {
    val = leftVal + rightVal;
  } else if (leftVal != 0) {
    val = leftVal;
  } else if (rightVal != 0) {
    val = rightVal;
  }

  cout<<val;

  return 0;
}
