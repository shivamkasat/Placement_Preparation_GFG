#include <bits/stdc++.h>
using namespace std;

int findMaxSubSum(vector < vector < int > > &grid) {
	int rows = grid.size();
	int cols = grid[0].size();
	int maxSum = INT_MIN;
	int tempSum = INT_MIN;
	int result = INT_MIN;
	vector < int > temp(rows, 0);
	for (int l = 0; l < cols; l++) {
		for (auto &x : temp) {
			x = 0;
		}
		for (int r = l; r < cols; r++) {
			//adding rth col to running row sum
			for (int j = 0; j < rows; j++) {
				temp[j] += grid[j][r];
			}

			//apply kadane here;
			tempSum = temp[0];
			maxSum = tempSum;
			for (int j = 1; j < rows; j++) {
				tempSum = max(tempSum + temp[j], temp[j]);
				maxSum = max(tempSum, maxSum);
			}
		}

		result = max(result, maxSum);
	}

	return result;
}

int main() {
	int rows;
	int cols;
	cin>>rows;
	cin>>cols;
	vector < vector < int > >mat(rows, vector < int >(cols, 0));
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin>>mat[i][j];
		}
	}
	cout<<findMaxSubSum(mat)<<endl;
	return 0;
}