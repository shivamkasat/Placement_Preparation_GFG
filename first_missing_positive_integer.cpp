#include <bits/stdc++.h>
using namespace std;

int findFirstMissingPositive(vector < int > &nums) {
  int i = 0;
        int n = nums.size();
        int j = n - 1;
        int temp = 0;
        while (i < j) {
            while (i < n && nums[i] <= 0) {
                i++;
            }
            while (j > i && nums[j] > 0) {
                j--;
            }

            if (i < j) {
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }

        }


        i = 0;
        while (i < n && nums[i] <= 0) {
            i++;
        }

        for (int j = i; j < n; j++) {
            nums[j] *= -1;
        }


        while (i < n) {
            if (abs(nums[i]) <= n) {
                if (nums[abs(nums[i]) - 1] == 0 || nums[abs(nums[i]) - 1] == INT_MIN) {
                    nums[abs(nums[i]) - 1] = 1;
                } else {
                     nums[abs(nums[i]) - 1] = abs(nums[abs(nums[i]) - 1]);
                }
            }
            i++;
        }

        int result = n + 1;
        i = 0;
        while (i < n) {
            if (nums[i] <= 0) {
                result = i + 1;
                break;
            }
            i++;
        }

        return result;
        
}


int main() {
  int test;
  cin>>test;
  while (test--) {
    int n;
    cin>>n;
    vector < int > nums(n, 0);
    for (int i = 0; i < n; i++) {
      cin>>nums[i];
    }
    cout<<findFirstMissingPositive(nums);
  }
  return 0;
}
