#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < string > words(n);
    unordered_map < string, string > hmap;
    for (int i = 0; i < n; i++) {
      cin>>words[i];
    }


    string path = "";
    for (auto x : words) {
      path = "";
      for (auto y : x) {
        if (y >= 'A' && y <= 'Z') {
          path.push_back(y);
        }
      }
      if (path != "") {
        hmap[path] = x;
      }
    }

    int inputLength;
    cin>>inputLength;

    string inputString;
    for (int i = 0; i < inputLength; i++) {
      cin>>inputString;
      cout<<hmap[inputString]<<endl;
    }

  }
  return 0;
}
