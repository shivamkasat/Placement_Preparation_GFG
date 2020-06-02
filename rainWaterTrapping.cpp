#include <bits/stdc++.h>
using namespace std;





int rainWater(vector < int > &bars) {
  int totalWater = 0;
  stack < int > st;
  for (int i = 0; i < bars.size(); i++) {
    while (st.empty() != true && bars[i] > bars[st.top()]) {
      int current = st.top();
      st.pop();
      if (st.empty() != true)
        totalWater += ((min(bars[st.top()], bars[i]) - bars[current]) * (i - st.top() - 1));
    }
    st.push(i);
  }
  return totalWater;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > bars;
    int bar;
    for (int i = 0; i < n; i++) {
      cin>>bar;
      bars.push_back(bar);
    }
    cout<<rainWater(bars)<<endl;
  }
  return 0;
}
