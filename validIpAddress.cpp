#include <bits/stdc++.h>
using namespace std;

bool isValid(string ip) {
  int n = ip.length();
  int i = 0;
  int j = 0;
  while (i < n) {
    int j = i;
    int num = 0;
    while (j < n && ip[j] != '.') {
      num = num * 10 + (ip[j] - '0');
      j++;
    }

    if (num < 0 || num > 255) {
      return false;
    } else if (ip[i] == '0' && j - i != 1) {
      return false;
    }

    i= j + 1;

  }
  return true;

}

void findIps(string &s, vector < string > &allIps, string ip, int dots, int index) {
  // cout<<"s = "<<s<<" ip = "<<ip<<" dots = "<<dots<<" index = "<<index<<endl;

  if (dots == 0) {
    ip += s.substr(index, s.length() - index + 1);
    cout<<ip<<endl;
    // if (index == s.length()) {
    if (isValid(ip)) {
      allIps.push_back(ip);
    }
    // }
    // cout<<"returing as dots == 0"<<endl;
    return;
  }


  string tempip = "";
  int l = 1;
  while (l <= 3 && index + l < s.length()) {
    tempip = ip;
    tempip += s.substr(index, l);
    tempip += ".";
    findIps(s, allIps, tempip, dots - 1, index + l);
    l++;
  }

}

vector < string > findAllIps(string &s) {
  vector < string > allIps;
  string ip = "";
  int dots = 3;
  int index = 0;
  findIps(s, allIps, ip, dots, index);
  return allIps;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string ip;
    cin>>ip;
    vector < string > validIps;
    validIps = findAllIps(ip);
    cout<<"printing valid ip"<<endl;
    for (int i = 0; i < validIps.size(); i++) {
      cout<<validIps[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
