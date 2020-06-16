#include <bits/stdc++.h>
using namespace std;

int findSolution(vector < int > &nums) {

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
    cout<<findSolution(nums)<<endl;
  }
  return 0;
}
