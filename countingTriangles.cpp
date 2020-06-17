#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;


int findTriangleCount(vector < int > &nums) {
  ll count = 0;
  int n = nums.size();
  int j = 0;
  int k = 0;
  sort(nums.begin(), nums.end());
  for (int i = n - 1; i > 1; i--) {
    j = 0;
    k = i - 1;

    while (j < k) {
      if (nums[j] + nums[k] > nums[i]) {
        count += (k - j);
        k--;
      } else {
        j++;
      }

    }

  }

  return count % mod;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    int num;
    vector < int > nums;
    for (int i = 0; i < n; i++) {
      cin>>num;
      nums.push_back(num);
    }
    cout<<findTriangleCount(nums)<<endl;
  }
  return 0;
}
