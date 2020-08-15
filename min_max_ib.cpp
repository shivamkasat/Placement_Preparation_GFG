int findMinMaxSum(vector < int > &nums) {
	int n = nums.size();
	int min = nums[0];
	int max = nums[0];
	for (int i = 1; i < n; i++) {
		if (nums[i] < min) {
			min = nums[i];
		} else if (nums[i] > max) {
			max = nums[i];
		}
	}

	return min + max;
}