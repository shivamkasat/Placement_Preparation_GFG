#include <bits/stdc++.h>
using namespace std;

void bfs(int start, int n1, int n2, vector < int > &result) {
  queue < int > q;
  q.push(start);

  int current;
  int lastDigit;
  while (q.empty() != true) {
    current = q.front();
    q.pop();
    if (current > n2) {
      break;
    }

    if (current >= n1 && current <= n2) {
      result.push_back(current);
    }

    lastDigit = current % 10;
    if (lastDigit - 1 >= 0) {
      q.push(current * 10 + lastDigit - 1);
    }

    if (lastDigit + 1 < 10) {
      q.push(current *  10 + lastDigit + 1);
    }

  }

}

vector < int > findAllSteppingNumbers(int n1, int n2) {
  string num1 = to_string(n1);
  string num2 = to_string(n2);
  int first = num1[0] - '0';
  int last = num2[0] - '0';
  vector < int > result;
  for (int i = first; i <= last; i++) {
    bfs(i, n1, n2, result);
  }
  if (n1 == 0) {
    result.push_back(0);
  }
  sort(result.begin(), result.end());
  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n1;
    int n2;
    cin>>n1;
    cin>>n2;
    vector < int > result;
    result = findAllSteppingNumbers(n1, n2);
    for (int i = 0; i < result.size(); i++) {
      cout<<result[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
