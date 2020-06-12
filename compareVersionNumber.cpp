#include <bits/stdc++.h>
using namespace std;

int compare(string &s1, string &s2) {
  if (s1 == s2) {
    return 0;
  } else if (s1.length() == 0) {
    return -1;
  } else if (s2.length() == 0) {
    return 1;
  }

  int i1 = 0;
  int i2 = 0;
  int n1 = s1.length();
  int n2 = s2.length();
  int j1 = 0;
  int j2 = 0;
  string sub1 = "";
  string sub2 = "";

  while (i1 < n1 && i2 < n2) {
    while (i1 < n1 && s1[i1] == '0' ) {
      i1++;
    }

    while (i2 < n2 && s2[i2] == '0' ) {
      i2++;
    }

    j1 = i1;
    j2 = i2;

    while (j1 < n1 && s1[j1] != '.') {
      j1++;
    }

    while (j2 < n2 && s2[j2] != '.') {
      j2++;
    }



    sub1 = s1.substr(i1, j1 - i1);
    sub2 = s2.substr(i2, j2 - i2);

    cout<<"sub1 = "<<sub1<<" sub2 = "<<sub2<<endl;

    if (sub1 > sub2) {
      return 1;
    } else if (sub2 > sub1) {
      return -1;
    } else {
      if (s1[j1] == '.') {
        j1 += 1;
      }

      if (s2[j2] == '.') {
        j2 += 1;
      }
      i1 = j1;
      i2 = j2;
    }

  }

  while (i1 < n1 && s1[i1] == '0' ) {
    i1++;
  }

  j1 = i1;

  while (j1 < n1 && s1[j1] != '.') {
    j1++;
  }

  // sub1 = s1.substr(i1, j1 - i1);

  while (i2 < n2 && s2[i2] == '0' ) {
    i2++;
  }

  j2 = i2;

  while (j2 < n2 && s2[j2] != '.') {
    j2++;
  }

  // sub2 = s2.substr(i2, j2 - i2);

  if (j1 - i1 > j2 - i2) {
    return 1;
  } else if (j2 - i2 > j1 - i2) {
    return -1;
  } else {
    return 0;
  }



}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s1;
    string s2;
    cin>>s1;
    cin>>s2;
    cout<<compare(s1, s2)<<endl;
  }
  return 0;
}
