#include <bits/stdc++.h>
using namespace std;

string findSmallestMulti(int n) {
  if (n == 1) {
    return "1";
  }

  vector < bool > visited(n, false);

  queue < pair < int, string > > q;
  q.push({1, "1"});
  visited[1] = true;
  pair < int , string > current;
  int rem = 0;
  while (q.empty() != true) {
    current = q.front();
    q.pop();
    rem = current.first;
    if (rem == 0){
      return current.second;
    }
    if (visited[(rem * 10) % n] == false) {
      visited[(rem * 10) % n] = true;
      q.push({(rem * 10) % n, current.second + "0"});
    }

    if (visited[(rem * 10 + 1) % n] == false) {
      visited[((rem * 10) + 1) % n] = true;
      q.push({((rem * 10 + 1) % n), current.second + "1"});
    }
  }
  return "WRONG";inter
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    cout<<findSmallestMulti(n)<<endl;
  }
  return 0;
}
