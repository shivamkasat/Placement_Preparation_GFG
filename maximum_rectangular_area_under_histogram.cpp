#include <bits/stdc++.h>
using namespace std;

vector < int > findSmallerIndexLeft(vector < int > &heights) {
  vector < int > smallerIndexLeft;
  stack < int > st;
  for (int i = 0; i < heights.size(); i++) {
    while (st.empty() != true && heights[st.top()] >= heights[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      smallerIndexLeft.push_back(-1);
    } else {
      smallerIndexLeft.push_back(st.top());
    }
    st.push(i);
  }
  return smallerIndexLeft;
}


vector < int > findSmallerIndexRight(vector < int > &heights) {
  int n = heights.size();
  vector < int > smallerIndexRight;
  stack < int > st;
  for (int i = n - 1; i >= 0; i--) {
    while (st.empty() != true && heights[st.top()] >= heights[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      smallerIndexRight.push_back(n);
    } else {
      smallerIndexRight.push_back(st.top());
    }
    st.push(i);
  }
  reverse(smallerIndexRight.begin(), smallerIndexRight.end());
  return smallerIndexRight;
}

int maxArea(vector < int > &heights) {
  vector < int > smallerIndexLeft;
  vector < int > smallerIndexRight;
  vector < int > widths(heights.size());
  smallerIndexLeft = findSmallerIndexLeft(heights);
  smallerIndexRight = findSmallerIndexRight(heights);

  cout<<"printing smallerIndexLeft"<<endl;
  for (int i = 0; i < heights.size(); i++) {
    cout<<smallerIndexLeft[i]<<" ";
  }
  cout<<endl;


    cout<<"printing smallerIndexRight"<<endl;
    for (int i = 0; i < heights.size(); i++) {
      cout<<smallerIndexRight[i]<<" ";
    }
    cout<<endl;


  int maxArea = -1;
  for (int i = 0; i < heights.size(); i++) {
    widths[i] = smallerIndexRight[i] - smallerIndexLeft[i] - 1;
    maxArea = max(maxArea, widths[i] * heights[i]);
  }
  return maxArea;

}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > heights;
    int height;
    for (int i = 0; i < n; i++) {
      cin>>height;
      heights.push_back(height);
    }

    cout<<maxArea(heights)<<endl;;

  }
  return 0;
}
