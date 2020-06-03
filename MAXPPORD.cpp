#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;


vector < int > findNextGreaterIndexRight(vector < int > &nums) {
  vector < int > result;
  stack < int > st;
  int n = nums.size();

  for (int i = n - 1; i >= 0; i--) {
    while (st.empty() != true && nums[st.top()] <= nums[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      result.push_back(0);
    } else {
      result.push_back(st.top());
    }
    st.push(i);
  }
  reverse(result.begin(), result.end());
  return result;
}

vector < int > findNextGreaterIndexLeft(vector < int > &nums) {
  vector < int > result;
  stack < int > st;
  int n = nums.size();

  for (int i = 0; i < n; i++) {
    while (st.empty() != true && nums[st.top()] <= nums[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      result.push_back(0);
    } else {
      result.push_back(st.top());
    }

    st.push(i);
  }

  return result;

}


int maxProd(vector < int > &nums) {
  int n = nums.size();
  vector < int > leftMax;
  vector < int > rightMax;

  leftMax = findNextGreaterIndexLeft(nums);
  rightMax = findNextGreaterIndexRight(nums);
  long long int maxProduct = INT_MIN;


  for (int i = 0; i < nums.size(); i++) {
    nums[i] = (leftMax[i] * rightMax[i]) % mod;
    maxProduct = max(maxProduct, nums[i]);
  }

  return maxProduct % mod;

}

int main () {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > nums(n, 0);
    for (int i = 0; i < n; i++) {
      cin>>nums[i];
    }

    cout<<maxProd(nums)<<endl;
  }
  return 0;
}
