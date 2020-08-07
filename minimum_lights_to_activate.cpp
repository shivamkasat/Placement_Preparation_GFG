//Main Idea
//start from the first light and try to find most distant light on right side which can be lighten up
// so that we can cover most distance with just one light
// if no such light exist we check the closest light on the left side so that again we can cover
//max distance

int Solution::solve(vector<int> &lights, int b) {
    int n = lights.size();
	vector < int > isIllum(n, 0);
	int i = 0;
	int j = 0;
	int count = 0;
	while (i < n) {
		j = min(i + b - 1, n - 1);
		while (j >= i) {
			if (lights[j] == 1) {
				count++;
				for (int k = max(j - (b - 1), 0); k < n && k <= j + (b - 1); k++) {
					isIllum[k] = 1;
				}
				break;
			}	
			j--;
		}

		if (isIllum[i] == 1) {
			i = j + (b);
			continue;
		}

		j = i - 1;
		while (j >= i - (b - 1)) {
			if (lights[j] == 1) {
				count++;
				for (int k = max(j - (b - 1), 0);k < n && k <= j + (b - 1); k++) {
					isIllum[k] = 1;
				}
				break;
			}
			j--;
		}
		if (isIllum[i] == 1) {
			i = j + b;
		} else {
			count = -1;
			break;
		}

	}
	
	return count;
}
