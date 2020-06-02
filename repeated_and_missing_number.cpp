#include <bits/stdc++.h>
using namespace std;

vector < int > repeatedNumber(vector < int > &nums) {
  vector < int > result(2, 0);
  long long s1 = 0, s2 = 0, s3 = 0, s4 = 0;
  long long sq = 0;
  long long N = nums.size();
  // s1 = sum of all the nubmers;
  // s2 = sum of all the squares
  // s3 = sum of all the given numbers
  // s4 = sum of square of all the given numbers;
  for (int i = 0; i < N; i++) {
    s3 += nums[i];
    sq = ((long long int)(nums[i]) * nums[i]);
    s4 += sq;
  }

  cout<<"S3 = "<<s3<<endl;
  cout<<"S4 = "<<s4<<endl;

  s1 =( N * (N + 1)) / 2;
  s2 = (N * (N + 1) * (2 * N + 1)) / 6;
  long long P = s1 - s3;
  long long Q = s2 - s4;
  long long R = Q / P;
  long long X = (P + R) / 2;
  long long Y = R - X;
  result[0] = Y;
  result[1] = X;
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
    vector < int > result;
    result = repeatedNumber(nums);
    for (int i = 0; i < result.size(); i++) {
      cout<<result[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
