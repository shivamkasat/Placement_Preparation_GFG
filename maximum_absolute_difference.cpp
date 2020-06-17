#include <bits/stdc++.h>
using namespace std;

int minAbsDiff(vector < int > &nums1, vector < int > &nums2, vector < int > &nums3) {
  int i = 0;
  int j = 0;
  int k = 0;

  int n1 = nums1.size();
  int n2 = nums2.size();
  int n3 = nums3.size();
  int minDiff = INT_MAX;
  int diff = INT_MAX;

  while (i < n1 && j < n2 && k < n3) {
    diff = abs(max(max(nums1[i], nums2[j]), nums3[k]) - min(min(nums1[i], nums2[j]), nums3[k]));
    minDiff = min(diff, minDiff);
    if (nums1[i] < nums2[j]) {
      if (nums1[i] < nums3[k]) {
        i++;
      } else {
        k++;
      }
    } else {
      if (nums2[j] < nums3[k]) {
        j++;
      } else {
        k++;
      }
    }
  }

  return minDiff;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    int data;
    vector < int > nums1;
    for (int i = 0; i < n; i++) {
      cin>>data;
      nums1.push_back(data);
    }

    int n2;
    cin>>n2;
    vector < int > nums2;
    for (int i = 0; i < n2; i++) {
      cin>>data;
      nums2.push_back(data);
    }

    int n3;
    cin>>n3;
    vector < int > nums3;
    for (int i = 0; i < n3; i++) {
      cin>>data;
      nums3.push_back(data);
    }

    cout<<minAbsDiff(nums1, nums2, nums3)<<endl;

  }
  return 0;
}
