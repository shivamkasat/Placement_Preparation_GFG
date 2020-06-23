#include <bits/stdc++.h>
using namespace std;

vector < int > findSolution(vector < int > &nums) {
  int n = nums.size();
  vector < int > preSum(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    preSum[i] = preSum[i - 1] + nums[i - 1];
  }

  unordered_map < int, pair < int, int > > hmap;
  int maxLength = 0;
  int maxKey = preSum[0];

  for (int i = 0; i <= n; i++) {
    if (hmap.find(preSum[i]) != hmap.end()) {
      hmap[preSum[i]].second = i;
      if (maxLength < (hmap[preSum[i]].second - hmap[preSum[i]].first )) {
        maxLength = hmap[preSum[i]].second - hmap[preSum[i]].first;
        maxKey = preSum[i];
      }
    } else {
      hmap[preSum[i]] = {i, i + 1};
    }
  }

    // for (auto x : hmap) {
    //     cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<endl;
    // }
    // cout<<endl;

  vector < int > result;
    if (maxLength == 0) {
        return result;
    }

  for (int i = hmap[maxKey].first; i < hmap[maxKey].second; i++) {
    result.push_back(nums[i]);
    // cout<<nums[i]<<" ";
  }
//   cout<<endl;

  return result;
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

    vector < int > result;
    result = findSolution(nums);

    for (int i = 0; i < result.size(); i++) {
        cout<<result[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
