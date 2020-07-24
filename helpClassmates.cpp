vector<int> help_classmate(vector<int> nums, int n)
{
    // find next smaller element to right;
    vector < int > result;
    stack < int > st;
    for (int i = n - 1; i >= 0; i--) {
        while (st.empty() != true && st.top() > nums[i]) {
            st.pop();
        }

        if (st.empty() != true) {
            result.push_back(st.top());
        } else {
            result.push_back(-1);
        }
        st.push(nums[i]);
    }
    reverse(result.begin(), result.end());
    return result;
}
