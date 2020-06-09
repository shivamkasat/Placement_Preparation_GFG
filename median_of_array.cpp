#include <bits/stdc++.h>
using namespace std;

int findK(vector < int > &nums1, vector < int > &nums2, int low, int high, int required) {
    int mid = 0;
    int count = 0;
    while (low < high) {
      mid = low + (high - low) / 2;
      count = 0;
      count += (upper_bound(nums1.begin(), nums1.end(), mid) - nums1.begin());
      count += (upper_bound(nums2.begin(), nums2.end(), mid) - nums2.begin());

      if (count < required) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    return low;
}

float median(vector < int > &nums1, vector < int > &nums2) {
  int n = nums1.size();
  int m = nums2.size();
  int low1 = n > 0 ? nums1[0] : INT_MAX;
  int low2 = m > 0 ? nums2[0] : INT_MAX;
  int low = min(low1, low2);
  int high1 = n > 0 ? nums1[n - 1] : INT_MIN;
  int high2 = m > 0 ? nums2[m - 1] : INT_MIN;
  int high = max(high1, high2);
  int mid = 0;
  int count = 0;
  int required = (n + m) / 2 + 1;

  float med1 = findK(nums1, nums2, low, high, required);
  float med2 = 0;
  if ((m + n) % 2 == 0) {
    med2 = findK(nums1, nums2, low, high, required - 1);
    return (med1 + med2 )/ 2;
  }

  return med1;


}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n1;
    cin>>n1;
    vector < int > nums1(n1, 0);
    for (int i = 0; i < n1; i++) {
      cin>>nums1[i];
    }
    int n2;
    cin>>n2;
    vector < int > nums2(n2, 0);
    for (int i = 0; i < n2; i++) {
      cin>>nums2[i];
    }

    cout<<median(nums1, nums2)<<endl;

  }
  return 0;
}
