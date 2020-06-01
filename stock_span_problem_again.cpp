#include <bits/stdc++.h>
using namespace std;

vector < int > findSpan(vector < int > &prices) {
  stack < int > st;
  vector < int > spans;
  for (int i = 0; i < prices.size(); i++) {
    while(st.empty() != true && prices[st.top()] <= prices[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      spans.push_back(i + 1);
    } else {
      spans.push_back(i - st.top());
    }
    st.push(i);
  }

  return spans;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > prices;
    int price;
    for (int i = 0; i < n; i++) {
      cin>>price;
      prices.push_back(price);
    }

    vector < int > spans;
    spans = findSpan(prices);
    for (int i = 0; i < spans.size(); i++) {
      cout<<spans[i]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
