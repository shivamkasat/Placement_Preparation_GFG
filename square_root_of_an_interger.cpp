#include <bits/stdc++.h>
using namespace std;

int sqroot(int n) {
  if (n == 1) {
    return 1;
  }
  int low = 1;
  int high = n / 2;
  long long int mid = 0;
  long long int square ;
  int result = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;
    square = mid * mid;
    if (square <= n) {
      result = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    cout<<sqroot(n)<<endl;
  }
  return 0;
}
