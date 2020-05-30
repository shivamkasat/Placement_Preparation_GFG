#include <bits/stdc++.h>
using namespace std;

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    int freqCounter[61] = {0};
    int num;
    for (int i = 0;i < n; i++) {
      cin>>num;
      freqCounter[num]++;
    }

    map < int, vector < int >, greater < int > > freqToNumber;

    for (int i = 1;i < 61; i++) {
      freqToNumber[freqCounter[i]].push_back(i);
    }

    int freq;
    vector < int > nums;
    map < int, vector < int > > :: iteartor itr = freqToNumber.begin();
    for (; itr != freqToNumber.end(); itr++) {
      nums = itr->second;
      freq = itr->first;
      for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < freq; j++) {
          cout<<nums[i]<<" ";
        }
      }
    }

    cout<<endl;


  }
  return 0;
}
