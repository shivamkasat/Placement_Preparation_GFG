#include <bits/stdc++.h>
using namespace std;

vector < int > findIntersection(vector < int > &nums1, vector < int > &nums2) {
  int i = 0;
  int j = 0;
  int n1 = nums1.size();
  int n2 = nums2.size();

  vector < int > result;

  while (i < n1 && j < n2) {
    if (nums1[i] < nums2[j]) {
      i++;
    } else if (nums2[j] < nums1[i]) {
      j++;
    } else {
      result.push_back(nums1[i]);
      i++;
      j++;
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
    vector < int > nums1;
    int data;
    for (int i = 0; i < n; i++) {
      cin>>data;
      nums1.push_back(data);
    }
    int m;
    cin>>m;
    vector < int > nums2;
    for (int i = 0; i < m; i++) {
      cin>>data;
      nums2.push_back(data);
    }

    vector < int > intersection;
    intersection = findIntersection(nums1, nums2);

    for (int i = 0; i < intersection.size(); i++) {
      cout<<intersection[i]<<" ";
    }
    cout<<endl;
  }
}
