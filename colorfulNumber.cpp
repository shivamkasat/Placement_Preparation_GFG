#include <bits/stdc++.h>
using namespace std;

bool isColourful(int num) {
  string number = to_string(num);
  int n =  number.size();
  unordered_set < long long int > hmap;
  long long int prod = 1;
  for (int i = 0; i < n; i++) {
    prod = 1;
    for (int j = i ; j < n; j++) {
      prod = prod * (number[i] - '0');
      if (hmap.find(prod) != hmap.end()) {
        return false;
      } else {
        hmap.insert(prod);
      }
    }
  }

  return true;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    // vector < int > nums(n, 0);
    // for (int i = 0; i < n; i++) {
    //   cin>>nums[i];
    // }

    cout<<isColourful(n)<<endl;
  }
}
