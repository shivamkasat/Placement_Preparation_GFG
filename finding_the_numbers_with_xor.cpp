#include <bits/stdc++.h>
using namespace std;

pair < int, int > findPair(vector < int > &nums) {
  int x = 0;
  int y = 0;
  int n = nums.size();
  int xorAll = 0;
  for (int i = 0; i < n; i++) {
    xorAll = xorAll ^ nums[i];
  }

  int rightMostSet = xorAll & ~(xorAll - 1);

  for (int i = 0; i < n; i++) {
    if (rightMostSet & nums[i]) {
      x = x ^ nums[i];
    } else {
      y = y ^ nums[i];
    }
  }

  pair <int, int > result;

  if (x < y) {
    result.first = x;
    result.second = y;
  } else {
    result.first = y;
    result.second = x;
  }

  return result;

}


int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    n = 2 * n + 2;
    vector < int > nums(n, 0);
    for (int i = 0; i < nums.size(); i++) {
      cin>>nums[i];
    }

    pair < int , int > result;
    result = findPair(nums);
    cout<<result.first<<" "<<result.second;
    cout<<endl;
  }
  return 0;
}
