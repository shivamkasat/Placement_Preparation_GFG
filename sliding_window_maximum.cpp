#include <bits/stdc++.h>
using namespace std;


vector < int > findMaxInWindow(vector < int > &nums, int k) {
  deque < int > q;
  vector < int > result;
  int n = nums.size();

  for (int i = 0; i < k; i++) {
    if (q.empty() == true) {
      q.push_back(i);
    } else {
      if (nums[i] >= nums[q.front()]) {
        q.clear();
      } else {
          while (nums[q.back()] < nums[i]) {
            q.pop_back();
          }
      }
      q.push_back(i);
    }
  }

  result.push_back(nums[q.front()]);
  int i = 1;
  int j = k;

  while (j < n) {
    if (q.front() == i - 1) {
      q.pop_front();
    }

    if (nums[j] >= nums[q.front()]) {
      q.clear();
    } else {
      while (nums[q.back()] < nums[j]) {
        q.pop_back();
      }
    }

    q.push_back(j);
    result.push_back(nums[q.front()]);
    j++;
    i++;
  }

  return result;

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

    int k;
    cin>>k;

    vector < int > result;
    result = findMaxInWindow(nums, k);
    for (int i = 0; i < result.size(); i++) {
      cout<<result[i]<<" ";
    }
    cout<<endl;


  }
  return 0;
}
