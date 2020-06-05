#include <bits/stdc++.h>
using namespace std;

vector < int > findNextSmallerIndex(vector < int > &nums) {
  vector < int > nextSmaller;
  stack < int > st;
  int n = nums.size();
  for (int i = n - 1; i >= 0; i--) {
    while (st.empty() != true && nums[st.top()] >= nums[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      nextSmaller.push_back(-1);
    } else {
      nextSmaller.push_back(st.top());
    }

    st.push(i);
  }

  reverse(nextSmaller.begin(), nextSmaller.end());
  return nextSmaller;
}

vector < int > findNextGreaterIndex(vector < int > &nums) {
  // vector < int > nextSmallerIndex = findNextSmallerIndex(nums);
  stack < int > st;
  vector < int > nextGreater;
  int n = nums.size();
  for (int i = n - 1; i >= 0; i--) {
    while (st.empty() != true && nums[st.top()] <= nums[i]) {
      st.pop();
    }

    if (st.empty() == true) {
      nextGreater.push_back(-1);
    } else {
      nextGreater.push_back(st.top());
    }

    st.push(i);
  }

  reverse(nextGreater.begin(), nextGreater.end());
  return nextGreater;

}

vector < int > findSolution(vector < int > &nums) {
  int n = nums.size();
  vector < int > nextSmallerIndex;
  vector < int > nextGreaterIndex;
  nextSmallerIndex = findNextSmallerIndex(nums);
  nextGreaterIndex = findNextGreaterIndex(nums);

  // cout<<"printing next smaller"<<endl;
  // for (int i = 0; i < n; i++) {
  //   cout<<nextSmallerIndex[i]<<" ";
  // }
  // cout<<endl;
  //
  // cout<<"printing next greater"<<endl;
  // for (int i = 0; i < n; i++) {
  //   cout<<nextGreaterIndex[i]<<" ";
  // }
  // cout<<endl;


  vector < int > result;
  // int nextSmall;
  // int nextGreat;
  for (int i = 0; i < nums.size(); i++) {
    if (nextSmallerIndex[i] != -1) {
      if (nextGreaterIndex[nextSmallerIndex[i]] != -1) {
        result.push_back(nums[nextGreaterIndex[nextSmallerIndex[i]]]);
      } else {
        result.push_back(-1);
      }
    } else {
      result.push_back(-1);
    }

    // result.push_back(nums[nextGreaterIndex[nextSmallerIndex[i]]]);
  }
  return result;
}

int main() {
  int n;
  cin>>n;
  vector < int > nums;
  int num;
  for (int i = 0; i < n; i++) {
    cin>>num;
    nums.push_back(num);
  }

  vector < int > result;
  result = findSolution(nums);
  for (int i = 0; i < result.size(); i++) {
    cout<<result[i]<<" ";
  }
  cout<<endl;

  return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
//
// vector < int > findNextSmallerIndex(vector < int > &nums) {
// 	vector < int > nextSmaller;
// 	stack < int > st;
// 	int n = nums.size();
// 	for (int i = n - 1; i >= 0; i--) {
// 		while (st.empty() != true && nums[st.top()] >= nums[i]) {
// 			st.pop();
// 		}
//
// 		if (st.empty() == true) {
// 			nextSmaller.push_back(-1);
// 		} else {
// 			nextSmaller.push_back(i);
// 		}
//
// 		st.push(i);
// 	}
//
// 	reverse(nextSmaller.begin(), nextSmaller.end());
// 	return nextSmaller;
// }
//
// vector < int > findNextGreaterIndex(vector < int > &nums) {
// 	int n = nums.size();
// 	vector < int > nextGreater;
// 	stack < int > st;
//
// 	for (int i = n - 1; i >= 0; i--) {
// 		while (st.empty() != true && nums[st.top()] <= nums[i]) {
// 			st.pop();
// 		}
//
// 		if (st.empty()) {
// 			nextGreater.push_back(-1);
// 		} else {
// 			nextGreater.push_back(i);
// 		}
//
// 		st.push(i);
// 	}
//   reverse(nextGreater.begin(), nextGreater.end());
// 	return nextGreater;
// }
//
// vector < int > findSolution(vector < int > &nums) {
// 	vector < int > nextSmallerIndex = findNextSmallerIndex(nums);
// 	vector < int > nextGreaterIndex = findNextGreaterIndex(nums);
// 	vector < int > result;
//
// 	cout<<"printing next smaller index"<<endl;
// 	for (int i = 0; i < nums.size(); i++) {
// 		cout<<nextSmallerIndex[i]<<" ";
// 	}
// 	cout<<endl;
//
// 	cout<<"printing next greater index"<<endl;
//
// 	for (int i = 0; i < nums.size(); i++) {
// 		cout<<nextGreaterIndex[i]<<" ";
// 	}
// 	cout<<endl;
//
// 	for (int i = 0; i < nums.size(); i++) {
// 		if (nextSmallerIndex[i] != -1) {
// 			if (nextGreaterIndex[nextSmallerIndex[i]] != -1) {
// 				result.push_back(nums[nextGreaterIndex[nextSmallerIndex[i]]]);
// 			} else {
// 				result.push_back(-1);
// 			}
// 		} else {
// 			result.push_back(-1);
// 		}
// 	}
//
// 	return result;
//
// }
//
// int main() {
// 	int n;
// 	cin>>n;
// 	vector < int > nums;
// 	int num;
// 	for (int i = 0; i < n; i++) {
// 		cin>>num;
// 		nums.push_back(num);
// 	}
//
// 	vector < int > result;
// 	result = findSolution(nums);
// 	for (int i = 0; i < result.size(); i++) {
// 		cout<<result[i]<<" ";
// 	}
// 	cout<<endl;
// 	return 0;
// }
