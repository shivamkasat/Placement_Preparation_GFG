#include <bits/stdc++.h>
#define prime 101
#define ll long long int
using namespace std;


ll calcHash(ll oldHash, char newChar, char oldChar, int patternLength) {
  cout<<"newChar = "<<newChar<<" old char = "<<oldChar<<endl;
  oldHash = oldHash - (oldChar - 'a');
  oldHash = oldHash / prime;
  oldHash = oldHash + ((newChar - 'a') * pow(prime, patternLength - 1));
  return oldHash;
}

ll calcInitialHash(string str, int initial, int end) {
  int hashValue = 0;
  for (int i = initial; i < end; i++) {
    hashValue = hashValue + (str[i] - 'a') * pow(prime, i);
  }
  return hashValue;
}

bool matchStrings(string s, string p, int initial) {
  for (int i = 0, j = initial; i < p.length(); i++, j++) {
    if (s[j] != p[i]) {
      return false;
    }
  }
  return true;
}

int indexOfFirstMatch(string s, string p) {
  int stringLength = s.length();
  int patternLength = p.length();
  ll patternHash = 0;
  ll oldHash = 0;
  ll newHash = 0;

  patternHash = calcInitialHash(p, 0, patternLength);
  oldHash = calcInitialHash(s, 0, patternLength);

  if (patternHash == oldHash && matchStrings(s,p,0)) {
    return 0;
  }

  int j = patternLength;
  int i = 1;
  while (j < stringLength) {
    newHash = calcHash(oldHash, s[j], s[i - 1], patternLength);
    cout<<"newHash = "<<newHash<<" patternHash = "<<patternHash<<endl;
    if (newHash == patternHash && matchStrings(s, p, i)) {
      return i;
    }
    oldHash = newHash;
    i++;
    j++;
  }
  return -1;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    string s;
    cin>>s;
    string p;
    cin>>p;
    cout<<indexOfFirstMatch(s, p)<<endl;
  }
  return 0;
}
