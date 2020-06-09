#include <bits/stdc++.h>
using namespace std;

vector < int > findLeaders(vector < int > &arr) {
  int n = arr.size();
  vector < int > result;
result.push_back(arr[n - 1]);
for (int i = n - 2; i >= 0; i--) {
    if (arr[i] < arr[i + 1]) {
        arr[i] = arr[i + 1];
    } else {
        result.push_back(arr[i]);
    }
}

reverse(result.begin(), result.end());
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
    vector < int > leaders;
    leaders = findLeaders(nums);
    for (int i = 0; i < leaders.size(); i++) {
      cout<<leaders[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
