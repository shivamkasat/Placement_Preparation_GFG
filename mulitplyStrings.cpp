#include<bits/stdc++.h>
using namespace std;

string multiplyStrings(string , string );

int main() {

    int t;
    cin>>t;
    while(t--)
    {
    	string a;
    	string b;
    	cin>>a>>b;

    	cout<<multiplyStrings(a,b)<<endl;
    }

}


string addNumbers(string s1, string s2) {



  string result;
  if (s1.length() > s2.length()) {
    result = "0" + s1;
  } else {
    result = "0" + s2;
  }

  int i = s1.length() - 1;
  int j = s2.length() - 1;
  int k = result.length() - 1;
  int carry = 0;
  int base = 0;
  while (i >= 0 && j >= 0) {
    base = (s1[i] - '0') + (s2[j] - '0') + carry;
    result[k] = char(base % 10) + '0';
    carry = base / 10;
    k--;
    i--;
    j--;
  }

  while (i >= 0) {
    base = (s1[i] - '0') + carry;
    result[k] = char(base % 10) + '0';
    carry = base / 10;
    k--;
    i--;
  }

  while (j >= 0) {
    base = (s2[j] - '0') + carry;
    result[k] = char(base % 10) + '0';
    carry = base / 10;
    k--;
    j--;
  }

  return result;
}

string calcMulti(string &s1, int num) {
  string result = "0" + s1;
  int carry = 0;
  int base = 0;
  char basech;
  for (int i = s1.length() - 1; i >= 0; i--) {
    base = (s1[i] - '0') * num + carry;
    result[i + 1] = char((base % 10)) + 48;
    carry = base / 10;
  }
  result[0] = char(carry) + 48;
  return result;
}

void fillhmap(vector < int > &track, unordered_map < char, string > &hmap, string &s1) {
  for (int i = 0; i < track.size(); i++) {
    if (track[i] == 1) {
      hmap[char(i) + 48] = calcMulti(s1, i);
    }
  }
}
/*You are required to complete below function */
string multiplyStrings(string s3, string s4) {
    string s1;
    string s2;
    if (s3[0] == '-') {
      s1 = s3.substr(1, s3.length() - 1);
  } else {
      s1 = s3;
  }

  if (s4[0] == '-') {
      s2 = s4.substr(1, s4.length() - 1);
  } else {
      s2 = s4;
  }
    unordered_map < char, string > hmap;
    vector < int > track(10, 0);
    for (int i = 0; i < s2.length(); i++) {
      hmap[s2[i]] = "";
      track[s2[i] - 48] = 1;
    }
    fillhmap(track, hmap, s1);


    string result = hmap[s2[s2.length() - 1]];
    string temp = "";
    string temp2;
    for (int i = s2.length() - 2; i >= 0; i--) {
      temp += "0";
      temp2 = addNumbers(result, hmap[s2[i]] + temp);
      result = temp2;
    }

    int i = 0;
    while (i < result.length() && result[i] == '0') {
        i++;
    }

    if (i == result.length()) {
        result = "0";
    } else {

        result = result.substr(i, result.length() - i);
        if ((s3[0] == '-' && s4[0] != '-') || (s3[0] != '-' && s4[0] == '-')) {
          result = "-" + result;
        }
    }

    return result;

}
