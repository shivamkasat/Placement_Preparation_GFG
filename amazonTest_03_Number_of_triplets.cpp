#include <bits/stdc++.h>
using namespace std;

int findTriplets(vector < int > &nums) {
  vector < int > smallerCount;
  int n = nums.size();
  int count = 0;
  for (int i = 0; i < n; i++) {
    count = 0;
    for (int j = i + 1; j < n; j++) {
      if (nums[j] < nums[i]) {
        count++;
      }
    }
    smallerCount.push_back(count);
  }

  // for (int i = 0; i < n; i++) {
  //   cout<<smallerCount[i]<<" ";
  // }
  // cout<<endl;

  int resultCount = 0;

  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      if (nums[j] > nums[i]) {
        resultCount += smallerCount[j];
      }
    }
  }

  return resultCount;

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
    cout<<findTriplets(nums)<<endl;
  }
  return 0;
}
