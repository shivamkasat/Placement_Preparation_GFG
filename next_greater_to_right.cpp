#include <bits/stdc++.h>
using namespace std;

vector < int > findNextGreaterToRight(vector < int > &nums) {
  vector < int > result;
  stack < int > st;
  for (int i = nums.size() - 1; i >= 0; i--) {
    while (st.empty() != true && st.top() <= nums[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      result.push_back(-1);
    } else {
      result.push_back(st.top());
    }
    st.push(nums[i]);
  }
  reverse(result.begin(), result.end());
  return result;
}

vector < int > findNextGreaterToLeft(vector < int > &nums) {
  vector < int > result;
  stack < int > st;
  for (int i = 0; i < nums.size(); i++) {
    while (st.empty() != true && st.top() <= nums[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      result.push_back(-1);
    } else {
      result.push_back(st.top());
    }

    st.push(nums[i]);
  }
  return result;
}

vector < int > findNextSmallerToRight(vector < int > &nums) {
  vector < int > result;
  stack < int > st;
  for (int i = nums.size() - 1; i >= 0; i--) {
    while (st.empty() != true && st.top() >= nums[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      result.push_back(-1);
    } else {
      result.push_back(st.top());
    }
    st.push(nums[i]);
  }

  reverse(result.begin(), result.end());
  return result;
}

vector < int > findNextSmallerToLeft(vector < int > &nums) {
  vector < int > result;
  stack < int > st;
  for (int i = 0; i < nums.size(); i++) {
    while (st.empty() != true && st.top() >= nums[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      result.push_back(-1);
    } else {
      result.push_back(st.top());
    }

    st.push(nums[i]);
  }
  return result;
}

int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > nums;
    int num;
    for (int i = 0; i < n; i++) {
      cin>>num;
      nums.push_back(num);
    }

    vector < int > greaterRight;
    greaterRight = findNextGreaterToRight(nums);
    for (int i = 0; i < greaterRight.size(); i++) {
      cout<<greaterRight[i]<<" ";
    }
    cout<<endl;

    vector < int > greaterLeft;
    greaterLeft = findNextGreaterToLeft(nums);
    for (int i = 0; i < greaterLeft.size(); i++) {
      cout<<greaterLeft[i]<<" ";
    }
    cout<<endl;


    vector < int > smallerRight;
    smallerRight = findNextSmallerToRight(nums);
    for (int i = 0; i < smallerRight.size(); i++) {
      cout<<smallerRight[i]<<" ";
    }
    cout<<endl;


    vector < int > smallerLeft;
    smallerLeft = findNextSmallerToLeft(nums);
    for (int i = 0; i < smallerLeft.size(); i++) {
      cout<<smallerLeft[i]<<" ";
    }
    cout<<endl;

  }
  return 0;
}
