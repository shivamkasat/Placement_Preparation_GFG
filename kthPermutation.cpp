#include <bits/stdc++.h>
using namespace std;

//reference leetcode - permutation sequence

string findKthPermutation(int n, int k) {
  vector < int > fact(10, 1);
  for (int i = 1; i < 10; i++) {
    fact[i] = i * fact[i - 1];
  }

  string result = "";
  vector < char > nums;
  for (int i = 1; i <= n; i++) {
    nums.push_back(char(i) + '0');
  }

  k = k - 1;
  int index = 0;

  for (int i = 1; i <= n; i++) {
    index = k / fact[n - i];
    result.push_back(nums[index]);
    nums.erase(nums.begin() + index);
    k = k - (index * fact[n - i]);
  }

  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    int k;
    cin>>k;
    cout<<findKthPermutation(n, k)<<endl;
  }
  return 0;
}
