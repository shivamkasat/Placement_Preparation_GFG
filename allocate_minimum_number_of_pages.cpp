#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector < int > &nums, int studs, int maxPages) {
  int count = 1;
  int n = nums.size();
  int i = 0;
  int j = 0;
  int sum = 0;

  for (int i = 0; i < n; i++) {
    if (nums[i] > maxPages) {
      return false;
    }

    sum += nums[i];
    if (sum > maxPages) {
      sum = nums[i];
      count++;
    }

    if (count > studs) {
      return false;
    }
  }

  cout<<"maxPages = "<<maxPages<<" count = "<<count<<endl;



  return true;

}

int minPages(vector < int > &nums, int studs) {

  if (studs > nums.size()) {
    return -1;
  }

  int n = nums.size();
  int low = 0;
  int high = 0;
  for (int i = n - 1; i >= 0; i--) {
    high += nums[i];
  }
  int mid = 0;
  int result = -1  ;

  cout<<"low = "<<low<<" high = "<<high<<endl;

  while (low <= high) {
    mid = low + (high - low) / 2;
    if (isPossible(nums, studs, mid)) {
      result = mid;
      high = mid - 1;;
    } else {
      low = mid + 1;;
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
    vector < int > nums(n, 0);
    for (int i = 0; i < n; i++) {
      cin>>nums[i];
    }

    int studs;
    cin>>studs;

    cout<<minPages(nums, studs)<<endl;

  }
}
