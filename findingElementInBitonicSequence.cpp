#include <bits/stdc++.h>
using namespace std;

int findNumberIndex(vector < int > nums, int item) {
  if ()
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > nums(n, 0);
    for (int i = 0; i < n; i++) {
      cin>>nums[i];
    }

    int item;
    cin>>item;

    cout<<findNumberIndex(nums, item);
  }
  return 0;
}
