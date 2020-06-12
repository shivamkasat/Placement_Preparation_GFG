#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int modular_exp(long long int a, long long int b) {
  if (a == 0) {
    return 0;
  } else if (b == 0) {
    return 1;
  } else if (b % 2 == 0) {
    return ((modular_exp(a, b / 2) % mod) * (modular_exp(a, b / 2) % mod)) % mod;
  } else {
    return ((modular_exp(a, b - 1) % mod) * (a % mod)) % mod;
  }
}

int modular_inverse(long long int b) {
  return (modular_exp(b, mod - 2) % mod);
}

int findLCM(int n1, int n2) {
  return ((n1 % mod) * (n2 % mod) * (__gcd(n1, n2) % mod)  ) % mod;
}

string rotate(string &s, int k) {
  int n = s.length();
  k = k % n;
  string s1 = s;
  // cout<<s1<<endl;
  reverse(s1.begin(), s1.begin() + k);
  // cout<<s1<<endl;
  reverse(s1.begin() + k, s1.end());
  // cout<<s1<<endl;
  reverse(s1.begin(), s1.end());
  // cout<<s1<<endl;
  return s1;
}

int magicNumber(vector < string > &strs) {

  int n = strs.size();
  // cout<<"printing string"<<endl;
  // for (int i = 0; i < n; i++) {
  //   cout<<strs[i]<<" ";
  // }
  // cout<<endl;

  vector < long long int > counter(n, 0);
  long long int count = 1;
  string current = "";
  for (int i = 0; i < n; i++) {
    count = 1;
    current = strs[i];
    while (strs[i] != rotate(current, count)) {
      // cout<<"rotating"<<strs[i]<<endl;
      current = rotate(current, count);
      count++;
      // cout<<"rotating "<<strs[i]<<"current rotation = "<<current<<endl;
    }
    cout<<"rotations requried "<<strs[i] <<" = "<<count<<endl;

    counter[i] = count;
  }

  long long int lcm = 1;

  for (int i = 0; i < n; i++) {
    lcm = findLCM(lcm, counter[i]);
  }

  // cout<<"calculated LCM = "<<lcm<<endl;

  return lcm;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < string > strs;
    string s1;
    for (int i = 0; i < n; i++) {
      cin>>s1;
      strs.push_back(s1);
    }

    cout<<magicNumber(strs)<<endl;
  }
  // string s1 = "aabb";
  // cout<<rotate(s1, 3)<<endl;
  return 0;
}
