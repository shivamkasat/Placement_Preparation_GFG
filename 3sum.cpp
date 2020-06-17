#include <bits/stdc++.h>
using namespace std;

int closestSum(vector < int > &nums, int target) {
  int n = nums.size();
  int sum = INT_MAX;
  int minDiff = INT_MAX;
  int result = INT_MAX;
  sort(nums.begin(), nums.end());

  for (int i = 0; i < n; i++) {
    int j = i + 1;
    int k = n - 1;
    while (j < k) {
      sum = (nums[i] + nums[j] + nums[k]);
      if ( minDiff > abs(target - sum)) {
        result = sum;
        minDiff = abs(target - result);
      }

      if (target == sum) {
        return result;
      } else if (target < sum) {
        k--;
      } else {
        j++;
      }

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
    int data;
    vector < int > nums;
    for (int i = 0; i < n; i++) {
      cin>>data;
      nums.push_back(data);
    }

    int target;
    cin>>target;

    cout<<closestSum(nums, target)<<endl;
  }
}
