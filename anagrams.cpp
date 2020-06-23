#include <bits/stdc++.h>
using namespace std;

vector < vector < int > > findAnagrams(vector < string > &strs) {
  unordered_map < string , vector < int > > hmap;
  for (int i = 0; i < strs.size(); i++) {
    sort(strs[i].begin(), strs[i].end())
    hmap[strs[i]].push_back(i);
  }

  vector < vector < int > > resutl;
  for (auto itr = hmap.begin(); itr != hmap.end(); itr++) {
    result.push_back(itr->second);
  }
  return result;
}


int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    string s;
    vector < string > strs;
    for (int i = 0; i < n; i++) {
      cin>>s;
      strs.push_back(s);
    }

    vector < vector < int > > result;
    result = findAnagrams(strs);
    for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < result[i].size(); j++) {
        cout<<result[i][j]<<" ";
      }
      cout<<endl;
    }

  }
  return 0;
}
