#include <bits/stdc++.h>
using namespace std;

int findSolution(vector < int > &nums, int k) {
  int n = nums.size();
  unordered_set < int > hset;
  for (int i = 0; i < n; i++) {
    if (hset.find(k + nums[i]) != hset.end()) {
      return true;
    } else {
      hset.insert(nums[i]);
    }
  }

  return false;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > nums;
    int num;
    for (int i = 0; i < n; i++) {
      cin>>num;
      nums.push_back(num);
    }
    int k;
    cin>>k;

    cout<<findSolution(nums, k)<<endl;
  }
  return 0;
}
