#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  vector < string > words(n);
  unordered_map < string, string > hmap;
  for (int i = 0; i < n; i++) {
    cin>>words[i];
  }

  string path = "";
  for (int i = 0; i < words.size(); i++) {
    path = "";
    for (int j = 0; j < words[i].size(); j++) {
      if (words[i][j] >= 'A' && words[i][j] <= 'Z') {
        path.push_back(words[i][j]);
      }
    }

    if (path != "") {
      hmap[path] = words[i]
    }
  }


  int inputs;
  cin>>inputs;
  for (int i = 0; i < inputs; i++) {
    cin>>inputString;
    cout<<hmap[inputString];
  }
}
