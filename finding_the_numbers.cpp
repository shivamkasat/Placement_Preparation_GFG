#include <bits/stdc++.h>
using namespace std;

unordered_set < int > findPair(vector < int > &nums) {
  unordered_set < int > hmap;
  for (int i = 0; i < n; i++) {
    if (hmap.find(nums[i]) == hmap.end()) {
      hmap.insert(nums[i]);
    } else {
      hmap.erase(nums[i]);
    }
  }

  return hmap;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    n = 2 * n + 2;
    vector < int > nums(n, 0);
    for (int i = 0; i < nums.size(); i++) {
      cin>>nums[i];
    }

    unordered_set <int > result;
    result = findPair(nums);
    for (auto x : result) {
      cout<<x<<" ";
    }
    cout<<endl;
  }
  return 0;
}
