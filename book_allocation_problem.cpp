#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isValid(vector < int > &nums, int students, ll maxPages) {
  ll count = 1;
  ll sum = 0;

  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] > maxPages) {
      return false;
    }

    sum += nums[i];
    if(sum > maxPages) {
      count++;
      sum = nums[i];
    }

  }

  if (count > students) {
    return false;
  } else {
    return true;
  }
}

ll maxPages(vector < int > &nums, int students) {
  ll low = 0;
  ll high = 0;
  ll mid = 0;
  ll result = -1;

  if (nums.size() < students) {
    return -1;
  }

  for (int i = 0; i < nums.size(); i++) {
    high += nums[i];
  }

  while (low <= high) {
    mid = low + (high - low) / 2;

    if (isValid(nums, students, mid)) {
      result = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
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
    int students;
    cin>>students;

    cout<<maxPages(nums, students)<<endl;
  }
  return 0;
}
