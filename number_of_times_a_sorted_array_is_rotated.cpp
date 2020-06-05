#include <bits/stdc++.h>
#define ll long long
using namespace std;

int findRotationCount(vector < ll > &nums) {
  // find the index of the smallest element => decided by comparing with the left and right element
  int n = nums.size();
  int low = 0;
  int high = n - 1;
  int ans = -1;
  int mid = 0;
  while (low <= high) {
    mid = low + (high - low) / 2;

    // if (low == high) {
    //   cout<<"first if"<<endl;
    //   ans = mid;
    //   break;
    // } else if (nums[mid] < nums[mid + 1] && nums[mid] < nums[mid - 1]) {
    //   cout<<"second if"<<endl;
    //   ans = mid;
    //   break;
    // }

    if (nums[(mid + 1) % n] > nums[mid] && nums[(mid + n - 1) % n] > nums[mid]) {
      cout<<"first if"<<endl;
      ans = mid;
      break;
    } else if (nums[mid] > nums[high]) {
      cout<<"third if"<<endl;
      low = mid + 1;
    } else {
      cout<<"fourth else"<<endl;
      high = mid - 1;
    }

  }
  return ans;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < ll > nums;
    ll num;
    for (int i = 0; i < n; i++) {
      cin>>num;
      nums.push_back(num);
    }

    cout<<findRotationCount(nums)<<endl;

  }
  return 0;
}
