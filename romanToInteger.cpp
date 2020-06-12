#include <bits/stdc++.h>
using namespace std;

int toInteger(string s) {
  unordered_map < char, int > hmap;
  hmap['I'] = 1;
  hmap['V'] = 5;
  hmap['X'] = 10;
  hmap['L'] = 50;
  hmap['C'] = 100;
  hmap['D'] = 500;
  hmap['M'] = 1000;

  int i = 0;
  int num = 0;
  while (i < n) {
    if (i + 1 < n && hmap[s[i + 1]] > hmap[s[i]] {
      num += (hmap[s[i + 1]] - hmap[s[i]]);
      i+=2;
    } else {
      num += (hmap[s[i]]);
      i++;
    }
  }

  return num;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s;
    cin>>s;
    cout<<toInteger(s)<<endl;
  }
  return 0;
}
