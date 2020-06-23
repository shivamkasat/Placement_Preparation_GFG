#include <bits/stdc++.h>
using namespace std;

bool comp(vector < int > &tmap, vector < int > &smap) {
  for (int i = 0; i < 126; i++) {
    if (tmap[i] != 0) {
      if (tmap[i] > smap[i]) {
        cout<<"returning false as tmap[i] = "<<tmap[i]<<" smap[i] = "<<smap[i]<<endl;
        return false;
      }
    }
  }

  return true;
}

string findMinWindow(string s, string t) {
  vector < int > tmap(126, 0);
  vector < int > smap(126, 0);
  for (int i = 0; i < t.length(); i++) {
    tmap[t[i]]++;
  }

  int i = 0;
  int j = 0;
  int n = s.length();
  int maxLength = n + 1;
  int startIndex = 0;

  while (j < n) {

    if (comp(tmap, smap)) {

      if (j - i < maxLength) {
        maxLength = j - i;
        startIndex = i;
      }

      // cout<<"two maps are equal"<<endl;
      smap[s[i]]--;
      i++;
    } else {
      // cout<<"tow maps are not equal"<<endl;
      smap[s[j]]++;
      j++;
    }

  }

  while (i < n) {
    if (comp(tmap, smap)) {
      if (j - i < maxLength) {
        maxLength = j - i;
        startIndex = i;
      }
    }
    smap[s[i]]--;
    i++;
  }

  string result = "";
  if (maxLength == n + 1) {
    return result;
  }

  result = s.substr(startIndex, maxLength);
  return result;


}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s;
    string t;
    cin>>s;
    cin>>t;
    cout<<findMinWindow(s, t)<<endl;
  }
  return 0;
}
