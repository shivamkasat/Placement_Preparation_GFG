#include <bits/stdc++.h>
using namespace std;

string largestNumber(vector < int > &nums) {
  vector < string > newNums;
  for (int i = 0; i < nums.size(); i++) {
    newNums.push_back(to_String(nums[i]));
  }

  sort(newNums.begin(), newNums.end());

  int swapCount = 0;
  string tempString1 = "";
  string tempString2 = "";

  while (1) {
    swapCount = 0;
    for (int i = 1; i < newNums.size(); i++) {
      tempString1 = newNums[i - 1] + newNums[i];
      tempString2 = newNums[i] + newNums[i - 1];
      if (tempString2 > tempString1) {
        tempString1 = newNums[i];
        newNums[i] = newNums[i - 1];
        newNums[i - 1] = tempString1;
        swapCount++;
      }
    }
    if(swapCount == 0) {
      break;
    }
  }

  tempString1 = "";

  for (int i = 0; i < newNums.size(); i++) {
    tempString1 += newNums[i];
  }

  return tempString1;

}

string largestNumberOptimized(vector < int > &nums) {
  vector < string > newNums;
  bool allZero = true;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != 0) {
      allZero = false;
    }
    newNums.push_back(to_String(nums[i]));
  }

  if (allZero) {
    return "0";
  }

  sort(newNums.begin(), newNums.end());
  string result = newNums[0];
  int current = 1;
  string tempString1 = "";
  string tempString2 = "";
  while (current < newNums.size()) {
    if (result + newNums[current] > newNums[current] + result) {
      result = result + newNums[current];
    } else {
      result = newNums[current] + result;
    }
    current++;
  }

  return result;


}

int main() {
  int test;
  cin<<test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > nums(n, 0);
    for (int i = 0; i < n; i++) {
      cin>>nums[i];
    }
    largestNumber(nums);
  }
  return 0;
}
